#pragma once

#include "Script.h"
//#include <map>

gSScriptInit & GetScriptInit();
static const char* useTypesStrings[] = {
 "None" ,
 "Action",
 "1H",
 "2H",
 "Arrow",
 "Bow",
 "CrossBow",
 "Bolt",
 "Fist",
 "Shield",
 "Armor",
 "Helmet",
 "Staff",
 "Amulet",
 "Ring",
 "Cast",
 "Potion",
 "Bread",
 "Meat",
 "Fruit",
 "Bread",
 "Potion",
 "Cup",
 "Bowl",
 "Torch",
 "Alarmhorn",
 "Staff",
 "Block",
 "Lute",
 "Staff",
 "TrophyTeeth",
 "Valuable",
 "Smoke",
 "OrcPipe",
 "Tool",
 "Tool",
 "Staff",
 "Tool",
 "Staff",
 "Tool",
 "Tool",
 "TrophySkin",
 "Letter",
 "Letter",
 "Letter",
 "Key",
 "Key",
 "CarryFront",
 "CarryShoulder",
 "Axe",
 "TrophyFur",
 "Staff",
 "Axe",
 "ITEM_E",
 "Modify",
 "Fist",
 "ITEM_H",
 "Anvil",
 "Forge",
 "GrindStone",
 "Cauldron",
 "Barbecue",
 "Alchemy",
 "Bookshelf",
 "Bookstand",
 "TakeStone",
 "DropStone",
 "PickOre",
 "PickGround",
 "DigGround",
 "Field",
 "Repair",
 "SawLog",
 "Lumberjack",
 "Bed",
 "SleepGround",
 "CleanFloor",
 "Dance",
 "FanBoss",
 "Boss",
 "Throne",
 "Pace",
 "Bard",
 "Stool",
 "Bench",
 "Waterpipe",
 "WaterBarrel",
 "Stove",
 "Campfire",
 "SitCampfire",
 "SitGround",
 "Smalltalk",
 "Preach",
 "Spectator",
 "Stand",
 "Guard",
 "Trader",
 "Listener",
 "OrcDance",
 "Stoneplate",
 "OrcDrum",
 "Door",
 "OrcBoulder",
 "EatGround",
 "DrinkWater",
 "Pee",
 "Chest",
 "Shrine",
 "AttackPoint",
 "Roam",
 "BODY_A",
 "Beard",
 "Hair",
 "Head",
 "Body",
 "Flee",
 "Talk" ,
};
//static std::map<gEUseType , bCString> useTypeMap;
/*static void InitMap ( ) {
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
}*/