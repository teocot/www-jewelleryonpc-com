//-----------------------------------------------------------------------------
// File States.h
//-----------------------------------------------------------------------------
// States.h defines the states for the application
// using the Turing model of a state machine
//-----------------------------------------------------------------------------
#pragma once

#define STATE											  0x100000
//-----------------------------------------------------------------------------
//WHEN THE PERSPECTIVE MOVES IN THE CAMERA,
//THESE PERSPECTIVE DEFINITIONS WILL MOVE INTO THE OBJECTLIB
#define PERSPECTIVE										  0x200000
#define ORTHO2D		PERSPECTIVE							+ 0x010000
#define ORTHO		PERSPECTIVE							+ 0x020000
#define ISOMETRIC	PERSPECTIVE							+ 0x030000
#define ANYTHING	PERSPECTIVE							+ 0x040000

#define CAMERA											  0x300000
#define CAMERA_FRONT_VIEW								+ 0x010000
#define CAMERA_BACK_VIEW								+ 0x020000
#define CAMERA_LEFT_VIEW								+ 0x030000
#define CAMERA_RIGHT_VIEW								+ 0x040000
#define CAMERA_TOP_VIEW								    + 0x050000
#define CAMERA_BOTTOM_VIEW								+ 0x060000
#define CAMERA_PERSPECTIVE_VIEW							+ 0x070000

#define DRAW											  0x400000
#define DRAW_SOLID		DRAW							+ 0x010000
#define DRAW_FACE		DRAW							+ 0x020000
#define DRAW_WIRE		DRAW							+ 0x030000
#define DRAW_VERTEX		DRAW							+ 0x040000
#define DRAW_TEXTURE	DRAW							+ 0x050000

//****************************** SCENE *****************************//
#define STATE_SCENE					STATE				+ 0x010000
#define STATE_SCENE_MOVE			STATE_SCENE			+ 0x001000
#define STATE_SCENE_MOVE_X			STATE_SCENE_MOVE	+ 0x000100
#define STATE_SCENE_MOVE_Y			STATE_SCENE_MOVE	+ 0x000200
#define STATE_SCENE_MOVE_Z			STATE_SCENE_MOVE	+ 0x000300

#define STATE_SCENE_ROTATE			STATE_SCENE			+ 0x002000
#define STATE_SCENE_ROTATE_X		STATE_SCENE_ROTATE  + 0x000100
#define STATE_SCENE_ROTATE_Y		STATE_SCENE_ROTATE  + 0x000200
#define STATE_SCENE_ROTATE_Z		STATE_SCENE_ROTATE  + 0x000300

#define STATE_SCENE_SCALE			STATE_SCENE			+ 0x003000
#define STATE_SCENE_SCALE_IN		STATE_SCENE_SCALE	+ 0x000100
#define STATE_SCENE_SCALE_OUT		STATE_SCENE_SCALE	+ 0x000200
//THIS ONE SHOULD BE FOR THE CAMERA + SOME PERSPECTIVE STATES
#define STATE_SCENE_WALK			STATE_SCENE			+ 0x004000
#define STATE_SCENE_PAN				STATE_SCENE			+ 0x005000
//****************************** SCENE *****************************//
 
//****************************** OBJECT *****************************//
#define STATE_OBJECT				STATE				+ 0x020000
#define STATE_OBJECT_SELECT			STATE_OBJECT		+ 0x001000
//--------------------------------------------------------------------
// alt key pressed, we add to the selection list
#define STATE_OBJECT_SELECT_ADD		STATE_OBJECT_SELECT	+ 0x000100
//--------------------------------------------------------------------
// ctr key pressed, 
// select + add to the selection list if not selected
// unselect + remove from the selection list if selected
#define STATE_OBJECT_SELECT_OR		STATE_OBJECT_SELECT	+ 0x000200
//--------------------------------------------------------------------

#define STATE_OBJECT_MOVE			STATE_OBJECT		+ 0x002000
#define STATE_OBJECT_MOVE_X			STATE_OBJECT_MOVE	+ 0x000100
#define STATE_OBJECT_MOVE_Y			STATE_OBJECT_MOVE	+ 0x000200
#define STATE_OBJECT_MOVE_Z			STATE_OBJECT_MOVE	+ 0x000300
#define STATE_OBJECT_MOVE_ADD		STATE_OBJECT_MOVE	+ 0x000400
#define STATE_OBJECT_MOVE_OR		STATE_OBJECT_MOVE	+ 0x000500

#define STATE_OBJECT_ROTATE			STATE_OBJECT		+ 0x003000
#define STATE_OBJECT_ROTATE_X		STATE_OBJECT_ROTATE + 0x000100
#define STATE_OBJECT_ROTATE_Y		STATE_OBJECT_ROTATE + 0x000200
#define STATE_OBJECT_ROTATE_Z		STATE_OBJECT_ROTATE + 0x000300
#define STATE_OBJECT_ROTATE_ADD		STATE_OBJECT_ROTATE + 0x000400
#define STATE_OBJECT_ROTATE_OR		STATE_OBJECT_ROTATE + 0x000500

