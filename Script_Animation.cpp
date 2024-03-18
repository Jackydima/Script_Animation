#include "Script_Animation.h"

#include "util/Memory.h"
#include "util/Logging.h"
#include "util/Hook.h"
#include <iostream>
#include "Script.h"



static void InitMap ( ) {
    useTypeMap[gEUseType_None] = "None";
    useTypeMap[gEUseType_Action] = "Action";
    useTypeMap[gEUseType_1H] = "1H";
    useTypeMap[gEUseType_2H] = "2H";
    useTypeMap[gEUseType_Arrow] = "Arrow";
    useTypeMap[gEUseType_Bow] = "Bow";
    useTypeMap[gEUseType_CrossBow] = "CrossBow";
    useTypeMap[gEUseType_Bolt] = "Bolt";
    useTypeMap[gEUseType_Fist] = "Fist";
    useTypeMap[gEUseType_Shield] = "Shield";
    useTypeMap[gEUseType_Armor] = "Armor";
    useTypeMap[gEUseType_Helmet] = "Helmet";
    useTypeMap[gEUseType_Staff] = "Staff";
    useTypeMap[gEUseType_Amulet] = "Amulet";
    useTypeMap[gEUseType_Ring] = "Ring";
    useTypeMap[gEUseType_Cast] = "Cast";
    useTypeMap[gEUseType_Potion] = "Potion";
    useTypeMap[gEUseType_Plant] = "Bread";
    useTypeMap[gEUseType_Meat] = "Meat";
    useTypeMap[gEUseType_Fruit] = "Fruit";
    useTypeMap[gEUseType_Bread] = "Bread";
    useTypeMap[gEUseType_Bottle] = "Potion";
    useTypeMap[gEUseType_Cup] = "Cup";
    useTypeMap[gEUseType_Bowl] = "Bowl";
    useTypeMap[gEUseType_Torch] = "Torch";
    useTypeMap[gEUseType_Alarmhorn] = "Alarmhorn";
    useTypeMap[gEUseType_Broom] = "Staff";
    useTypeMap[gEUseType_Brush] = "Block";
    useTypeMap[gEUseType_Lute] = "Lute";
    useTypeMap[gEUseType_Rake] = "Staff";
    useTypeMap[gEUseType_TrophyTeeth] = "TrophyTeeth";
    useTypeMap[gEUseType_Valuable] = "Valuable";
    useTypeMap[gEUseType_Smoke] = "Smoke";
    useTypeMap[gEUseType_OrcPipe] = "OrcPipe";
    useTypeMap[gEUseType_Scoop] = "Tool";
    useTypeMap[gEUseType_Stick] = "Tool";
    useTypeMap[gEUseType_Shovel] = "Staff";
    useTypeMap[gEUseType_Hammer] = "Tool";
    useTypeMap[gEUseType_Fan] = "Staff";
    useTypeMap[gEUseType_Pan] = "Tool";
    useTypeMap[gEUseType_Saw] = "Tool";
    useTypeMap[gEUseType_TrophySkin] = "TrophySkin";
    useTypeMap[gEUseType_Map] = "Letter";
    useTypeMap[gEUseType_Book] = "Letter";
    useTypeMap[gEUseType_Letter] = "Letter";
    useTypeMap[gEUseType_Key] = "Key";
    useTypeMap[gEUseType_Lockpick] = "Key";
    useTypeMap[gEUseType_CarryFront] = "CarryFront";
    useTypeMap[gEUseType_CarryShoulder] = "CarryShoulder";
    useTypeMap[gEUseType_Pickaxe] = "Axe";
    useTypeMap[gEUseType_TrophyFur] = "TrophyFur";
    useTypeMap[gEUseType_Halberd] = "Staff";
    useTypeMap[gEUseType_Axe] = "Axe";
    useTypeMap[gEUseType_ITEM_E] = "ITEM_E";
    useTypeMap[gEUseType_Modify] = "Modify";
    useTypeMap[gEUseType_PhysicalFist] = "Fist";
    useTypeMap[gEUseType_ITEM_H] = "ITEM_H";
    useTypeMap[gEUseType_Anvil] = "Anvil";
    useTypeMap[gEUseType_Forge] = "Forge";
    useTypeMap[gEUseType_GrindStone] = "GrindStone";
    useTypeMap[gEUseType_Cauldron] = "Cauldron";
    useTypeMap[gEUseType_Barbecue] = "Barbecue";
    useTypeMap[gEUseType_Alchemy] = "Alchemy";
    useTypeMap[gEUseType_Bookshelf] = "Bookshelf";
    useTypeMap[gEUseType_Bookstand] = "Bookstand";
    useTypeMap[gEUseType_TakeStone] = "TakeStone";
    useTypeMap[gEUseType_DropStone] = "DropStone";
    useTypeMap[gEUseType_PickOre] = "PickOre";
    useTypeMap[gEUseType_PickGround] = "PickGround";
    useTypeMap[gEUseType_DigGround] = "DigGround";
    useTypeMap[gEUseType_Field] = "Field";
    useTypeMap[gEUseType_Repair] = "Repair";
    useTypeMap[gEUseType_SawLog] = "SawLog";
    useTypeMap[gEUseType_Lumberjack] = "Lumberjack";
    useTypeMap[gEUseType_Bed] = "Bed";
    useTypeMap[gEUseType_SleepGround] = "SleepGround";
    useTypeMap[gEUseType_CleanFloor] = "CleanFloor";
    useTypeMap[gEUseType_Dance] = "Dance";
    useTypeMap[gEUseType_FanBoss] = "FanBoss";
    useTypeMap[gEUseType_Boss] = "Boss";
    useTypeMap[gEUseType_Throne] = "Throne";
    useTypeMap[gEUseType_Pace] = "Pace";
    useTypeMap[gEUseType_Bard] = "Bard";
    useTypeMap[gEUseType_Stool] = "Stool";
    useTypeMap[gEUseType_Bench] = "Bench";
    useTypeMap[gEUseType_Waterpipe] = "Waterpipe";
    useTypeMap[gEUseType_WaterBarrel] = "WaterBarrel";
    useTypeMap[gEUseType_PirateTreasure] = "Stove";
    useTypeMap[gEUseType_Campfire] = "Campfire";
    useTypeMap[gEUseType_SitCampfire] = "SitCampfire";
    useTypeMap[gEUseType_SitGround] = "SitGround";
    useTypeMap[gEUseType_Smalltalk] = "Smalltalk";
    useTypeMap[gEUseType_Preach] = "Preach";
    useTypeMap[gEUseType_Spectator] = "Spectator";
    useTypeMap[gEUseType_Stand] = "Stand";
    useTypeMap[gEUseType_Guard] = "Guard";
    useTypeMap[gEUseType_Trader] = "Trader";
    useTypeMap[gEUseType_Listener] = "Listener";
    useTypeMap[gEUseType_OrcDance] = "OrcDance";
    useTypeMap[gEUseType_Stoneplate] = "Stoneplate";
    useTypeMap[gEUseType_OrcDrum] = "OrcDrum";
    useTypeMap[gEUseType_Door] = "Door";
    useTypeMap[gEUseType_OrcBoulder] = "OrcBoulder";
    useTypeMap[gEUseType_EatGround] = "EatGround";
    useTypeMap[gEUseType_DrinkWater] = "DrinkWater";
    useTypeMap[gEUseType_Pee] = "Pee";
    useTypeMap[gEUseType_Chest] = "Chest";
    useTypeMap[gEUseType_Shrine] = "Shrine";
    useTypeMap[gEUseType_AttackPoint] = "AttackPoint";
    useTypeMap[gEUseType_Roam] = "Roam";
    useTypeMap[gEUseType_BODY_A] = "BODY_A";
    useTypeMap[gEUseType_Beard] = "Beard";
    useTypeMap[gEUseType_Hair] = "Hair";
    useTypeMap[gEUseType_Head] = "Head";
    useTypeMap[gEUseType_Body] = "Body";
    useTypeMap[gEUseType_Flee] = "Flee";
    useTypeMap[gEUseType_Talk] = "Talk";
}

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
                p_RetString += useTypeMap[leftWeapon.Interaction.GetProperty<PSInteraction::PropertyUseType> ( )];
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
                p_RetString += useTypeMap[rightWeapon.Interaction.GetProperty<PSInteraction::PropertyUseType> ( )];
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

extern "C" __declspec( dllexport )
gSScriptInit const * GE_STDCALL ScriptInit( void )
{
    //AllocConsole ( );
    //freopen_s ( ( FILE** )stdout , "CONOUT$" , "w" , stdout );
    // Ensure that that Script_Game.dll is loaded.
    GetScriptAdmin().LoadScriptDLL("Game.dll");
    InitMap ( );
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
