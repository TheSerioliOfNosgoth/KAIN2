#pragma once

#include <windows.h>
#include <ddraw.h>
#include <d3d.h>
#include "d3dbuckt.h"
#include "d3dclip.h"

typedef struct SystemTextureD3D
{
	DWORD age;
	DWORD clut;
	LPDIRECTDRAWSURFACE4 surface;
	IDirect3DTexture2* texture;
	SystemTextureD3D* linked;
} SystemTextureD3D;

typedef struct SystemTexturePool
{
	int age;
	int clut;
	LPDIRECTDRAWSURFACE4 surface;
	IDirect3DTexture2* texture;
} SystemTexturePool;

extern DWORD D3D_ClipPlaneMask, D3D_InverseClipPlanes;
extern float D3D_LeftClip, D3D_BottomClip, D3D_TopClip, D3D_RightClip,
	D3D_FarClip, D3D_NearClip;
extern int D3D_Windowed,
	D3D_XRes,
	D3D_YRes,
	D3D_BitDepth,
	D3D_Triplebuf,
	D3D_VSync,
	D3D_Filter,
	D3D_InScene;

extern DDPIXELFORMAT sys_texture_fmt;
extern DWORD sys_texture_amask, sys_texture_rmask, sys_texture_gmask, sys_texture_bmask;
extern int sys_texture_cnt, dev_texture_cnt;
extern SystemTextureD3D sys_textures[32];
extern SystemTexturePool sys_texture_pool[64];
extern HANDLE sys_texture_handle;
extern RTL_CRITICAL_SECTION sys_tex_csec;
extern int sys_cluts[64], sys_clut_cnt;