#define STATE_OBJECT_SCALE			STATE_OBJECT		+ 0x004000
#define STATE_OBJECT_SCALE_X		STATE_OBJECT_SCALE  + 0x000100
#define STATE_OBJECT_SCALE_Y		STATE_OBJECT_SCALE  + 0x000200
#define STATE_OBJECT_SCALE_Z		STATE_OBJECT_SCALE  + 0x000300
#define STATE_OBJECT_SCALE_ADD		STATE_OBJECT_SCALE  + 0x000400
#define STATE_OBJECT_SCALE_OR		STATE_OBJECT_SCALE  + 0x000500

#define STATE_OBJECT_DRAW			STATE_OBJECT		+ 0x005000
#define STATE_OBJECT_DRAW_SOLID		STATE_OBJECT_DRAW	+ 0x000100
#define STATE_OBJECT_DRAW_WIRE		STATE_OBJECT_DRAW	+ 0x000200
#define STATE_OBJECT_DRAW_POINTS	STATE_OBJECT_DRAW	+ 0x000300
//****************************** OBJECT *****************************//

//****************************** CREATE *****************************//
#define STATE_CREATE				STATE					+ 0x050000

#define STATE_CREATE				STATE					+ 0x050000

//****************************** MESH *****************************//
#define STATE_CREATE_MESH			STATE_CREATE			+ 0x001000
//****************************** MESH *****************************//


//****************************** SOLIDS *****************************//
#define STATE_CREATE_SOLID				STATE_CREATE			+ 0x004000

//****************************** MODIFY *****************************//
//#define STATE_MODIFY					STATE					+ 0x060000

//****************************** ROTATION_MESH *****************************//
#define STATE_ROTATION_MESH				STATE					+ 0x080000
#define STATE_ROTATION_MESH_PROFILE		STATE_ROTATION_MESH		+ 0x001000
#define STATE_ROTATION_MESH_AXIS		STATE_ROTATION_MESH		+ 0x002000
#define STATE_ROTATION_MESH_GENERATE	STATE_ROTATION_MESH		+ 0x003000
//****************************** ROTATION_MESH *****************************//


//******************************************* RING *****************************//
#define STATE_RING							STATE				+ 0x060000
#define STATE_RING_CHOICE					STATE_RING			+ 0x001000

#define STATE_RING_CUT_NO_SELECTION			STATE_RING_CHOICE	+ 0x000100
#define STATE_RING_CUT_CUT_SELECTED			STATE_RING_CHOICE	+ 0x000010
#define STATE_RING_CUT_GEM_SELECTED			STATE_RING_CHOICE	+ 0x000020
#define STATE_RING_CUT_BOTH_SELECTED		STATE_RING_CHOICE	+ 0x000030
#define STATE_RING_CUT_CREATED				STATE_RING_CHOICE	+ 0x000040

#define STATE_RING_BAND_NO_SELECTION		STATE_RING_CHOICE	+ 0x000200
#define STATE_RING_BAND_BAND_SELECTED		STATE_RING_CHOICE	+ 0x000010
#define STATE_RING_BAND_METAL_SELECTED		STATE_RING_CHOICE	+ 0x000020
#define STATE_RING_BAND_BOTH_SELECTED		STATE_RING_CHOICE	+ 0x000030
#define STATE_RING_BAND_CREATED				STATE_RING_CHOICE	+ 0x000040

#define STATE_RING_SETTING_NO_SELECTION		STATE_RING_CHOICE	+ 0x000300
#define STATE_RING_SETTING_SETTING_SELECTED	STATE_RING_CHOICE	+ 0x000010
#define STATE_RING_SETTING_METAL_SELECTED	STATE_RING_CHOICE	+ 0x000020
#define STATE_RING_SETTING_BOTH_SELECTED	STATE_RING_CHOICE	+ 0x000030
#define STATE_RING_SETTING_CREATED			STATE_RING_CHOICE	+ 0x000040

#define STATE_RING_NOT_CREATED				STATE_RING_CHOICE	+ 0x000500
#define STATE_RING_CREATED					STATE_RING_CHOICE	+ 0x000600

#define STATE_ZOOM_RING						STATE_RING_CHOICE	+ 0x000700
#define STATE_ZOOM_ELEMENT					STATE_RING_CHOICE	+ 0x000800

#define RING_ACTION							STATE_RING			+ 0x002000
#define ACTION_RING_SELECT_CUT				RING_ACTION			+ 0x000010
#define ACTION_RING_SELECT_GEMSTONE			RING_ACTION			+ 0x000020
#define ACTION_RING_CREATE_CUT				RING_ACTION			+ 0x000030
#define ACTION_RING_SELECT_BAND				RING_ACTION			+ 0x000040
#define ACTION_RING_SELECT_BANDMETAL		RING_ACTION			+ 0x000050
#define ACTION_RING_CREATE_BAND				RING_ACTION			+ 0x000060
#define ACTION_RING_SELECT_SETTING			RING_ACTION			+ 0x000070
#define ACTION_RING_SELECT_SETTINGMETAL		RING_ACTION			+ 0x000080
#define ACTION_RING_CREATE_SETTING			RING_ACTION			+ 0x000090
#define ACTION_RING_CREATE_RING				RING_ACTION			+ 0x0000A0
//this is for when we open a ring from a file:
#define ACTION_RING_IMPORT_RING				RING_ACTION			+ 0x0000B0

