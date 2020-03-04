//-----------------------------------------------------------------------------
// File ObjectDefinitions.h
//-----------------------------------------------------------------------------
#pragma once

enum draw_style{SOLID, WIRE, VERTEX};
//-----------------------------------------------------------------------------

//#define SOLID 0x010000
//#define WIRE  0x020000
#define SELECTION  0x030000

#define OBJECT_TOKEN			 99
#define EDGE_TOKEN				101
#define FACE_TOKEN				102
#define VERTEX_TOKEN			103
#define AXES_TOKEN				104
#define MOVEAXES_TOKEN			105
#define MOVEAXES_X_TOKEN		104
#define MOVEAXES_Y_TOKEN		105
#define MOVEAXES_Z_TOKEN		106
#define ROTATEAXES_TOKEN		107
#define ROTATEAXES_X_TOKEN		108
#define ROTATEAXES_Y_TOKEN		109
#define ROTATEAXES_Z_TOKEN		110
#define SCALEAXES_TOKEN			111
#define SCALEAXES_X_TOKEN		112
#define SCALEAXES_Y_TOKEN		113
#define SCALEAXES_Z_TOKEN		114

#define SELECTION_PLANE_TOKEN	115

//2d tokens, these objects are not meshes??
#define POINT3D_TOKEN			116

#define EXTRUSION_FACE_TOKEN	117
#define EXTRUSION_VECTOR_TOKEN	118
//-----------------------------------------------------------------------------
