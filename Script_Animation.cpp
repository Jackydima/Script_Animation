#include "Script_Animation.h"

#include "util/Memory.h"
#include "util/Logging.h"
#include "util/Hook.h"
#include <iostream>
#include "Script.h"


gSScriptInit & GetScriptInit()
{
    static gSScriptInit s_ScriptInit;
    return s_ScriptInit;
}
/**
* p_Str1 was Hit on regular Attack , p_Str2 was Fwd on regular Attack
*/
void GE_STDCALL GetAniName ( bCString& p_RetString, eCEntity* p_Entity, gEAction p_Action, bCString p_Str1, bCString& p_Str2, GEBool p_Bool) {
    p_RetString.Clear ( );
    
    if ( p_Entity == nullptr )
        return;
    Entity actorEntity = Entity ( p_Entity );
    //std::cout << "Name: " << actorEntity.GetName ( ) << "\n";
    eCVisualAnimation_PS* vA = ( eCVisualAnimation_PS*) actorEntity.Animation.m_pEngineEntityPropertySet;
    // eCVisualAnimation_PS* vA = (eCVisualAnimation_PS *) p_Entity->GetPropertySet ( eEPropertySetType_Animation );
    if ( vA == nullptr )
        return;
    auto actor = vA->GetActor ( );
    if ( !actor->IsValid ( ) )
        return;
    bCString actorName = actor->GetActorName ( );
    //std::cout << "Actor: " << actorName << "\n";
    // Here the destination p_RetString gets the Actor Name used for animation (removed G3_) in der Beginning mostly
    // Example: G3_Hero_ ... -> Hero
    GEInt indexWord = actorName.GetWord ( 1 , "_" , p_RetString , GEFalse , GEFalse );
    p_RetString += "_";
    //std::cout << "RetString: " << p_RetString << "\n";
    // TODO: Make Custom String return vals here PropertySetType
    // Used the Property of Routine * (int*)( actorEntity.Routine + 0x40 ) 
    if ( !actorEntity.Routine.IsValid ( ) )
        return;
    p_RetString += *( bCString* )(RVA_Game(0x3f78e0) + static_cast< GEInt >( actorEntity.Routine.GetProperty<PSRoutine::PropertyAniState>()) * 0x4 ); // Game.dll Map to String
    p_RetString += "_";
    //std::cout << "RetString: " << p_RetString << "\n";

    if ( !actorEntity.Inventory.IsValid ( ) || p_Action == gEAction_Fall ) {
        p_RetString += "None_None_";
        //std::cout << "RetString: " << p_RetString << "\n";
    }
    else {
        //Entity leftWeapon = (( gCInventory_PS* )( actorEntity.Inventory.m_pEngineEntityPropertySet))->GetStackFromSlot ( gESlot_LeftHand );
        Entity leftWeapon = actorEntity.Inventory.GetItemFromSlot ( gESlot_LeftHand );
        //std::cout << "LeftWeapon: " << leftWeapon.GetName() << "\n";
        if ( leftWeapon == None ) {
            //std::cout << "Problems in Leftweapon\n";
            p_RetString += "None_";
            //std::cout << "RetString: " << p_RetString << "\n";
        }
        else {
            if ( leftWeapon.Interaction.IsValid ( ) ) {
                p_RetString += *( char** )( RVA_Game ( 0x2bac98 ) + static_cast< GEInt >( leftWeapon.Interaction.GetProperty<PSInteraction::PropertyUseType> ( ) )* 0x4);
                p_RetString += "_";
                //std::cout << "RetString: " << p_RetString << "\n";
            }
            else {
                //std::cout << "Problems in Interaction\n";
                p_RetString += "None_";
                //std::cout << "RetString: " << p_RetString << "\n";
            }
        }
        Entity rightWeapon = actorEntity.Inventory.GetItemFromSlot ( gESlot_RightHand );
        if ( rightWeapon == None ) {
            p_RetString += "None_";
            //std::cout << "Problems in Rightweapon\n";
            //std::cout << "RetString: " << p_RetString << "\n";
        }
        else {
            if ( rightWeapon.Interaction.IsValid ( ) ) {
                p_RetString += *( char** )( RVA_Game ( 0x2bac98 ) + static_cast< GEInt >( rightWeapon.Interaction.GetProperty<PSInteraction::PropertyUseType> ( ) ) * 0x4 );
                p_RetString += "_";
                //std::cout << "RetString: " << p_RetString << "\n";
            }
            else {
                //std::cout << "Problems in Interaction\n";
                p_RetString += "None_";
                //std::cout << "RetString: " << p_RetString << "\n";
            }
        }
    }
    if ( actorEntity.NPC.m_pEngineEntityPropertySet == nullptr ) {
        p_RetString += "P0_";
        //std::cout << "RetString: " << p_RetString << "\n";
    }
    else {
        // TODO
        //if ( &p_Str1 != nullptr )//Test more
            //*( short* )( &p_Str1 - 4 ) = *( short* )( &p_Str1 - 4 ) + 1;
        gEPose actorPose = ((gCNPC_PS*)(actorEntity.NPC.m_pEngineEntityPropertySet))->GetPrimaryPoseExt ( p_Action,p_Str1 );
        p_RetString += *( bCString* )( RVA_Game ( 0x3f7878 ) + static_cast<GEInt>(actorPose) * 0x4 );
        p_RetString += "_";
        //std::cout << "RetString: " << p_RetString << "\n";
    }
    p_RetString += *( bCString* )( RVA_Game ( 0x3f75c0 ) + static_cast< GEInt >( p_Action ) * 0x4 );
    p_RetString += "_";
    //std::cout << "RetString: " << p_RetString << "\n";
    p_RetString += p_Str1;
    p_RetString += "_";
    //std::cout << "RetString: " << p_RetString << "\n";
    if ( !p_Bool ) {
        p_RetString += "N_";
    }
    else {
        p_RetString += "O_";
    }
    //std::cout << "RetString: " << p_RetString << "\n";
    p_RetString += p_Str2;
    p_RetString += "_00_";
    //std::cout << "RetString: " << p_RetString << "\n";
}

/**
* Adjust the List of bCString ID-Values for the Usetype (117 gEUseType)
* With that all Game.dll AnimationName Choosers use the Namespace of the Weapontype
* It is specifically needed for more seperation of the Games 2H-Animations which are Shared between 2H, Axes, Pickaxes, and Halberts
*/
void AdjustUseTypeStringList ( ) {
    DWORD currProt , newProt;
    VirtualProtect ( ( LPVOID )RVA_Game ( 0x2bac98 ) , 117*0x4 , PAGE_EXECUTE_READWRITE , &currProt );
    memset ( ( LPVOID )RVA_Game ( 0x2bac98 ) , 0x90 , 117 * 0x4 );
    memcpy ( ( LPVOID )RVA_Game ( 0x2bac98 ) , useTypesStrings , 117 * 0x4 );
    VirtualProtect ( ( LPVOID )RVA_Game ( 0x2bac98 ) , 117 * 0x4 , currProt , &newProt );
}


extern "C" __declspec( dllexport )
gSScriptInit const * GE_STDCALL ScriptInit( void )
{
    //AllocConsole ( );
    //freopen_s ( ( FILE** )stdout , "CONOUT$" , "w" , stdout );
    // Ensure that that Script_Game.dll is loaded.
    GetScriptAdmin().LoadScriptDLL("Game.dll");
    //InitMap ( );
    AdjustUseTypeStringList ( );
    static mCFunctionHook Hook_GetAniName;

    Hook_GetAniName.Hook ( RVA_Game ( 0x16f840 ) , &GetAniName , mCBaseHook::mEHookType_ThisCall );

    return &GetScriptInit();
}

//
// Entry Point
//

BOOL APIENTRY DllMain( HMODULE hModule, DWORD dwReason, LPVOID )
{
    switch( dwReason )
    {
    case DLL_PROCESS_ATTACH:
        ::DisableThreadLibraryCalls( hModule );
        break;
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
