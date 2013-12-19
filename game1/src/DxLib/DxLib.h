// -------------------------------------------------------------------------------
// 
// 		ＤＸライブラリ		ヘッダファイル
// 
// 				Ver 3.10e
// 
// -------------------------------------------------------------------------------

#ifndef __DXLIB
#define __DXLIB

#include "DxCompileConfig.h"
#include "DxDirectX.h"

// ＤＸライブラリのバージョン
#define DXLIB_VERSION 0x310e
#define DXLIB_VERSION_STR _T( "3.10e" )

// 設定 -----------------------------------------------------------------------

// ＤＸライブラリに必要な lib ファイルを、プロジェクトのカレントフォルダや
// コンパイラのデフォルト LIB パスに設定せずに使用される場合は以下の
// コメントを外してください
//#define DX_LIB_NOT_DEFAULTPATH

#ifndef __DX_MAKE

// 描画関連の関数を一切使用されない場合は以下のコメントを外して下さい
//#define DX_NOTUSE_DRAWFUNCTION

#endif // __DX_MAKE

// ライブラリリンク定義--------------------------------------------------------

#if !defined( __ANDROID ) && !defined( DDX_GCC_COMPILE )

#ifndef __DX_MAKE
	#ifndef DX_LIB_NOT_DEFAULTPATH
		#ifndef DX_SRC_COMPILE
			#ifdef _MSC_VER
				#ifdef _WIN64
					#ifdef _DEBUG
						#pragma comment( lib, "DxDrawFunc_x64_d.lib"		)		//  描画部分の抜き出し
						#ifdef UNICODE
							#pragma comment( lib, "DxLibW_x64_d.lib"		)		//  ＤＸライブラリ使用指定
							#pragma comment( lib, "DxUseCLibW_x64_d.lib"	)		//  標準Ｃライブラリを使用する部分の lib ファイルの使用指定
						#else
							#pragma comment( lib, "DxLib_x64_d.lib"			)		//  ＤＸライブラリ使用指定
							#pragma comment( lib, "DxUseCLib_x64_d.lib"		)		//  標準Ｃライブラリを使用する部分の lib ファイルの使用指定
						#endif
					#else
						#pragma comment( lib, "DxDrawFunc_x64.lib"			)		//  描画部分の抜き出し
						#ifdef UNICODE
							#pragma comment( lib, "DxLibW_x64.lib"			)		//  ＤＸライブラリ使用指定
							#pragma comment( lib, "DxUseCLibW_x64.lib"		)		//  標準Ｃライブラリを使用する部分の lib ファイルの使用指定
						#else
							#pragma comment( lib, "DxLib_x64.lib"			)		//  ＤＸライブラリ使用指定
							#pragma comment( lib, "DxUseCLib_x64.lib"		)		//  標準Ｃライブラリを使用する部分の lib ファイルの使用指定
						#endif
					#endif
				#else
					#ifdef _DEBUG
						#pragma comment( lib, "DxDrawFunc_d.lib"		)		//  描画部分の抜き出し
						#ifdef UNICODE
							#pragma comment( lib, "DxLibW_d.lib"		)		//  ＤＸライブラリ使用指定
							#pragma comment( lib, "DxUseCLibW_d.lib"	)		//  標準Ｃライブラリを使用する部分の lib ファイルの使用指定
						#else
							#pragma comment( lib, "DxLib_d.lib"			)		//  ＤＸライブラリ使用指定
							#pragma comment( lib, "DxUseCLib_d.lib"		)		//  標準Ｃライブラリを使用する部分の lib ファイルの使用指定
						#endif
					#else
						#pragma comment( lib, "DxDrawFunc.lib"			)		//  描画部分の抜き出し
						#ifdef UNICODE
							#pragma comment( lib, "DxLibW.lib"			)		//  ＤＸライブラリ使用指定
							#pragma comment( lib, "DxUseCLibW.lib"		)		//  標準Ｃライブラリを使用する部分の lib ファイルの使用指定
						#else
							#pragma comment( lib, "DxLib.lib"			)		//  ＤＸライブラリ使用指定
							#pragma comment( lib, "DxUseCLib.lib"		)		//  標準Ｃライブラリを使用する部分の lib ファイルの使用指定
						#endif
					#endif
				#endif
			#else
				#pragma comment( lib, "DxDrawFunc.lib"		)			//  描画部分の抜き出し
				#ifdef UNICODE
					#pragma comment( lib, "DxLibW.lib"		)			//  ＤＸライブラリ使用指定
					#pragma comment( lib, "DxUseCLibW.lib"	)			//  標準Ｃライブラリを使用する部分の lib ファイルの使用指定
				#else
					#pragma comment( lib, "DxLib.lib"		)			//  ＤＸライブラリ使用指定
					#pragma comment( lib, "DxUseCLib.lib"	)			//  標準Ｃライブラリを使用する部分の lib ファイルの使用指定
				#endif
			#endif

			#ifdef _DEBUG
				#pragma comment( linker, "/NODEFAULTLIB:libcmt.lib" )
				#pragma comment( linker, "/NODEFAULTLIB:libc.lib" )
				#pragma comment( linker, "/NODEFAULTLIB:libcd.lib" )
	//			#pragma comment( linker, "/NODEFAULTLIB:msvcrt.lib" )
	//			#pragma comment( linker, "/NODEFAULTLIB:msvcrtd.lib" )
			#else
				#pragma comment( linker, "/NODEFAULTLIB:libcmtd.lib" )
				#pragma comment( linker, "/NODEFAULTLIB:libc.lib" )
				#pragma comment( linker, "/NODEFAULTLIB:libcd.lib" )
	//			#pragma comment( linker, "/NODEFAULTLIB:msvcrt.lib" )
	//			#pragma comment( linker, "/NODEFAULTLIB:msvcrtd.lib" )
			#endif
		#endif
		//#pragma comment( lib, "libcmt.lib"		)				//  C標準マルチスレッド対応ライブラリ
		#pragma comment( lib, "kernel32.lib"		)			//  Win32カーネルライブラリ
		//#pragma comment( lib, "comctl32.lib"		)			//　Win32APIライブラリ
		#pragma comment( lib, "user32.lib"		)				//  Win32APIライブラリ
		#pragma comment( lib, "gdi32.lib"		)				//  Win32APIライブラリ
		#pragma comment( lib, "advapi32.lib"		)			//  Win32APIライブラリ
		//#pragma comment( lib, "ole32.lib"		)				//  Win32APIライブラリ
		#pragma comment( lib, "shell32.lib"		)				//  マルチメディアライブラリ
		//#pragma comment( lib, "winmm.lib"		)				//  マルチメディアライブラリ
		#ifndef DX_NON_MOVIE
			//#pragma comment( lib, "Strmiids.lib" )			//　DirectShowライブラリ
		#endif
		#ifndef DX_NON_NETWORK
			//#pragma comment( lib, "wsock32.lib" )				//  WinSocketsライブラリ
		#endif
		#ifndef DX_NON_KEYEX
			//#pragma comment( lib, "imm32.lib" )					// ＩＭＥ操作用ライブラリ
		#endif
		#ifndef DX_NON_ACM
			//#pragma comment( lib, "msacm32.lib" )				// ＡＣＭ操作用ライブラリ 
		#endif
		#ifndef DX_NON_BULLET_PHYSICS
			#ifdef _MSC_VER
				#ifdef DX_USE_VC8_BULLET_PHYSICS_LIB
					#ifdef _WIN64
						#ifdef _DEBUG
							#pragma comment( lib, "libbulletcollision_vc8_x64_d.lib" )	// Visual C++ 8.0 でコンパイルした Bullet Physics ライブラリ 
							#pragma comment( lib, "libbulletdynamics_vc8_x64_d.lib" )
							#pragma comment( lib, "libbulletmath_vc8_x64_d.lib" )
						#else
							#pragma comment( lib, "libbulletcollision_vc8_x64.lib" )	// Visual C++ 8.0 でコンパイルした Bullet Physics ライブラリ 
							#pragma comment( lib, "libbulletdynamics_vc8_x64.lib" )
							#pragma comment( lib, "libbulletmath_vc8_x64.lib" )
						#endif
					#else
						#ifdef _DEBUG
							#pragma comment( lib, "libbulletcollision_vc8_d.lib" )	// Visual C++ 8.0 でコンパイルした Bullet Physics ライブラリ 
							#pragma comment( lib, "libbulletdynamics_vc8_d.lib" )
							#pragma comment( lib, "libbulletmath_vc8_d.lib" )
						#else
							#pragma comment( lib, "libbulletcollision_vc8.lib" )	// Visual C++ 8.0 でコンパイルした Bullet Physics ライブラリ 
							#pragma comment( lib, "libbulletdynamics_vc8.lib" )
							#pragma comment( lib, "libbulletmath_vc8.lib" )
						#endif
					#endif
				#else
					#ifdef _WIN64
						#ifdef _DEBUG
							#pragma comment( lib, "libbulletcollision_vc8_x64_d.lib" )	// Visual C++ 8.0 でコンパイルした Bullet Physics ライブラリ 
							#pragma comment( lib, "libbulletdynamics_vc8_x64_d.lib" )
							#pragma comment( lib, "libbulletmath_vc8_x64_d.lib" )
						#else
							#pragma comment( lib, "libbulletcollision_vc8_x64.lib" )	// Visual C++ 8.0 でコンパイルした Bullet Physics ライブラリ 
							#pragma comment( lib, "libbulletdynamics_vc8_x64.lib" )
							#pragma comment( lib, "libbulletmath_vc8_x64.lib" )
						#endif
					#else
						#ifdef _DEBUG
							#pragma comment( lib, "libbulletcollision_vc6_d.lib" )	// Visual C++ 6.0 でコンパイルした Bullet Physics ライブラリ 
							#pragma comment( lib, "libbulletdynamics_vc6_d.lib" )
							#pragma comment( lib, "libbulletmath_vc6_d.lib" )
						#else
							#pragma comment( lib, "libbulletcollision_vc6.lib" )	// Visual C++ 6.0 でコンパイルした Bullet Physics ライブラリ 
							#pragma comment( lib, "libbulletdynamics_vc6.lib" )
							#pragma comment( lib, "libbulletmath_vc6.lib" )
						#endif
					#endif
				#endif
			#else
				#pragma comment( lib, "libbulletcollision.lib" )	// Bullet Physics ライブラリ 
				#pragma comment( lib, "libbulletdynamics.lib" )
				#pragma comment( lib, "libbulletmath.lib" )
			#endif
		#endif
		#ifndef DX_NON_PNGREAD
			#ifdef _MSC_VER
				#ifdef _WIN64
					#ifdef _DEBUG
						#pragma comment( lib, "libpng_x64_d.lib" )		// ＰＮＧライブラリ
						#pragma comment( lib, "zlib_x64_d.lib" )
					#else
						#pragma comment( lib, "libpng_x64.lib" )		// ＰＮＧライブラリ
						#pragma comment( lib, "zlib_x64.lib" )
					#endif
				#else
					#ifdef _DEBUG
						#pragma comment( lib, "libpng_d.lib" )			// ＰＮＧライブラリ
						#pragma comment( lib, "zlib_d.lib" )
					#else
						#pragma comment( lib, "libpng.lib" )			// ＰＮＧライブラリ
						#pragma comment( lib, "zlib.lib" )
					#endif
				#endif
			#else
				#pragma comment( lib, "libpng.lib" )			// ＰＮＧライブラリ
				#pragma comment( lib, "zlib.lib" )
			#endif
		#endif
		#ifndef DX_NON_JPEGREAD
			#ifdef _MSC_VER
				#ifdef _WIN64
					#ifdef _DEBUG
						#pragma comment( lib, "libjpeg_x64_d.lib" )		// ＪＰＥＧライブラリ
					#else
						#pragma comment( lib, "libjpeg_x64.lib" )		// ＪＰＥＧライブラリ
					#endif
				#else
					#ifdef _DEBUG
						#pragma comment( lib, "libjpeg_d.lib" )			// ＪＰＥＧライブラリ
					#else
						#pragma comment( lib, "libjpeg.lib" )			// ＪＰＥＧライブラリ
					#endif
				#endif
			#else
				#pragma comment( lib, "libjpeg.lib" )			// ＪＰＥＧライブラリ
			#endif
		#endif
		#ifndef DX_NON_OGGVORBIS								// ＯｇｇＶｏｒｂｉｓライブラリ
			#ifdef _MSC_VER
				#ifdef _WIN64
					#ifdef _DEBUG
						#pragma comment( lib, "ogg_static_x64_d.lib" )
						#pragma comment( lib, "vorbis_static_x64_d.lib" )
						#pragma comment( lib, "vorbisfile_static_x64_d.lib" )
					#else
						#pragma comment( lib, "ogg_static_x64.lib" )
						#pragma comment( lib, "vorbis_static_x64.lib" )
						#pragma comment( lib, "vorbisfile_static_x64.lib" )
					#endif
				#else
					#ifdef _DEBUG
						#pragma comment( lib, "ogg_static_d.lib" )
						#pragma comment( lib, "vorbis_static_d.lib" )
						#pragma comment( lib, "vorbisfile_static_d.lib" )
					#else
						#pragma comment( lib, "ogg_static.lib" )
						#pragma comment( lib, "vorbis_static.lib" )
						#pragma comment( lib, "vorbisfile_static.lib" )
					#endif
				#endif
			#else
				#pragma comment( lib, "ogg_static.lib" )
				#pragma comment( lib, "vorbis_static.lib" )
				#pragma comment( lib, "vorbisfile_static.lib" )
			#endif
		#endif
		#ifndef DX_NON_OGGTHEORA								// ＯｇｇＴｈｅｏｒａライブラリ
			#ifdef _MSC_VER
				#ifdef _WIN64
					#ifdef _DEBUG
						#pragma comment( lib, "ogg_static_x64_d.lib" )
						#pragma comment( lib, "vorbis_static_x64_d.lib" )
						#pragma comment( lib, "vorbisfile_static_x64_d.lib" )

						#pragma comment( lib, "libtheora_static_x64_d.lib" )
					#else
						#pragma comment( lib, "ogg_static_x64.lib" )
						#pragma comment( lib, "vorbis_static_x64.lib" )
						#pragma comment( lib, "vorbisfile_static_x64.lib" )

						#pragma comment( lib, "libtheora_static_x64.lib" )
					#endif
				#else
					#ifdef _DEBUG
						#pragma comment( lib, "ogg_static_d.lib" )
						#pragma comment( lib, "vorbis_static_d.lib" )
						#pragma comment( lib, "vorbisfile_static_d.lib" )

						#pragma comment( lib, "libtheora_static_d.lib" )
					#else
						#pragma comment( lib, "ogg_static.lib" )
						#pragma comment( lib, "vorbis_static.lib" )
						#pragma comment( lib, "vorbisfile_static.lib" )

						#pragma comment( lib, "libtheora_static.lib" )
					#endif
				#endif
			#else
				#pragma comment( lib, "ogg_static.lib" )
				#pragma comment( lib, "vorbis_static.lib" )
				#pragma comment( lib, "vorbisfile_static.lib" )

				#pragma comment( lib, "libtheora_static.lib" )
			#endif
		#endif
	#endif
#endif

#endif // !defined( __ANDROID ) && !defined( DDX_GCC_COMPILE )

// 定義---------------------------------------------------------------------------

// π
#define DX_PI										(3.1415926535897932384626433832795 )
#define DX_PI_F										(3.1415926535897932384626433832795f)
#define DX_TWO_PI									(3.1415926535897932384626433832795  * 2.0 )
#define DX_TWO_PI_F									(3.1415926535897932384626433832795f * 2.0f)

#define DX_CHAR										char

#define DX_DEFINE_START

#define MAX_IMAGE_NUM								(32768)				// 同時に持てるグラフィックハンドルの最大数( ハンドルエラーチェックのマスクに使用しているので 65536 以下の 2 のべき乗にして下さい )
#define MAX_2DSURFACE_NUM							(32768)				// ２Ｄサーフェスデータの最大数( ハンドルエラーチェックのマスクに使用しているので 65536 以下の 2 のべき乗にして下さい )
#define MAX_3DSURFACE_NUM							(65536)				// ３Ｄサーフェスデータの最大数( ハンドルエラーチェックのマスクに使用しているので 65536 以下の 2 のべき乗にして下さい )
#define MAX_IMAGE_DIVNUM							(64)				// 画像分割の最大数
#define MAX_SURFACE_NUM								(65536)				// サーフェスデータの最大数
#define MAX_SOFTIMAGE_NUM							(8192)				// 同時に持てるソフトイメージハンドルの最大数( ハンドルエラーチェックのマスクに使用しているので 65536 以下の 2 のべき乗にして下さい )

#define MAX_SOUND_NUM								(32768)				// 同時に持てるサウンドハンドルの最大数
#define MAX_SOFTSOUND_NUM							(8192)				// 同時に持てるソフトウエアサウンドハンドルの最大数
#define MAX_MUSIC_NUM								(256)				// 同時に持てるミュージックハンドルの最大数
#define MAX_MOVIE_NUM								(100)				// 同時に持てるムービーハンドルの最大数
#define MAX_MASK_NUM								(512)				// 同時に持てるマスクハンドルの最大数
#define MAX_FONT_NUM								(40)				// 同時に持てるフォントハンドルの最大数
#define MAX_INPUT_NUM								(256)				// 同時に持てる文字列入力ハンドルの最大数
#define MAX_SOCKET_NUM								(8192)				// 同時に持てる通信ハンドルの最大数
#define MAX_LIGHT_NUM								(4096)				// 同時に持てるライトハンドルの最大数
#define MAX_SHADER_NUM								(4096)				// 同時に持てるシェーダーハンドルの最大数
#define MAX_MODEL_BASE_NUM							(32768)				// 同時に持てる３Ｄモデル基本データハンドルの最大数
#define MAX_MODEL_NUM								(32768)				// 同時に持てる３Ｄモデルデータハンドルの最大数
#define MAX_VERTEX_BUFFER_NUM						(16384)				// 同時に持てる頂点バッファハンドルの最大数
#define MAX_INDEX_BUFFER_NUM						(16384)				// 同時に持てるインデックスバッファの最大数
#define MAX_FILE_NUM								(32768)				// 同時に持てるファイルハンドルの最大数

#define MAX_JOYPAD_NUM								(16)				// ジョイパッドの最大数
#define MAX_EVENTPROCESS_NUM						(5)					// 一度に処理するイベントの最大数

#define DEFAULT_SCREEN_SIZE_X						(640)				// デフォルトの画面の幅
#define DEFAULT_SCREEN_SIZE_Y						(480)				// デフォルトの画面の高さ
#define DEFAULT_COLOR_BITDEPTH						(16)				// デフォルトの色ビット深度

#define DEFAULT_FOV									(60.0F * 3.1415926535897932384626433832795F / 180.0F)	// デフォルトの視野角
#define DEFAULT_TAN_FOV_HALF						(0.57735026918962576450914878050196F) // tan( FOV * 0.5 )
#define DEFAULT_NEAR								(0.0F)				// NEARクリップ面
#define DEFAULT_FAR									(20000.0F)			// FARクリップ面

#define DEFAULT_FONT_SIZE							(16)				// フォントのデフォルトのサイズ
#define DEFAULT_FONT_THINCK							(6)					// フォントのデフォルトの太さ
#define DEFAULT_FONT_TYPE							( DX_FONTTYPE_NORMAL )	// フォントのデフォルトの形態
#define DEFAULT_FONT_EDGESIZE						(1)					// フォントのデフォルトの太さ

#define FONT_CACHE_MAXNUM							(2024)				// フォントキャッシュに格納できる最大文字数
#define FONT_CACHE_MEMORYSIZE						(0x50000)			// フォントキャッシュの最大容量
#define FONT_CACHE_MAX_YLENGTH						(0x4000)			// フォントキャッシュサーフェスの最大縦幅

#define MAX_USERIMAGEREAD_FUNCNUM					(10)				// ユーザーが登録できるグラフィックロード関数の最大数


// ＷＩＮＤＯＷＳのバージョンマクロ
#define DX_WINDOWSVERSION_31						(0x000)
#define DX_WINDOWSVERSION_95						(0x001)
#define DX_WINDOWSVERSION_98						(0x002)
#define DX_WINDOWSVERSION_ME						(0x003)
#define DX_WINDOWSVERSION_NT31						(0x104)
#define DX_WINDOWSVERSION_NT40						(0x105)
#define DX_WINDOWSVERSION_2000						(0x106)
#define DX_WINDOWSVERSION_XP						(0x107)
#define DX_WINDOWSVERSION_VISTA						(0x108)
#define DX_WINDOWSVERSION_7							(0x109)
#define DX_WINDOWSVERSION_8							(0x10A)
#define DX_WINDOWSVERSION_NT_TYPE					(0x100)

// ＤｉｒｅｃｔＸのバージョンマクロ
#define DX_DIRECTXVERSION_NON						(0)
#define DX_DIRECTXVERSION_1							(0x10000)
#define DX_DIRECTXVERSION_2							(0x20000)
#define DX_DIRECTXVERSION_3							(0x30000)
#define DX_DIRECTXVERSION_4							(0x40000)
#define DX_DIRECTXVERSION_5							(0x50000)
#define DX_DIRECTXVERSION_6							(0x60000)
#define DX_DIRECTXVERSION_6_1						(0x60100)
#define DX_DIRECTXVERSION_7							(0x70000)
#define DX_DIRECTXVERSION_8							(0x80000)
#define DX_DIRECTXVERSION_8_1						(0x80100)

// 文字セット
#define DX_CHARSET_DEFAULT							(0)				// デフォルト文字セット
#define DX_CHARSET_SHFTJIS							(1)				// 日本語文字セット
#define DX_CHARSET_HANGEUL							(2)				// 韓国語文字セット
#define DX_CHARSET_BIG5								(3)				// 繁体文字セット
#define DX_CHARSET_GB2312							(4)				// 簡体文字セット

// ＭＩＤＩの再生モード定義
#define DX_MIDIMODE_MCI								(0)				// ＭＣＩによる再生
#define DX_MIDIMODE_DM								(1)				// ＤｉｒｅｃｔＭｕｓｉｃによる再生

// 描画モード定義
#define DX_DRAWMODE_NEAREST							(0)				// ネアレストネイバー法で描画
#define DX_DRAWMODE_BILINEAR						(1)				// バイリニア法で描画する
#define DX_DRAWMODE_ANISOTROPIC						(2)				// 異方性フィルタリング法で描画する
#define DX_DRAWMODE_OTHER							(3)				// それ以外

// フォントのタイプ
#define DX_FONTTYPE_NORMAL							(0x00)				// ノーマルフォント
#define DX_FONTTYPE_EDGE							(0x01)				// エッジつきフォント
#define DX_FONTTYPE_ANTIALIASING					(0x02)				// アンチエイリアスフォント( 標準機能アンチエイリアス )
#define DX_FONTTYPE_ANTIALIASING_4X4				(0x12)				// アンチエイリアスフォント( 4x4サンプリング )
#define DX_FONTTYPE_ANTIALIASING_8X8				(0x22)				// アンチエイリアスフォント( 8x8サンプリング )
#define DX_FONTTYPE_ANTIALIASING_EDGE				(0x03)				// アンチエイリアス＆エッジ付きフォント( 標準機能アンチエイリアス )
#define DX_FONTTYPE_ANTIALIASING_EDGE_4X4			(0x13)				// アンチエイリアス＆エッジ付きフォント( 4x4サンプリング )
#define DX_FONTTYPE_ANTIALIASING_EDGE_8X8			(0x23)				// アンチエイリアス＆エッジ付きフォント( 8x8サンプリング )

// 描画ブレンドモード定義
#define DX_BLENDMODE_NOBLEND						(0)				// ノーブレンド
#define DX_BLENDMODE_ALPHA							(1)				// αブレンド
#define DX_BLENDMODE_ADD							(2)				// 加算ブレンド
#define DX_BLENDMODE_SUB							(3)				// 減算ブレンド
#define DX_BLENDMODE_MUL							(4)				// 乗算ブレンド
   // (内部処理用)
#define DX_BLENDMODE_SUB2							(5)				// 内部処理用減算ブレンド子１
//#define DX_BLENDMODE_BLINEALPHA					(7)				// 境界線ぼかし
#define DX_BLENDMODE_XOR							(6)				// XORブレンド( ソフトウエアレンダリングモードでのみ有効 )
#define DX_BLENDMODE_DESTCOLOR						(8)				// カラーは更新されない
#define DX_BLENDMODE_INVDESTCOLOR					(9)				// 描画先の色の反転値を掛ける
#define DX_BLENDMODE_INVSRC							(10)			// 描画元の色を反転する
#define DX_BLENDMODE_MULA							(11)			// アルファチャンネル考慮付き乗算ブレンド
#define DX_BLENDMODE_ALPHA_X4						(12)			// αブレンドの描画元の輝度を最大４倍にできるモード
#define DX_BLENDMODE_ADD_X4							(13)			// 加算ブレンドの描画元の輝度を最大４倍にできるモード
#define DX_BLENDMODE_SRCCOLOR						(14)			// 描画元のカラーでそのまま描画される
#define DX_BLENDMODE_HALF_ADD						(15)			// 半加算ブレンド

// 画像合成タイプ
#define DX_BLENDGRAPHTYPE_NORMAL					(0)				// 通常合成
#define DX_BLENDGRAPHTYPE_WIPE						(1)				// ワイプ処理
#define DX_BLENDGRAPHTYPE_ALPHA						(2)				// ブレンド画像のα値と元画像のα値を掛け合わせる

// グラフィックフィルタータイプ
#define DX_GRAPH_FILTER_MONO						(0)				// モノトーンフィルタ
#define DX_GRAPH_FILTER_GAUSS						(1)				// ガウスフィルタ
#define DX_GRAPH_FILTER_DOWN_SCALE					(2)				// 縮小フィルタ
#define DX_GRAPH_FILTER_BRIGHT_CLIP					(3)				// 明るさクリップフィルタ
#define DX_GRAPH_FILTER_HSB							(4)				// 色相・彩度・明度フィルタ
#define DX_GRAPH_FILTER_INVERT						(5)				// 階調の反転フィルタ
#define DX_GRAPH_FILTER_LEVEL						(6)				// レベル補正フィルタ
#define DX_GRAPH_FILTER_TWO_COLOR					(7)				// ２階調化フィルタ
#define DX_GRAPH_FILTER_GRADIENT_MAP				(8)				// グラデーションマップフィルタ
#define DX_GRAPH_FILTER_PREMUL_ALPHA				(9)				// 通常のアルファチャンネル付き画像を乗算済みアルファ画像に変換するフィルタ
#define DX_GRAPH_FILTER_NUM							(10)

// グラフィックブレンドタイプ
#define DX_GRAPH_BLEND_NORMAL						(0)				// 通常
#define DX_GRAPH_BLEND_RGBA_SELECT_MIX				(1)				// RGBAの要素を選択して合成
#define DX_GRAPH_BLEND_MULTIPLE						(2)				// 乗算
#define DX_GRAPH_BLEND_DIFFERENCE					(3)				// 減算
#define DX_GRAPH_BLEND_ADD							(4)				// 加算
#define DX_GRAPH_BLEND_SCREEN						(5)				// スクリーン
#define DX_GRAPH_BLEND_OVERLAY						(6)				// オーバーレイ
#define DX_GRAPH_BLEND_DODGE						(7)				// 覆い焼き
#define DX_GRAPH_BLEND_BURN							(8)				// 焼き込み
#define DX_GRAPH_BLEND_DARKEN						(9)				// 比較(暗)
#define DX_GRAPH_BLEND_LIGHTEN						(10)			// 比較(明)
#define DX_GRAPH_BLEND_SOFTLIGHT					(11)			// ソフトライト
#define DX_GRAPH_BLEND_HARDLIGHT					(12)			// ハードライト
#define DX_GRAPH_BLEND_EXCLUSION					(13)			// 除外
#define DX_GRAPH_BLEND_NORMAL_ALPHACH				(14)			// αチャンネル付き画像の通常合成
#define DX_GRAPH_BLEND_ADD_ALPHACH					(15)			// αチャンネル付き画像の加算合成
#define DX_GRAPH_BLEND_MULTIPLE_A_ONLY				(16)			// アルファチャンネルのみの乗算
#define DX_GRAPH_BLEND_NUM							(17)

// DX_GRAPH_BLEND_RGBA_SELECT_MIX 用の色選択用定義
#define DX_RGBA_SELECT_SRC_R						(0)				// 元画像の赤成分
#define DX_RGBA_SELECT_SRC_G						(1)				// 元画像の緑成分
#define DX_RGBA_SELECT_SRC_B						(2)				// 元画像の青成分
#define DX_RGBA_SELECT_SRC_A						(3)				// 元画像のα成分
#define DX_RGBA_SELECT_BLEND_R						(4)				// ブレンド画像の赤成分
#define DX_RGBA_SELECT_BLEND_G						(5)				// ブレンド画像の緑成分
#define DX_RGBA_SELECT_BLEND_B						(6)				// ブレンド画像の青成分
#define DX_RGBA_SELECT_BLEND_A						(7)				// ブレンド画像のα成分

// ポリゴンカリングモード
#define DX_CULLING_NONE								(0)				// カリングなし
#define DX_CULLING_LEFT								(1)				// 背面を左回りでカリング
#define DX_CULLING_RIGHT							(2)				// 背面を右回りでカリング

// クリッピング方向
#define DX_CAMERACLIP_LEFT							(0x01)			// 画面左方向にクリップ
#define DX_CAMERACLIP_RIGHT							(0x02)			// 画面右方向にクリップ
#define DX_CAMERACLIP_BOTTOM						(0x04)			// 画面下方向にクリップ
#define DX_CAMERACLIP_TOP							(0x08)			// 画面上方向にクリップ
#define DX_CAMERACLIP_BACK							(0x10)			// 画面後方向にクリップ
#define DX_CAMERACLIP_FRONT							(0x20)			// 画面前方向にクリップ

// MV1モデルの頂点タイプ
#define DX_MV1_VERTEX_TYPE_1FRAME					(0)				// １フレームの影響を受ける頂点
#define DX_MV1_VERTEX_TYPE_4FRAME					(1)				// １〜４フレームの影響を受ける頂点
#define DX_MV1_VERTEX_TYPE_8FRAME					(2)				// ５〜８フレームの影響を受ける頂点
#define DX_MV1_VERTEX_TYPE_FREE_FRAME				(3)				// ９フレーム以上の影響を受ける頂点
#define DX_MV1_VERTEX_TYPE_NMAP_1FRAME				(4)				// 法線マップ用の情報が含まれる１フレームの影響を受ける頂点
#define DX_MV1_VERTEX_TYPE_NMAP_4FRAME				(5)				// 法線マップ用の情報が含まれる１〜４フレームの影響を受ける頂点
#define DX_MV1_VERTEX_TYPE_NMAP_8FRAME				(6)				// 法線マップ用の情報が含まれる５〜８フレームの影響を受ける頂点
#define DX_MV1_VERTEX_TYPE_NMAP_FREE_FRAME			(7)				// 法線マップ用の情報が含まれる９フレーム以上の影響を受ける頂点
#define DX_MV1_VERTEX_TYPE_NUM						(8)				// 頂点タイプの数

// メッシュの種類
#define DX_MV1_MESHCATEGORY_NORMAL					(0)				// 普通のメッシュ
#define DX_MV1_MESHCATEGORY_OUTLINE					(1)				// 輪郭線描画用メッシュ
#define DX_MV1_MESHCATEGORY_OUTLINE_ORIG_SHADER		(2)				// 輪郭線描画用メッシュ( オリジナルシェーダーでの描画用 )
#define DX_MV1_MESHCATEGORY_NUM						(3)				// メッシュの種類の数

// MV1ファイルの保存タイプ
#define MV1_SAVETYPE_MESH							(0x0001)		// メッシュ情報のみ保存
#define MV1_SAVETYPE_ANIM							(0x0002)		// アニメーション情報のみ保存
#define MV1_SAVETYPE_NORMAL							( MV1_SAVETYPE_MESH | MV1_SAVETYPE_ANIM )	// 通常保存

// アニメーションキーデータタイプ
#define MV1_ANIMKEY_DATATYPE_ROTATE					(0)				// 回転
#define MV1_ANIMKEY_DATATYPE_ROTATE_X				(1)				// 回転Ｘ
#define MV1_ANIMKEY_DATATYPE_ROTATE_Y				(2)				// 回転Ｙ
#define MV1_ANIMKEY_DATATYPE_ROTATE_Z				(3)				// 回転Ｚ
#define MV1_ANIMKEY_DATATYPE_SCALE					(5)				// 拡大
#define MV1_ANIMKEY_DATATYPE_SCALE_X				(6)				// スケールＸ
#define MV1_ANIMKEY_DATATYPE_SCALE_Y				(7)				// スケールＹ
#define MV1_ANIMKEY_DATATYPE_SCALE_Z				(8)				// スケールＺ
#define MV1_ANIMKEY_DATATYPE_TRANSLATE				(10)			// 平行移動
#define MV1_ANIMKEY_DATATYPE_TRANSLATE_X			(11)			// 平行移動Ｘ
#define MV1_ANIMKEY_DATATYPE_TRANSLATE_Y			(12)			// 平行移動Ｙ
#define MV1_ANIMKEY_DATATYPE_TRANSLATE_Z			(13)			// 平行移動Ｚ
#define MV1_ANIMKEY_DATATYPE_MATRIX4X4C				(15)			// ４×４行列の４列目( 0,0,0,1 )固定版
#define MV1_ANIMKEY_DATATYPE_MATRIX3X3				(17)			// ３×３行列
#define MV1_ANIMKEY_DATATYPE_SHAPE					(18)			// シェイプ
#define MV1_ANIMKEY_DATATYPE_OTHRE					(20)			// その他

// タイムタイプ
#define MV1_ANIMKEY_TIME_TYPE_ONE					(0)				// 時間情報は全体で一つ
#define MV1_ANIMKEY_TIME_TYPE_KEY					(1)				// 時間情報は各キーに一つ

// アニメーションキータイプ
#define MV1_ANIMKEY_TYPE_QUATERNION_X				(0)				// クォータニオン( Xファイルタイプ )
#define MV1_ANIMKEY_TYPE_VECTOR						(1)				// ベクター
#define MV1_ANIMKEY_TYPE_MATRIX4X4C					(2)				// ４×４行列の４列目( 0,0,0,1 )固定版
#define MV1_ANIMKEY_TYPE_MATRIX3X3					(3)				// ３×３行列
#define MV1_ANIMKEY_TYPE_FLAT						(4)				// フラット
#define MV1_ANIMKEY_TYPE_LINEAR						(5)				// 線形補間
#define MV1_ANIMKEY_TYPE_BLEND						(6)				// 混合
#define MV1_ANIMKEY_TYPE_QUATERNION_VMD				(7)				// クォータニオン( VMDタイプ )

// 描画先画面指定用定義
#define DX_SCREEN_FRONT								(0xfffffffc)
#define DX_SCREEN_BACK								(0xfffffffe) 
#define DX_SCREEN_WORK 								(0xfffffffd)
#define DX_SCREEN_TEMPFRONT							(0xfffffffb)

#define DX_NONE_GRAPH								(0xfffffffb)	// グラフィックなしハンドル

// グラフィック減色時の画像劣化緩和処理モード
#define DX_SHAVEDMODE_NONE							(0)				// 画像劣化緩和処理を行わない
#define DX_SHAVEDMODE_DITHER						(1)				// ディザリング
#define DX_SHAVEDMODE_DIFFUS						(2)				// 誤差拡散

// 画像の保存タイプ
#define DX_IMAGESAVETYPE_BMP						(0)				// bitmap
#define DX_IMAGESAVETYPE_JPEG						(1)				// jpeg
#define DX_IMAGESAVETYPE_PNG						(2)				// Png

// サウンド再生形態指定用定義
#define DX_PLAYTYPE_LOOPBIT							(0x0002)		// ループ再生ビット
#define DX_PLAYTYPE_BACKBIT							(0x0001)		// バックグラウンド再生ビット

#define DX_PLAYTYPE_NORMAL							(0)												// ノーマル再生
#define DX_PLAYTYPE_BACK				  			( DX_PLAYTYPE_BACKBIT )							// バックグラウンド再生
#define DX_PLAYTYPE_LOOP							( DX_PLAYTYPE_LOOPBIT | DX_PLAYTYPE_BACKBIT )	// ループ再生

// 動画再生タイプ定義
#define DX_MOVIEPLAYTYPE_BCANCEL					(0)				// ボタンキャンセルあり
#define DX_MOVIEPLAYTYPE_NORMAL						(1)				// ボタンキャンセルなし

// サウンドのタイプ
#define DX_SOUNDTYPE_NORMAL							(0)				// ノーマルサウンド形式
#define DX_SOUNDTYPE_STREAMSTYLE					(1)				// ストリーム風サウンド形式

// サウンドデータタイプのマクロ
#define DX_SOUNDDATATYPE_MEMNOPRESS					(0)				// 圧縮された全データは再生が始まる前にサウンドメモリにすべて解凍され、格納される
#define DX_SOUNDDATATYPE_MEMNOPRESS_PLUS			(1)				// 圧縮された全データはシステムメモリに格納され、再生しながら逐次解凍され、最終的にすべてサウンドメモリに格納される(その後システムメモリに存在する圧縮データは破棄される)
#define DX_SOUNDDATATYPE_MEMPRESS					(2)				// 圧縮された全データはシステムメモリに格納され、再生する部分だけ逐次解凍しながらサウンドメモリに格納する(鳴らし終わると解凍したデータは破棄されるので何度も解凍処理が行われる)
#define DX_SOUNDDATATYPE_FILE						(3)				// 圧縮されたデータの再生する部分だけファイルから逐次読み込み解凍され、サウンドメモリに格納される(鳴らし終わると解凍したデータは破棄されるので何度も解凍処理が行われる)

// 読み込み処理のタイプ
#define DX_READSOUNDFUNCTION_PCM					(0x0001)		// PCM の読み込み処理
#define DX_READSOUNDFUNCTION_ACM					(0x0002)		// ACM を使用した読み込み処理
#define DX_READSOUNDFUNCTION_OGG					(0x0004)		// Ogg Vorbis の読み込み処理
#define DX_READSOUNDFUNCTION_MP3					(0x0008)		// ACM を使用した MP3 の読み込み処理
#define DX_READSOUNDFUNCTION_DSMP3					(0x0010)		// DirectShow を使用した MP3 の読み込み処理

// マスク透過色モード
#define DX_MASKTRANS_WHITE							(0)				// マスク画像の白い部分を透過色とする
#define DX_MASKTRANS_BLACK							(1)				// マスク画像の黒い部分を透過色とする
#define DX_MASKTRANS_NONE							(2) 			// 透過色なし

// Ｚバッファ書き込みモード
#define DX_ZWRITE_MASK								(0)				// 書き込めないようにマスクする
#define DX_ZWRITE_CLEAR								(1)				// 書き込めるようにマスクをクリアする

// 比較モード
#define DX_CMP_NEVER								(1)				// FALSE
#define DX_CMP_LESS									(2)				// Src <  Dest		DrawAlpha <  TestParam
#define DX_CMP_EQUAL								(3)				// Src == Dest		DrawAlpha == TestParam
#define DX_CMP_LESSEQUAL							(4)				// Src <= Dest		DrawAlpha <= TestParam
#define DX_CMP_GREATER								(5)				// Src >  Dest		DrawAlpha >  TestParam
#define DX_CMP_NOTEQUAL								(6)				// Src != Dest		DrawAlpha != TestParam
#define DX_CMP_GREATEREQUAL							(7)				// Src >= Dest		DrawAlpha >= TestParam
#define DX_CMP_ALWAYS								(8)				// TRUE
#define DX_ZCMP_DEFAULT								( DX_CMP_LESSEQUAL )
#define DX_ZCMP_REVERSE								( DX_CMP_GREATEREQUAL )

// シェーディングモード
#define DX_SHADEMODE_FLAT							D_D3DSHADE_FLAT
#define DX_SHADEMODE_GOURAUD						D_D3DSHADE_GOURAUD

// フォグモード
#define DX_FOGMODE_NONE								D_D3DFOG_NONE
#define DX_FOGMODE_EXP								D_D3DFOG_EXP
#define DX_FOGMODE_EXP2								D_D3DFOG_EXP2
#define DX_FOGMODE_LINEAR							D_D3DFOG_LINEAR

// マテリアルタイプ
#define DX_MATERIAL_TYPE_NORMAL						(0)				// 標準マテリアル
#define DX_MATERIAL_TYPE_TOON						(1)				// トゥーンレンダリング用マテリアル
#define DX_MATERIAL_TYPE_TOON_2						(2)				// トゥーンレンダリング用マテリアル_タイプ２( MMD互換 )

// マテリアルブレンドタイプ
#define DX_MATERIAL_BLENDTYPE_TRANSLUCENT			(0)				// アルファ合成
#define DX_MATERIAL_BLENDTYPE_ADDITIVE				(1)				// 加算
#define DX_MATERIAL_BLENDTYPE_MODULATE				(2)				// 乗算
#define DX_MATERIAL_BLENDTYPE_NONE					(3)				// 無効

// テクスチャアドレスタイプ
#define DX_TEXADDRESS_WRAP							D_D3DTADDRESS_WRAP
#define DX_TEXADDRESS_MIRROR						D_D3DTADDRESS_MIRROR
#define DX_TEXADDRESS_CLAMP							D_D3DTADDRESS_CLAMP
#define DX_TEXADDRESS_BORDER						D_D3DTADDRESS_BORDER

// 頂点データタイプ
#define DX_VERTEX_TYPE_NORMAL_3D					(0)				// VERTEX3D構造体形式
#define DX_VERTEX_TYPE_SHADER_3D					(1)				// VERTEX3DSHADER構造体形式
#define DX_VERTEX_TYPE_NUM							(2)

// インデックスデータタイプ
#define DX_INDEX_TYPE_16BIT							(0)				// 16bitインデックス

// モデルファイル読み込み時の物理演算モード
#define DX_LOADMODEL_PHYSICS_DISABLE				(1)				// 物理演算を使用しない
#define DX_LOADMODEL_PHYSICS_LOADCALC				(0)				// 読み込み時に計算
#define DX_LOADMODEL_PHYSICS_REALTIME				(2)				// 実行時計算

// ポリゴン描画タイプ
#define DX_PRIMTYPE_POINTLIST						D_D3DPT_POINTLIST
#define DX_PRIMTYPE_LINELIST						D_D3DPT_LINELIST
#define DX_PRIMTYPE_LINESTRIP						D_D3DPT_LINESTRIP
#define DX_PRIMTYPE_TRIANGLELIST					D_D3DPT_TRIANGLELIST
#define DX_PRIMTYPE_TRIANGLESTRIP					D_D3DPT_TRIANGLESTRIP
#define DX_PRIMTYPE_TRIANGLEFAN						D_D3DPT_TRIANGLEFAN

// ライトタイプ
#define DX_LIGHTTYPE_D3DLIGHT_POINT					D_D3DLIGHT_POINT
#define DX_LIGHTTYPE_D3DLIGHT_SPOT					D_D3DLIGHT_SPOT
#define DX_LIGHTTYPE_D3DLIGHT_DIRECTIONAL			D_D3DLIGHT_DIRECTIONAL
#define DX_LIGHTTYPE_D3DLIGHT_FORCEDWORD			D_D3DLIGHT_FORCE_DWORD
#define DX_LIGHTTYPE_POINT							D_D3DLIGHT_POINT
#define DX_LIGHTTYPE_SPOT							D_D3DLIGHT_SPOT
#define DX_LIGHTTYPE_DIRECTIONAL					D_D3DLIGHT_DIRECTIONAL

// グラフィックイメージフォーマットの定義
#define DX_GRAPHICSIMAGE_FORMAT_3D_RGB16					(0)		// １６ビットカラー標準
#define DX_GRAPHICSIMAGE_FORMAT_3D_RGB32					(1)		// ３２ビットカラー標準
#define DX_GRAPHICSIMAGE_FORMAT_3D_ALPHA_RGB16				(2)		// αチャンネル付き１６ビットカラー
#define DX_GRAPHICSIMAGE_FORMAT_3D_ALPHA_RGB32				(3)		// αチャンネル付き３２ビットカラー
#define DX_GRAPHICSIMAGE_FORMAT_3D_ALPHATEST_RGB16			(4)		// αテスト付き１６ビットカラー
#define DX_GRAPHICSIMAGE_FORMAT_3D_ALPHATEST_RGB32			(5)		// αテスト付き３２ビットカラー
#define DX_GRAPHICSIMAGE_FORMAT_3D_DXT1						(6)		// ＤＸＴ１
#define DX_GRAPHICSIMAGE_FORMAT_3D_DXT2						(7)		// ＤＸＴ２
#define DX_GRAPHICSIMAGE_FORMAT_3D_DXT3						(8)		// ＤＸＴ３
#define DX_GRAPHICSIMAGE_FORMAT_3D_DXT4						(9)		// ＤＸＴ４
#define DX_GRAPHICSIMAGE_FORMAT_3D_DXT5 					(10)	// ＤＸＴ５
#define DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_RGB16			(11)	// 描画可能１６ビットカラー
#define DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_RGB32			(12)	// 描画可能３２ビットカラー
#define DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_ALPHA_RGB32	(13)	// 描画可能α付き３２ビットカラー
#define DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_ABGR_I16		(14)	// 描画可能ARGB整数16ビット型カラー
#define DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_ABGR_F16		(15)	// 描画可能ARGB浮動小数点16ビット型カラー
#define DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_ABGR_F32		(16)	// 描画可能ARGB浮動小数点32ビット型カラー
#define DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_ONE_I8			(17)	// 描画可能１チャンネル整数8ビット型カラー
#define DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_ONE_I16		(18)	// 描画可能１チャンネル整数16ビット型カラー
#define DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_ONE_F16		(19)	// 描画可能１チャンネル浮動少数16ビット型カラー
#define DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_ONE_F32		(20)	// 描画可能１チャンネル浮動少数32ビット型カラー
#define DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_TWO_I8			(21)	// 描画可能２チャンネル整数8ビット型カラー
#define DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_TWO_I16		(22)	// 描画可能２チャンネル整数16ビット型カラー
#define DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_TWO_F16		(23)	// 描画可能２チャンネル浮動少数16ビット型カラー
#define DX_GRAPHICSIMAGE_FORMAT_3D_DRAWVALID_TWO_F32		(24)	// 描画可能２チャンネル浮動少数32ビット型カラー
#define DX_GRAPHICSIMAGE_FORMAT_3D_NUM						(25)
#define DX_GRAPHICSIMAGE_FORMAT_2D							(26)	// 標準( DirectDrawSurface の場合はこれのみ )
#define DX_GRAPHICSIMAGE_FORMAT_R5G6B5						(27)	// R5G6B5( MEMIMG 用 )
#define DX_GRAPHICSIMAGE_FORMAT_X8A8R5G6B5					(28)	// X8A8R5G6B5( MEMIMG 用 )
#define DX_GRAPHICSIMAGE_FORMAT_X8R8G8B8					(29)	// X8R8G8B8( MEMIMG 用 )
#define DX_GRAPHICSIMAGE_FORMAT_A8R8G8B8					(30)	// A8R8G8B8( MEMIMG 用 )

#define DX_GRAPHICSIMAGE_FORMAT_NUM							(31)	// グラフィックフォーマットの種類の数

// 基本イメージのピクセルフォーマット
#define DX_BASEIMAGE_FORMAT_NORMAL					(0)			// 普通の画像
#define DX_BASEIMAGE_FORMAT_DXT1					(1)			// ＤＸＴ１
#define DX_BASEIMAGE_FORMAT_DXT2					(2)			// ＤＸＴ２
#define DX_BASEIMAGE_FORMAT_DXT3					(3)			// ＤＸＴ３
#define DX_BASEIMAGE_FORMAT_DXT4					(4)			// ＤＸＴ４
#define DX_BASEIMAGE_FORMAT_DXT5					(5)			// ＤＸＴ５

// ツールバーのボタンの状態
#define TOOLBUTTON_STATE_ENABLE						(0)			// 入力可能な状態
#define TOOLBUTTON_STATE_PRESSED					(1)			// 押されている状態
#define TOOLBUTTON_STATE_DISABLE					(2)			// 入力不可能な状態
#define TOOLBUTTON_STATE_PRESSED_DISABLE			(3)			// 押されている状態で、入力不可能な状態
#define TOOLBUTTON_STATE_NUM						(4)			// ツールバーのボタンの状態の数

// ツールバーのボタンのタイプ
#define TOOLBUTTON_TYPE_NORMAL						(0)			// 普通のボタン
#define TOOLBUTTON_TYPE_CHECK						(1)			// 押すごとにＯＮ／ＯＦＦが切り替わるボタン
#define TOOLBUTTON_TYPE_GROUP						(2)			// 別の TOOLBUTTON_TYPE_GROUP タイプのボタンが押されるとＯＦＦになるタイプのボタン(グループの区切りは隙間で)
#define TOOLBUTTON_TYPE_SEP							(3)			// 隙間(ボタンではありません)
#define TOOLBUTTON_TYPE_NUM							(4)			// ツールバーのボタンのタイプの数

// 親メニューのＩＤ
#define MENUITEM_IDTOP								(0xabababab)

// メニューに追加する際のタイプ
#define MENUITEM_ADD_CHILD							(0)				// 指定の項目の子として追加する
#define MENUITEM_ADD_INSERT							(1)				// 指定の項目と指定の項目より一つ上の項目の間に追加する

// メニューの横に付くマークタイプ
#define MENUITEM_MARK_NONE							(0)				// 何も付け無い
#define MENUITEM_MARK_CHECK							(1)				// チェックマーク
#define MENUITEM_MARK_RADIO							(2)				// ラジオボタン

// 文字変換タイプ定義
#define DX_NUMMODE_10								(0)				// １０進数
#define DX_NUMMODE_16								(1)				// １６進数
#define DX_STRMODE_NOT0								(2)				// 空きを０で埋めない
#define DX_STRMODE_USE0								(3)				// 空きを０で埋める

// CheckHitKeyAll で調べる入力タイプ
#define DX_CHECKINPUT_KEY							(0x0001)		// キー入力を調べる
#define DX_CHECKINPUT_PAD							(0x0002)		// パッド入力を調べる
#define DX_CHECKINPUT_MOUSE							(0x0004)		// マウスボタン入力を調べる
#define DX_CHECKINPUT_ALL							(DX_CHECKINPUT_KEY | DX_CHECKINPUT_PAD | DX_CHECKINPUT_MOUSE)	// すべての入力を調べる

// パッド入力取得パラメータ
#define DX_INPUT_KEY_PAD1							(0x1001)		// キー入力とパッド１入力
#define DX_INPUT_PAD1								(0x0001)		// パッド１入力
#define DX_INPUT_PAD2								(0x0002)		// パッド２入力
#define DX_INPUT_PAD3								(0x0003)		// パッド３入力
#define DX_INPUT_PAD4								(0x0004)		// パッド４入力
#define DX_INPUT_PAD5								(0x0005)		// パッド５入力
#define DX_INPUT_PAD6								(0x0006)		// パッド６入力
#define DX_INPUT_PAD7								(0x0007)		// パッド７入力
#define DX_INPUT_PAD8								(0x0008)		// パッド８入力
#define DX_INPUT_PAD9								(0x0009)		// パッド９入力
#define DX_INPUT_PAD10								(0x000a)		// パッド１０入力
#define DX_INPUT_PAD11								(0x000b)		// パッド１１入力
#define DX_INPUT_PAD12								(0x000c)		// パッド１２入力
#define DX_INPUT_PAD13								(0x000d)		// パッド１３入力
#define DX_INPUT_PAD14								(0x000e)		// パッド１４入力
#define DX_INPUT_PAD15								(0x000f)		// パッド１５入力
#define DX_INPUT_PAD16								(0x0010)		// パッド１６入力
#define DX_INPUT_KEY								(0x1000)		// キー入力

// ムービーのサーフェスモード
#define DX_MOVIESURFACE_NORMAL						(0)
#define DX_MOVIESURFACE_OVERLAY						(1)
#define DX_MOVIESURFACE_FULLCOLOR					(2)

// パッド入力定義
#define PAD_INPUT_DOWN								(0x00000001)	// ↓チェックマスク
#define PAD_INPUT_LEFT								(0x00000002)	// ←チェックマスク
#define PAD_INPUT_RIGHT								(0x00000004)	// →チェックマスク
#define PAD_INPUT_UP								(0x00000008)	// ↑チェックマスク
#define PAD_INPUT_A									(0x00000010)	// Ａボタンチェックマスク
#define PAD_INPUT_B									(0x00000020)	// Ｂボタンチェックマスク
#define PAD_INPUT_C									(0x00000040)	// Ｃボタンチェックマスク
#define PAD_INPUT_X									(0x00000080)	// Ｘボタンチェックマスク
#define PAD_INPUT_Y									(0x00000100)	// Ｙボタンチェックマスク
#define PAD_INPUT_Z									(0x00000200)	// Ｚボタンチェックマスク
#define PAD_INPUT_L									(0x00000400)	// Ｌボタンチェックマスク
#define PAD_INPUT_R									(0x00000800)	// Ｒボタンチェックマスク
#define PAD_INPUT_START								(0x00001000)	// ＳＴＡＲＴボタンチェックマスク
#define PAD_INPUT_M									(0x00002000)	// Ｍボタンチェックマスク
#define PAD_INPUT_D									(0x00004000)
#define PAD_INPUT_F									(0x00008000)
#define PAD_INPUT_G									(0x00010000)
#define PAD_INPUT_H									(0x00020000)
#define PAD_INPUT_I									(0x00040000)
#define PAD_INPUT_J									(0x00080000)
#define PAD_INPUT_K									(0x00100000)
#define PAD_INPUT_LL								(0x00200000)
#define PAD_INPUT_N									(0x00400000)
#define PAD_INPUT_O									(0x00800000)
#define PAD_INPUT_P									(0x01000000)
#define PAD_INPUT_RR								(0x02000000)
#define PAD_INPUT_S									(0x04000000)
#define PAD_INPUT_T									(0x08000000)
#define PAD_INPUT_U									(0x10000000)
#define PAD_INPUT_V									(0x20000000)
#define PAD_INPUT_W									(0x40000000)
#define PAD_INPUT_XX								(0x80000000)

#define PAD_INPUT_1									(0x00000010)
#define PAD_INPUT_2									(0x00000020)
#define PAD_INPUT_3									(0x00000040)
#define PAD_INPUT_4									(0x00000080)
#define PAD_INPUT_5									(0x00000100)
#define PAD_INPUT_6									(0x00000200)
#define PAD_INPUT_7									(0x00000400)
#define PAD_INPUT_8									(0x00000800)
#define PAD_INPUT_9									(0x00001000)
#define PAD_INPUT_10								(0x00002000)
#define PAD_INPUT_11								(0x00004000)
#define PAD_INPUT_12								(0x00008000)
#define PAD_INPUT_13								(0x00010000)
#define PAD_INPUT_14								(0x00020000)
#define PAD_INPUT_15								(0x00040000)
#define PAD_INPUT_16								(0x00080000)
#define PAD_INPUT_17								(0x00100000)
#define PAD_INPUT_18								(0x00200000)
#define PAD_INPUT_19								(0x00400000)
#define PAD_INPUT_20								(0x00800000)
#define PAD_INPUT_21								(0x01000000)
#define PAD_INPUT_22								(0x02000000)
#define PAD_INPUT_23								(0x04000000)
#define PAD_INPUT_24								(0x08000000)
#define PAD_INPUT_25								(0x10000000)
#define PAD_INPUT_26								(0x20000000)
#define PAD_INPUT_27								(0x40000000)
#define PAD_INPUT_28								(0x80000000)

// マウス入力定義
#define MOUSE_INPUT_LEFT							(0x0001)			// マウス左ボタン
#define MOUSE_INPUT_RIGHT							(0x0002)			// マウス右ボタン
#define MOUSE_INPUT_MIDDLE							(0x0004)			// マウス中央ボタン
#define MOUSE_INPUT_1								(0x0001)			// マウス１ボタン
#define MOUSE_INPUT_2								(0x0002)			// マウス２ボタン
#define MOUSE_INPUT_3								(0x0004)			// マウス３ボタン
#define MOUSE_INPUT_4								(0x0008)			// マウス４ボタン
#define MOUSE_INPUT_5								(0x0010)			// マウス５ボタン
#define MOUSE_INPUT_6								(0x0020)			// マウス６ボタン
#define MOUSE_INPUT_7								(0x0040)			// マウス７ボタン
#define MOUSE_INPUT_8								(0x0080)			// マウス８ボタン

// キー定義
#define KEY_INPUT_BACK								D_DIK_BACK			// バックスペースキー
#define KEY_INPUT_TAB								D_DIK_TAB			// タブキー
#define KEY_INPUT_RETURN							D_DIK_RETURN		// エンターキー

#define KEY_INPUT_LSHIFT							D_DIK_LSHIFT		// 左シフトキー
#define KEY_INPUT_RSHIFT							D_DIK_RSHIFT		// 右シフトキー
#define KEY_INPUT_LCONTROL							D_DIK_LCONTROL		// 左コントロールキー
#define KEY_INPUT_RCONTROL							D_DIK_RCONTROL		// 右コントロールキー
#define KEY_INPUT_ESCAPE							D_DIK_ESCAPE		// エスケープキー
#define KEY_INPUT_SPACE								D_DIK_SPACE			// スペースキー
#define KEY_INPUT_PGUP								D_DIK_PGUP			// ＰａｇｅＵＰキー
#define KEY_INPUT_PGDN								D_DIK_PGDN			// ＰａｇｅＤｏｗｎキー
#define KEY_INPUT_END								D_DIK_END			// エンドキー
#define KEY_INPUT_HOME								D_DIK_HOME			// ホームキー
#define KEY_INPUT_LEFT								D_DIK_LEFT			// 左キー
#define KEY_INPUT_UP								D_DIK_UP			// 上キー
#define KEY_INPUT_RIGHT								D_DIK_RIGHT			// 右キー
#define KEY_INPUT_DOWN								D_DIK_DOWN			// 下キー
#define KEY_INPUT_INSERT							D_DIK_INSERT		// インサートキー
#define KEY_INPUT_DELETE							D_DIK_DELETE		// デリートキー

#define KEY_INPUT_MINUS								D_DIK_MINUS			// −キー
#define KEY_INPUT_YEN								D_DIK_YEN			// ￥キー
#define KEY_INPUT_PREVTRACK							D_DIK_PREVTRACK		// ＾キー
#define KEY_INPUT_PERIOD							D_DIK_PERIOD		// ．キー
#define KEY_INPUT_SLASH								D_DIK_SLASH			// ／キー
#define KEY_INPUT_LALT								D_DIK_LALT			// 左ＡＬＴキー
#define KEY_INPUT_RALT								D_DIK_RALT			// 右ＡＬＴキー
#define KEY_INPUT_SCROLL							D_DIK_SCROLL		// ScrollLockキー
#define KEY_INPUT_SEMICOLON							D_DIK_SEMICOLON		// ；キー
#define KEY_INPUT_COLON								D_DIK_COLON			// ：キー
#define KEY_INPUT_LBRACKET							D_DIK_LBRACKET		// ［キー
#define KEY_INPUT_RBRACKET							D_DIK_RBRACKET		// ］キー
#define KEY_INPUT_AT								D_DIK_AT			// ＠キー
#define KEY_INPUT_BACKSLASH							D_DIK_BACKSLASH		// ＼キー
#define KEY_INPUT_COMMA								D_DIK_COMMA			// ，キー
#define KEY_INPUT_KANJI								D_DIK_KANJI			// 漢字キー
#define KEY_INPUT_CONVERT							D_DIK_CONVERT		// 変換キー
#define KEY_INPUT_NOCONVERT							D_DIK_NOCONVERT		// 無変換キー
#define KEY_INPUT_KANA								D_DIK_KANA			// カナキー
#define KEY_INPUT_APPS								D_DIK_APPS			// アプリケーションメニューキー
#define KEY_INPUT_CAPSLOCK							D_DIK_CAPSLOCK		// CaspLockキー
#define KEY_INPUT_SYSRQ								D_DIK_SYSRQ			// PrintScreenキー
#define KEY_INPUT_PAUSE								D_DIK_PAUSE			// PauseBreakキー
#define KEY_INPUT_LWIN								D_DIK_LWIN			// 左Ｗｉｎキー
#define KEY_INPUT_RWIN								D_DIK_RWIN			// 右Ｗｉｎキー

#define KEY_INPUT_NUMLOCK							D_DIK_NUMLOCK		// テンキー０
#define KEY_INPUT_NUMPAD0							D_DIK_NUMPAD0		// テンキー０
#define KEY_INPUT_NUMPAD1							D_DIK_NUMPAD1		// テンキー１
#define KEY_INPUT_NUMPAD2							D_DIK_NUMPAD2		// テンキー２
#define KEY_INPUT_NUMPAD3							D_DIK_NUMPAD3		// テンキー３
#define KEY_INPUT_NUMPAD4							D_DIK_NUMPAD4		// テンキー４
#define KEY_INPUT_NUMPAD5							D_DIK_NUMPAD5		// テンキー５
#define KEY_INPUT_NUMPAD6							D_DIK_NUMPAD6		// テンキー６
#define KEY_INPUT_NUMPAD7							D_DIK_NUMPAD7		// テンキー７
#define KEY_INPUT_NUMPAD8							D_DIK_NUMPAD8		// テンキー８
#define KEY_INPUT_NUMPAD9							D_DIK_NUMPAD9		// テンキー９
#define KEY_INPUT_MULTIPLY							D_DIK_MULTIPLY		// テンキー＊キー
#define KEY_INPUT_ADD								D_DIK_ADD			// テンキー＋キー
#define KEY_INPUT_SUBTRACT							D_DIK_SUBTRACT		// テンキー−キー
#define KEY_INPUT_DECIMAL							D_DIK_DECIMAL		// テンキー．キー
#define KEY_INPUT_DIVIDE							D_DIK_DIVIDE		// テンキー／キー
#define KEY_INPUT_NUMPADENTER						D_DIK_NUMPADENTER	// テンキーのエンターキー

#define KEY_INPUT_F1								D_DIK_F1			// Ｆ１キー
#define KEY_INPUT_F2								D_DIK_F2			// Ｆ２キー
#define KEY_INPUT_F3								D_DIK_F3			// Ｆ３キー
#define KEY_INPUT_F4								D_DIK_F4			// Ｆ４キー
#define KEY_INPUT_F5								D_DIK_F5			// Ｆ５キー
#define KEY_INPUT_F6								D_DIK_F6			// Ｆ６キー
#define KEY_INPUT_F7								D_DIK_F7			// Ｆ７キー
#define KEY_INPUT_F8								D_DIK_F8			// Ｆ８キー
#define KEY_INPUT_F9								D_DIK_F9			// Ｆ９キー
#define KEY_INPUT_F10								D_DIK_F10			// Ｆ１０キー
#define KEY_INPUT_F11								D_DIK_F11			// Ｆ１１キー
#define KEY_INPUT_F12								D_DIK_F12			// Ｆ１２キー

#define KEY_INPUT_A									D_DIK_A			// Ａキー
#define KEY_INPUT_B									D_DIK_B			// Ｂキー
#define KEY_INPUT_C									D_DIK_C			// Ｃキー
#define KEY_INPUT_D									D_DIK_D			// Ｄキー
#define KEY_INPUT_E									D_DIK_E			// Ｅキー
#define KEY_INPUT_F									D_DIK_F			// Ｆキー
#define KEY_INPUT_G									D_DIK_G			// Ｇキー
#define KEY_INPUT_H									D_DIK_H			// Ｈキー
#define KEY_INPUT_I									D_DIK_I			// Ｉキー
#define KEY_INPUT_J									D_DIK_J			// Ｊキー
#define KEY_INPUT_K									D_DIK_K			// Ｋキー
#define KEY_INPUT_L									D_DIK_L			// Ｌキー
#define KEY_INPUT_M									D_DIK_M			// Ｍキー
#define KEY_INPUT_N									D_DIK_N			// Ｎキー
#define KEY_INPUT_O									D_DIK_O			// Ｏキー
#define KEY_INPUT_P									D_DIK_P			// Ｐキー
#define KEY_INPUT_Q									D_DIK_Q			// Ｑキー
#define KEY_INPUT_R									D_DIK_R			// Ｒキー
#define KEY_INPUT_S									D_DIK_S			// Ｓキー
#define KEY_INPUT_T									D_DIK_T			// Ｔキー
#define KEY_INPUT_U									D_DIK_U			// Ｕキー
#define KEY_INPUT_V									D_DIK_V			// Ｖキー
#define KEY_INPUT_W									D_DIK_W			// Ｗキー
#define KEY_INPUT_X									D_DIK_X			// Ｘキー
#define KEY_INPUT_Y									D_DIK_Y			// Ｙキー
#define KEY_INPUT_Z									D_DIK_Z			// Ｚキー

#define KEY_INPUT_0 								D_DIK_0			// ０キー
#define KEY_INPUT_1									D_DIK_1			// １キー
#define KEY_INPUT_2									D_DIK_2			// ２キー
#define KEY_INPUT_3									D_DIK_3			// ３キー
#define KEY_INPUT_4									D_DIK_4			// ４キー
#define KEY_INPUT_5									D_DIK_5			// ５キー
#define KEY_INPUT_6									D_DIK_6			// ６キー
#define KEY_INPUT_7									D_DIK_7			// ７キー
#define KEY_INPUT_8									D_DIK_8			// ８キー
#define KEY_INPUT_9									D_DIK_9			// ９キー

// アスキーコントロールキーコード
#define CTRL_CODE_BS								(0x08)				// バックスペース
#define CTRL_CODE_TAB								(0x09)				// タブ
#define CTRL_CODE_CR								(0x0d)				// 改行
#define CTRL_CODE_DEL								(0x10)				// ＤＥＬキー

#define CTRL_CODE_COPY								(0x03)				// コピー
#define CTRL_CODE_PASTE								(0x16)				// ペースト
#define CTRL_CODE_CUT								(0x18)				// カット
#define CTRL_CODE_ALL								(0x01)				// 全て選択

#define CTRL_CODE_LEFT								(0x1d)				// ←キー
#define CTRL_CODE_RIGHT								(0x1c)				// →キー
#define CTRL_CODE_UP								(0x1e)				// ↑キー
#define CTRL_CODE_DOWN								(0x1f)				// ↓キー

#define CTRL_CODE_HOME								(0x1a)				// ＨＯＭＥボタン
#define CTRL_CODE_END								(0x19)				// ＥＮＤボタン
#define CTRL_CODE_PAGE_UP							(0x17)				// ＰＡＧＥ ＵＰ
#define CTRL_CODE_PAGE_DOWN							(0x15)				// ＰＡＧＥ ＤＯＷＮ

#define CTRL_CODE_ESC								(0x1b)				// ＥＳＣキー
#define CTRL_CODE_CMP								(0x20)				// 制御コード敷居値

// SetGraphMode 戻り値定義
#define DX_CHANGESCREEN_OK							(0)					// 画面変更は成功した
#define DX_CHANGESCREEN_RETURN						(-1)				// 画面の変更は失敗し、元の画面モードに戻された
#define DX_CHANGESCREEN_DEFAULT						(-2)				// 画面の変更は失敗しデフォルトの画面モードに変更された
#define DX_CHANGESCREEN_REFRESHNORMAL				(-3)				// 画面の変更は成功したが、リフレッシュレートの変更は失敗した

// ストリームデータ読み込み処理コード簡略化関連
#define STTELL( st )								((st)->ReadShred.Tell( (st)->DataPoint ))
#define STSEEK( st, pos, type )						((st)->ReadShred.Seek( (st)->DataPoint, (pos), (type) ))
#define STREAD( buf, length, num, st )				((st)->ReadShred.Read( (buf), (length), (num), (st)->DataPoint ))
#define STWRITE( buf, length, num, st )				((st)->ReadShred.Write( (buf), (length), (num), (st)->DataPoint ))
#define STEOF( st )									((st)->ReadShred.Eof( (st)->DataPoint ))
#define STCLOSE( st )								((st)->ReadShred.Close( (st)->DataPoint ))

// ストリームデータ制御のシークタイプ定義
#define STREAM_SEEKTYPE_SET							(SEEK_SET)
#define STREAM_SEEKTYPE_END							(SEEK_END)
#define STREAM_SEEKTYPE_CUR							(SEEK_CUR)

// グラフィックロード時のイメージタイプ
#define LOADIMAGE_TYPE_FILE							(0)				// イメージはファイルである
#define LOADIMAGE_TYPE_MEM							(1)				// イメージはメモリである
#define LOADIMAGE_TYPE_NONE							(-1)			// イメージは無い



#ifndef DX_NON_NETWORK

// HTTP エラー
#define HTTP_ERR_SERVER								(0)				// サーバーエラー
#define HTTP_ERR_NOTFOUND							(1)				// ファイルが見つからなかった
#define HTTP_ERR_MEMORY								(2)				// メモリ確保の失敗
#define HTTP_ERR_LOST								(3)				// 途中で切断された
#define HTTP_ERR_NONE								(-1)			// エラーは報告されていない

// HTTP 処理の結果
#define HTTP_RES_COMPLETE							(0)				// 処理完了
#define HTTP_RES_STOP								(1)				// 処理中止
#define HTTP_RES_ERROR								(2)				// エラー終了
#define HTTP_RES_NOW								(-1)			// 現在進行中

#endif // DX_NON_NETWORK

#define DX_DEFINE_END

// データ型定義-------------------------------------------------------------------

namespace DxLib
{

#define DX_STRUCT_START

// ＩＭＥ入力文字列の描画に必要な情報の内の文節情報
typedef struct tagIMEINPUTCLAUSEDATA
{
	int						Position ;				// 何バイト目から
	int						Length ;				// 何バイトか
} IMEINPUTCLAUSEDATA, *LPIMEINPUTCLAUSEDATA ;

// ＩＭＥ入力文字列の描画に必要な情報
typedef struct tagIMEINPUTDATA
{
	const TCHAR *				InputString ;			// 入力中の文字列

	int							CursorPosition ;		// カーソルの入力文字列中の位置(バイト単位)

	const IMEINPUTCLAUSEDATA *	ClauseData ;			// 文節情報
	int							ClauseNum ;				// 文節情報の数
	int							SelectClause ;			// 選択中の分節( -1 の場合はどの文節にも属していない( 末尾にカーソルがある ) )

	int							CandidateNum ;			// 変換候補の数( 0の場合は変換中ではない )
	const TCHAR **				CandidateList ;			// 変換候補文字列リスト( 例：ｎ番目の候補を描画する場合  DrawString( 0, 0, data.CandidateList[ n ], GetColor(255,255,255) ); )
	int							SelectCandidate ;		// 選択中の変換候補

	int							ConvertFlag ;			// 文字変換中かどうか( TRUE:変換中  FALSE:変換中ではない( 文字単位でカーソルが移動できる状態 ) )
} IMEINPUTDATA, *LPIMEINPUTDATA ;

// 画面モード情報データ型
typedef struct tagDISPLAYMODEDATA
{
	int						Width ;				// 水平解像度
	int						Height ;			// 垂直解像度
	int						ColorBitDepth ;		// 色ビット深度
	int						RefreshRate ;		// リフレッシュレート( -1 の場合は規定値 )
} DISPLAYMODEDATA, *LPDISPLAYMODEDATA ;

// タイムデータ型
typedef struct tagDATEDATA
{
	int						Year ;							// 年
	int						Mon ;							// 月
	int						Day ;							// 日
	int						Hour ;							// 時間
	int						Min ;							// 分
	int						Sec ;							// 秒
} DATEDATA, *LPDATEDATA ;

// ファイル情報構造体
typedef struct tagFILEINFO
{
	TCHAR					Name[260] ;			// オブジェクト名
	int						DirFlag ;			// ディレクトリかどうか( TRUE:ディレクトリ  FALSE:ファイル )
	LONGLONG				Size ;				// サイズ
	DATEDATA				CreationTime ;		// 作成日時
	DATEDATA				LastWriteTime ;		// 最終更新日時
} FILEINFO, *LPFILEINFO ;

#ifndef DX_NOTUSE_DRAWFUNCTION

// 行列構造体
typedef struct tagMATRIX
{
	float					m[4][4] ;
} MATRIX, *LPMATRIX ;

// ベクトルデータ型
typedef struct tagVECTOR
{
	float					x, y, z ;
} VECTOR, *LPVECTOR, XYZ, *LPXYZ ;

// FLOAT2個データ型
typedef struct tagFLOAT2
{
	float					u, v ;
} UV ;

// float 型のカラー値
typedef struct tagCOLOR_F
{
	float					r, g, b, a ;
} COLOR_F, *LPCOLOR_F ;

// unsigned char 型のカラー値
typedef struct tagCOLOR_U8
{
	BYTE					b, g, r, a ;
} COLOR_U8 ;

// FLOAT4個データ型
typedef struct tagFLOAT4
{
	float					x, y, z, w ;
} FLOAT4, *LPFLOAT4 ;

// INT4個データ型
typedef struct tagINT4
{
	int						x, y, z, w ;
} INT4 ;

// ２Ｄ描画用頂点構造体(テクスチャ無し)
typedef struct tagVERTEX_NOTEX_2D
{
	VECTOR					pos ;
	float					rhw ;
	int						color ;
} VERTEX_NOTEX_2D, *LPVERTEX_NOTEX_2D ; 

// 主に２Ｄ描画に使用する頂点データ型
typedef struct tagVERTEX_2D
{
	VECTOR					pos ;
	float					rhw ;
	int						color ;
	float					u, v ;
} VERTEX_2D, *LPVERTEX_2D ; 

// ２Ｄ描画に使用する頂点データ型(DrawPrimitive2D用)
typedef struct tagVERTEX2D
{
	VECTOR					pos ;
	float					rhw ;
	COLOR_U8				dif ;
	float					u, v ;
} VERTEX2D, *LPVERTEX2D ; 

// ２Ｄ描画に使用する頂点データ型(DrawPrimitive2DToShader用)
typedef struct tagVERTEX2DSHADER
{
	VECTOR					pos ;
	float					rhw ;
	COLOR_U8				dif ;
	COLOR_U8				spc ;
	float					u, v ;
	float					su, sv ;
} VERTEX2DSHADER, *LPVERTEX2DSHADER ; 

// ２Ｄ描画に使用する頂点データ型(公開用)
typedef struct tagVERTEX
{
	float					x, y ;
	float					u, v ;
	unsigned char			b, g, r, a ;
} VERTEX ;

// ３Ｄ描画に使用する頂点データ型( テクスチャなし )( 旧バージョンのもの )
typedef struct tagVERTEX_NOTEX_3D
{
	VECTOR					pos ;
	unsigned char			b, g, r, a ;
} VERTEX_NOTEX_3D, *LPVERTEX_NOTEX_3D ;

// ３Ｄ描画に使用する頂点データ型( 旧バージョンのもの )
typedef struct tagVERTEX_3D
{
	VECTOR					pos ;
	unsigned char			b, g, r, a ;
	float					u, v ;
} VERTEX_3D, *LPVERTEX_3D ;

// ３Ｄ描画に使用する頂点データ型
typedef struct tagVERTEX3D
{
	VECTOR					pos ;						// 座標
	VECTOR					norm ;						// 法線
	COLOR_U8				dif ;						// ディフューズカラー
	COLOR_U8				spc ;						// スペキュラカラー
	float					u, v ;						// テクスチャ座標
	float					su, sv ;					// 補助テクスチャ座標
} VERTEX3D, *LPVERTEX3D ;

// ３Ｄ描画に使用する頂点データ型( DrawPrimitive3DToShader用 )
// 注意…メンバ変数に追加があるかもしれませんので、宣言時の初期化( VERTEX3DSHADER Vertex = { 0.0f, 0.0f, ... というようなもの )はしない方が良いです
typedef struct tagVERTEX3DSHADER
{
	VECTOR					pos ;						// 座標
	FLOAT4					spos ;						// 補助座標
	VECTOR					norm ;						// 法線
	VECTOR					tan ;						// 接線
	VECTOR					binorm ;					// 従法線
	COLOR_U8				dif ;						// ディフューズカラー
	COLOR_U8				spc ;						// スペキュラカラー
	float					u, v ;						// テクスチャ座標
	float					su, sv ;					// 補助テクスチャ座標
} VERTEX3DSHADER, *LPVERTEX3DSHADER ;

// ライトパラメータ
typedef struct tagLIGHTPARAM
{
	int						LightType ;					// ライトのタイプ( DX_LIGHTTYPE_D3DLIGHT_POINT 等 )
	COLOR_F					Diffuse ;					// ディフューズカラー
	COLOR_F					Specular ;					// スペキュラカラー
	COLOR_F					Ambient ;					// アンビエント色
	VECTOR					Position ;					// 位置
	VECTOR					Direction ;					// 方向
	float					Range ;						// 有効距離
	float					Falloff ;					// フォールオフ 1.0f にしておくのが好ましい
	float					Attenuation0 ;				// 距離による減衰係数０
	float					Attenuation1 ;				// 距離による減衰係数１
	float					Attenuation2 ;				// 距離による減衰係数２
	float					Theta ;						// スポットライトの内部コーンの照明角度( ラジアン )
	float					Phi ;						// スポットライトの外部コーンの照明角度
} LIGHTPARAM ;

// マテリアルパラメータ
typedef struct tagMATERIALPARAM
{
	COLOR_F					Diffuse ;					// ディフューズカラー
	COLOR_F					Ambient ;					// アンビエントカラー
	COLOR_F					Specular ;					// スペキュラカラー
	COLOR_F					Emissive ;					// エミッシブカラー
	float					Power ;						// スペキュラハイライトの鮮明度
} MATERIALPARAM ;

// ラインヒットチェック結果格納用構造体
typedef struct tagHITRESULT_LINE
{
	int						HitFlag ;					// 当たったかどうか( 1:当たった  0:当たらなかった )
	VECTOR					Position ;					// 当たった座標
} HITRESULT_LINE ;

// コリジョン結果代入用ポリゴン
typedef struct tagMV1_COLL_RESULT_POLY
{
	int						HitFlag ;							// ( MV1CollCheck_Line でのみ有効 )ヒットフラグ( 1:ヒットした  0:ヒットしなかった )
	VECTOR					HitPosition ;						// ( MV1CollCheck_Line でのみ有効 )ヒット座標

	int						FrameIndex ;						// 当たったポリゴンが含まれるフレームの番号
	int						PolygonIndex ;						// 当たったポリゴンの番号
	int						MaterialIndex ;						// 当たったポリゴンが使用しているマテリアルの番号
	VECTOR					Position[ 3 ] ;						// 当たったポリゴンを形成する三点の座標
	VECTOR					Normal ;							// 当たったポリゴンの法線
} MV1_COLL_RESULT_POLY ;

// コリジョン結果代入用ポリゴン配列
typedef struct tagMV1_COLL_RESULT_POLY_DIM
{
	int						HitNum ;							// ヒットしたポリゴンの数
	MV1_COLL_RESULT_POLY *	Dim ;								// ヒットしたポリゴンの配列( HitNum個分存在する )
} MV1_COLL_RESULT_POLY_DIM ;

// 参照用頂点構造体
typedef struct tagMV1_REF_VERTEX
{
	VECTOR					Position ;							// 位置
	VECTOR					Normal ;							// 法線
	UV						TexCoord[ 2 ] ;						// テクスチャ座標
	COLOR_U8				DiffuseColor ;						// ディフューズカラー
	COLOR_U8				SpecularColor ;						// スペキュラカラー
} MV1_REF_VERTEX ;

// 参照用ポリゴン構造体
typedef struct tagMV1_REF_POLYGON
{
	unsigned short			FrameIndex ;						// このポリゴンが属しているフレーム
	unsigned short			MaterialIndex ;						// 使用しているマテリアル
	int						VIndexTarget ;						// VIndex が指すインデックスの参照先( 1:フレーム  0:モデル全体 )
	int						VIndex[ 3 ] ;						// ３角形ポリゴンを成す参照頂点のインデックス
	VECTOR					MinPosition ;						// ポリゴンを成す頂点座標の最小値
	VECTOR					MaxPosition ;						// ポリゴンを成す頂点座標の最大値
} MV1_REF_POLYGON ;

// 参照用ポリゴンデータ構造体
typedef struct tagMV1_REF_POLYGONLIST
{
	int						PolygonNum ;						// 参照用ポリゴンの数
	int						VertexNum ;							// 頂点の数
	VECTOR					MinPosition ;						// 頂点座標の最小値
	VECTOR					MaxPosition ;						// 頂点座標の最大値
	MV1_REF_POLYGON	*		Polygons ;							// 参照用ポリゴン配列
	MV1_REF_VERTEX *		Vertexs ;							// 参照用頂点配列
} MV1_REF_POLYGONLIST ;

#endif // DX_NOTUSE_DRAWFUNCTION






// ストリームデータ制御用関数ポインタ構造体タイプ２
typedef struct tagSTREAMDATASHREDTYPE2
{
	DWORD_PTR				(*Open		)( const TCHAR *Path, int UseCacheFlag, int BlockReadFlag, int UseASyncReadFlag ) ;
	int						(*Close		)( DWORD_PTR Handle ) ;
	long					(*Tell		)( DWORD_PTR Handle ) ;
	int						(*Seek		)( DWORD_PTR Handle, long SeekPoint, int SeekType ) ;
	size_t					(*Read		)( void *Buffer, size_t BlockSize, size_t DataNum, DWORD_PTR Handle ) ;
	int						(*Eof		)( DWORD_PTR Handle ) ;
	int						(*IdleCheck	)( DWORD_PTR Handle ) ;
	int						(*ChDir		)( const TCHAR *Path ) ;
	int						(*GetDir	)( TCHAR *Buffer ) ;
	DWORD_PTR				(*FindFirst	)( const TCHAR *FilePath, FILEINFO *Buffer ) ;		// 戻り値: -1=エラー  -1以外=FindHandle
	int						(*FindNext	)( DWORD_PTR FindHandle, FILEINFO *Buffer ) ;			// 戻り値: -1=エラー  0=成功
	int						(*FindClose	)( DWORD_PTR FindHandle ) ;							// 戻り値: -1=エラー  0=成功
} STREAMDATASHREDTYPE2 ;

// ストリームデータ制御用関数ポインタ構造体
typedef struct tagSTREAMDATASHRED
{
	long					(*Tell		)( void *StreamDataPoint ) ;
	int						(*Seek		)( void *StreamDataPoint, long SeekPoint, int SeekType ) ;
	size_t					(*Read		)( void *Buffer, size_t BlockSize, size_t DataNum, void *StreamDataPoint ) ;
//	size_t					(*Write		)( void *Buffer, size_t BlockSize, size_t DataNum, void *StreamDataPoint ) ;
	int						(*Eof		)( void *StreamDataPoint ) ;
	int						(*IdleCheck	)( void *StreamDataPoint ) ;
	int						(*Close		)( void *StreamDataPoint ) ;
} STREAMDATASHRED, *LPSTREAMDATASHRED ;

// ストリームデータ制御用データ構造体
typedef struct tagSTREAMDATA
{
	STREAMDATASHRED			ReadShred ;
	void					*DataPoint ;
} STREAMDATA ;




#ifndef DX_NOTUSE_DRAWFUNCTION

// パレット情報構造体
typedef struct tagCOLORPALETTEDATA
{
	unsigned char			Blue ;
	unsigned char			Green ;
	unsigned char			Red ;
	unsigned char			Alpha ;
} COLORPALETTEDATA ;

// カラー構造情報構造体
typedef struct tagCOLORDATA
{
	unsigned char			Format ;										// フォーマット( DX_BASEIMAGE_FORMAT_NORMAL 等 )

	unsigned char			ChannelNum ;									// チャンネル数
	unsigned char			ChannelBitDepth ;								// １チャンネル辺りのビット深度
	unsigned char			FloatTypeFlag ;									// 浮動小数点型かどうか( TRUE:浮動小数点型  FALSE:整数型 )
	unsigned char			PixelByte ;										// １ピクセルあたりのバイト数

	// 以下は ChannelNum 又は ChannelBitDepth が 0 の時のみ有効
	unsigned char			ColorBitDepth ;									// ビット深度
	unsigned char			NoneLoc, NoneWidth ;							// 使われていないビットのアドレスと幅
	unsigned char			RedWidth, GreenWidth, BlueWidth, AlphaWidth ;	// 各色のビット幅
	unsigned char			RedLoc	, GreenLoc  , BlueLoc  , AlphaLoc   ;	// 各色の配置されているビットアドレス
	unsigned int			RedMask , GreenMask , BlueMask , AlphaMask  ;	// 各色のビットマスク
	unsigned int			NoneMask ;										// 使われていないビットのマスク
	COLORPALETTEDATA		Palette[ 256 ] ;								// パレット( ColorBitDepth が８以下の場合のみ有効 )
} COLORDATA, *LPCOLORDATA ;

// 基本イメージデータ構造体
typedef struct tagBASEIMAGE
{
	COLORDATA				ColorData ;							// 色情報
	int						Width, Height, Pitch ;				// 幅、高さ、ピッチ
	void					*GraphData ;						// グラフィックイメージ
	int						MipMapCount ;						// ミップマップの数
} BASEIMAGE, GRAPHIMAGE, *LPGRAPHIMAGE ;

// ラインデータ型
typedef struct tagLINEDATA
{
	int						x1, y1, x2, y2 ;					// 座標
	int						color ;								// 色
	int						pal ;								// パラメータ
} LINEDATA, *LPLINEDATA ;

// 座標データ型
typedef struct tagPOINTDATA
{
	int						x, y ;								// 座標
	int						color ;								// 色
	int						pal ;								// パラメータ
} POINTDATA, *LPPOINTDATA ;

// イメージフォーマットデータ
typedef struct tagIMAGEFORMATDESC
{
	unsigned char			TextureFlag ;					// テクスチャか、フラグ( TRUE:テクスチャ  FALSE:標準サーフェス )
	unsigned char			AlphaChFlag ;					// αチャンネルはあるか、フラグ	( TRUE:ある  FALSE:ない )
	unsigned char			DrawValidFlag ;					// 描画可能か、フラグ( TRUE:可能  FALSE:不可能 )
	unsigned char			SystemMemFlag ;					// システムメモリ上に存在しているか、フラグ( TRUE:システムメモリ上  FALSE:ＶＲＡＭ上 )( 標準サーフェスの時のみ有効 )
	unsigned char			UseManagedTextureFlag ;			// マネージドテクスチャを使用するか、フラグ

	unsigned char			BaseFormat ;					// 基本フォーマット( DX_BASEIMAGE_FORMAT_NORMAL 等 )
	unsigned char			MipMapCount ;					// ミップマップの数
	unsigned char			AlphaTestFlag ;					// αテストチャンネルはあるか、フラグ( TRUE:ある  FALSE:ない )( テクスチャの場合のみ有効 )
	unsigned char			FloatTypeFlag ;					// 浮動小数点型かどうか
	unsigned char			ColorBitDepth ;					// 色深度( テクスチャの場合のみ有効 )
	unsigned char			ChannelNum ;					// チャンネルの数
	unsigned char			ChannelBitDepth ;				// １チャンネル辺りのビット深度( テクスチャの場合のみ有効、0 の場合は ColorBitDepth が使用される )
	unsigned char			BlendGraphFlag ;				// ブレンド用画像か、フラグ
	unsigned char			UsePaletteFlag ;				// パレットを使用しているか、フラグ( SystemMemFlag が TRUE の場合のみ有効 )

	unsigned char			MSSamples ;						// マルチサンプリング数( 描画対象の場合使用 )
	unsigned char			MSQuality ;						// マルチサンプリングクオリティ( 描画対象の場合使用 )
} IMAGEFORMATDESC ;

#endif // DX_NOTUSE_DRAWFUNCTION

// DirectInput のジョイパッド入力情報
typedef struct tagDINPUT_JOYSTATE
{
	int						X ;								// スティックのＸ軸パラメータ( -1000〜1000 )
	int						Y ;								// スティックのＹ軸パラメータ( -1000〜1000 )
	int						Z ;								// スティックのＺ軸パラメータ( -1000〜1000 )
	int						Rx ;							// スティックのＸ軸回転パラメータ( -1000〜1000 )
	int						Ry ;							// スティックのＹ軸回転パラメータ( -1000〜1000 )
	int						Rz ;							// スティックのＺ軸回転パラメータ( -1000〜1000 )
	int						Slider[ 2 ] ;					// スライダー二つ
	unsigned int			POV[ 4 ] ;						// ハットスイッチ４つ( -1:入力なし 0:上 4500:右上 9000:右 13500:右下 18000:下 22500:左下 27000:左 31500:左上 )
	unsigned char			Buttons[ 32 ] ;					// ボタン３２個( 押されたボタンは 128 になる )
} DINPUT_JOYSTATE ;







// WinSockets使用時のアドレス指定用構造体
typedef struct tagIPDATA
{
	unsigned char			d1, d2, d3, d4 ;				// アドレス値
} IPDATA, *LPIPDATA ;

typedef struct tagIPDATA_IPv6
{
	union
	{
		unsigned char			Byte[ 16 ] ;
		unsigned short			Word[ 8 ] ;
	} ;
} IPDATA_IPv6 ;

#define DX_STRUCT_END

}

// 関数プロトタイプ宣言------------------------------------------------------------------

namespace DxLib
{

#define DX_FUNCTION_START

// DxSystem.cpp関数プロトタイプ宣言

// 初期化終了系関数
extern	int			DxLib_Init( void ) ;													// ライブラリ初期化を行う
extern	int			DxLib_End( void ) ;														// ライブラリ使用の後始末を行う

extern	int			DxLib_GlobalStructInitialize( void ) ;									// ライブラリの内部で使用している構造体をゼロ初期化して、DxLib_Init の前に行った設定を無効化する( DxLib_Init の前でのみ有効 )
extern	int			DxLib_IsInit( void ) ;													// ライブラリが初期化されているかどうかを取得する( 戻り値: TRUE=初期化されている  FALSE=されていない )

// メッセージ処理関数
extern	int			ProcessMessage( void ) ;												// ウインドウズのメッセージループに代わる処理を行う

// ウエイト系関数
extern	int			WaitTimer( int WaitTime ) ;												// 指定の時間だけ処理をとめる
#ifndef DX_NON_INPUT
extern	int			WaitKey( void ) ;														// キーの入力待ちを行う
#endif // DX_NON_INPUT

// カウンタ及び時刻取得系関数
extern	int			GetNowCount(				int UseRDTSCFlag = FALSE ) ;				// ミリ秒単位の精度を持つカウンタの現在値を得る
extern	LONGLONG	GetNowHiPerformanceCount(	int UseRDTSCFlag = FALSE ) ;				// GetNowCountの高精度バージョン
extern	int			GetDateTime(				DATEDATA *DateBuf ) ;						// 現在時刻を取得する 

// 乱数取得
extern	int			GetRand( int RandMax ) ;												// 乱数を取得する( RandMax : 返って来る値の最大値 )
extern	int			SRand(	 int Seed ) ;													// 乱数の初期値を設定する








// DxLog.cpp関数プロトタイプ宣言

#ifndef DX_NON_LOG
// エラー処理関数
extern	int			ErrorLogAdd(		 const TCHAR *ErrorStr ) ;							// ログファイル( Log.txt ) に文字列を出力する
extern 	int			ErrorLogFmtAdd(		 const TCHAR *FormatString , ... ) ;				// 書式付きで ログファイル( Log.txt ) に文字列を出力する( 書式は printf と同じ )
extern	int			ErrorLogTabAdd(		 void ) ;											// ログファイル( Log.txt ) に出力する文字列の前に付けるタブの数を一つ増やす
extern	int			ErrorLogTabSub(		 void ) ;											// ログファイル( Log.txt ) に出力する文字列の前に付けるタブの数を一つ減らす
extern	int			SetUseTimeStampFlag( int UseFlag ) ;									// ログファイル( Log.txt ) に出力する文字列の前に起動してからの時間を付けるかどうかを設定する( TRUE:付ける( デフォルト)  FALSE:付けない )
extern 	int			AppLogAdd(			 const TCHAR *String , ... ) ;						// ErrorLogFmtAdd と同じ機能

#ifndef DX_NON_PRINTF_DX

// ログ出力機能関数
extern	int			SetLogDrawOutFlag(	 int DrawFlag ) ;									// printfDx の結果を画面に出力するかどうかを設定する、TRUE:出力を行う  FALSE:出力を行わない( printfDx を実行すると内部で SetLogDrawOutFlag( TRUE ) ; が呼ばれます )
extern 	int			GetLogDrawFlag(		 void ) ;											// printfDx の結果を画面に出力するかどうかの設定を取得する( 戻り値  TRUE:出力を行う  FALSE:出力を行わない )
extern	int			SetLogFontSize(		 int Size ) ;										// printfDx の結果を画面に出力する際に使用するフォントのサイズを設定する

// 簡易画面出力関数
extern 	int			printfDx(			 const TCHAR *FormatString , ... ) ;				// printf と同じ引数で画面に文字列を表示するための関数
extern	int			clsDx(				 void ) ;											// printfDx の結果をリセットするための関数
#endif // DX_NON_PRINTF_DX

#endif // DX_NON_LOG












#ifndef DX_NON_ASYNCLOAD

// DxASyncLoad.cpp関数プロトタイプ宣言

// 非同期読み込み関係
extern	int			SetUseASyncLoadFlag(		int Flag ) ;								// 読み込み処理系の関数で非同期読み込みを行うかどうかを設定する( 非同期読み込みに対応している関数のみ有効 )( TRUE:非同期読み込みを行う  FALSE:非同期読み込みを行わない( デフォルト ) )
extern	int			CheckHandleASyncLoad(		int Handle ) ;								// ハンドルの非同期読み込みが完了しているかどうかを取得する( TRUE:まだ完了していない  FALSE:完了している  -1:エラー )
extern	int			GetHandleASyncLoadResult(	int Handle ) ;								// ハンドルの非同期読み込み処理の戻り値を取得する( 非同期読み込み中の場合は一つ前の非同期読み込み処理の戻り値が返ってきます )
extern	int			GetASyncLoadNum(			void ) ;									// 非同期読み込み中の処理の数を取得する

#endif // DX_NON_ASYNCLOAD











// DxHandle.cpp関数プロトタイプ宣言

extern	int			SetDeleteHandleFlag(		int Handle, int *DeleteFlag ) ;				// ハンドルが削除されたときに−１が設定される変数を登録する














// DxWindow.cpp関数プロトタイプ宣言

#ifdef __WINDOWS__

// 便利関数
extern	int			GetResourceInfo(		const TCHAR *ResourceName , const TCHAR *ResourceType , void **DataPointerP , int *DataSizeP ) ;		// 指定の名前、タイプのリソースのアドレスとサイズを取得する( 戻り値  -1:失敗  0:成功 )
extern	TCHAR*		GetResourceIDString(	int ResourceID ) ;																						// リソースＩＤ値からリソース名を取得する

// ウインドウ関係情報取得関数
extern	int			GetWindowCRect(					RECT *RectBuf ) ;										// メインウインドウのクライアント領域を取得する
extern	int			GetWindowActiveFlag(			void ) ;												// メインウインドウがアクティブかどうかを取得する( 戻り値  TRUE:アクティブ  FALSE:非アクティブ )
extern	int			GetActiveFlag(					void ) ;												// GetWindowActiveFlag の別名関数
extern	HWND		GetMainWindowHandle(			void ) ;												// メインウインドウのウインドウハンドルを取得する
extern	int			GetWindowModeFlag(				void ) ;												// ウインドウモードで起動しているかどうかを取得する( 戻り値  TRUE:ウインドウモード  FALSE:フルスクリーンモード )
extern	int			GetDefaultState(				int *SizeX , int *SizeY , int *ColorBitDepth ) ;		// 起動時のデスクトップの画面情報を取得する( SizeX:デスクトップの横解像度を格納する変数のポインタ  SizeY:縦解像度を格納する変数のポインタ  ColorBitDepth:画面カラービット数を格納する変数のポインタ )
extern	int			GetNoActiveState(				int ResetFlag = TRUE ) ;								// メインウインドウが非アクティブになり、処理が一時停止していたかどうかを取得する(引数 ResetFlag=TRUE:状態をリセット FALSE:状態をリセットしない    戻り値: 0=一時停止はしていない  1=一時停止していた )
extern	int			GetMouseDispFlag(				void ) ;												// マウスポインタを表示するかどうかの設定を取得する( 戻り値  TRUE:表示する  FALSE:表示しない )
extern	int			GetAlwaysRunFlag(				void ) ;												// メインウインドウが非アクティブになっても処理を実行し続けるかどうかの設定を取得する( TRUE:実行する  FALSE:停止する )
extern	int			_GetSystemInfo(					int *DxLibVer , int *DirectXVer , int *WindowsVer ) ;	// ＤＸライブラリと DirectX のバージョンと Windows のバージョン番号を取得する
extern	int			GetPcInfo(						TCHAR *OSString , TCHAR *DirectXString , TCHAR *CPUString , int *CPUSpeed /* 単位MHz */ , double *FreeMemorySize /* 単位MByte */ , double *TotalMemorySize , TCHAR *VideoDriverFileName , TCHAR *VideoDriverString , double *FreeVideoMemorySize /* 単位MByte */ , double *TotalVideoMemorySize ) ;	// ＰＣの情報を取得する
extern	int			GetUseMMXFlag(					void ) ;												// ＭＭＸが使えるかどうかの情報を得る
extern	int			GetUseSSEFlag(					void ) ;												// ＳＳＥが使えるかどうかの情報を得る
extern	int			GetUseSSE2Flag(					void ) ;												// ＳＳＥ２が使えるかどうかの情報を得る
extern	int			GetWindowCloseFlag(				void ) ;												// ウインドウを閉じようとしているかの情報を得る
extern	HINSTANCE	GetTaskInstance(				void ) ;												// ソフトのインスタンスを取得する
extern	int			GetUseWindowRgnFlag(			void ) ;												// リージョンを使っているかどうかを取得する
extern	int			GetWindowSizeChangeEnableFlag(	int *FitScreen = NULL ) ;								// ウインドウのサイズを変更できる設定になっているかどうかを取得する( 戻り値  TRUE:変更できるようになっている  FALSE:変更できないようになっている )
extern	double		GetWindowSizeExtendRate(		double *ExRateX = NULL , double *ExRateY = NULL ) ;		// 描画画面のサイズに対するウインドウサイズの比率を取得する( 戻り値は ExRateX に代入される値と同じです )
extern	int			GetWindowSize(					int *Width, int *Height ) ;								// メインウインドウのクライアント領域のサイズを取得する
extern	int			GetWindowPosition(				int *x, int *y ) ;										// メインウインドウのデスクトップ上の左上端座標を取得する( 枠も含める )
extern	int			GetWindowUserCloseFlag(			int StateResetFlag = FALSE ) ;							// メインウインドウの閉じるボタンが押されたかどうかを取得する
extern	int			GetNotDrawFlag(					void ) ;												// ＤＸライブラリの描画機能を使うかどうかの設定を取得する
extern	int			GetPaintMessageFlag(			void ) ;												// WM_PAINT メッセージが来たかどうかを取得する(戻り値  TRUE:WM_PAINTメッセージが来た(一度取得すると以後、再び WM_PAINTメッセージが来るまで FALSE が返ってくるようになる)  FALSE:WM_PAINT メッセージは来ていない)
extern	int			GetValidHiPerformanceCounter(	void ) ;												// パフォーマンスカウンタが有効かどうかを取得する(戻り値  TRUE:有効  FALSE:無効)

// 設定系関数
extern	int			ChangeWindowMode(						int Flag ) ;																		// ウインドウモードを変更する
extern	int			SetUseCharSet(							int CharSet /* = DX_CHARSET_SHFTJIS 等 */ ) ;										// ＤＸライブラリの文字列処理で前提とする文字列セットを設定する
extern	int			LoadPauseGraph(							const TCHAR *FileName ) ;															// アクティブウインドウが他のソフトに移っている際に表示する画像をファイルから読み込む( FileName に NULL を渡すことで解除)
extern	int			LoadPauseGraphFromMem(					void *MemImage , int MemImageSize ) ;												// アクティブウインドウが他のソフトに移っている際に表示する画像をメモリから読み込む( MemImage:ファイルイメージの先頭アドレス,NULL にすることで設定解除  MemImageSize:ファイルイメージのサイズ( 単位:Byte ) )
extern	int			SetActiveStateChangeCallBackFunction(	int (* CallBackFunction )( int ActiveState , void *UserData ) , void *UserData ) ;	// メインウインドウのアクティブ状態に変化があったときに呼ばれるコールバック関数を設定する( CallBackFunction:呼ばれるコールバック関数、NULL を渡すと設定解除  UserData:CallBackFunction の第２引数に渡される値 )
extern	int			SetWindowText(							const TCHAR *WindowText ) ;															// メインウインドウのウインドウテキストを変更する
extern	int			SetMainWindowText(						const TCHAR *WindowText ) ;															// SetWindowText の別名関数
extern	int			SetMainWindowClassName(					const TCHAR *ClassName ) ;															// メインウインドウのクラス名を設定する( DxLib_Init の前でのみ使用可能 )
#ifndef DX_NON_LOG
extern	int			SetOutApplicationLogValidFlag(			int Flag ) ;																		// ログファイル( Log.txt ) を作成するかどうかを設定する( TRUE:作成する( デフォルト )  FALSE:作成しない )、DxLib_Init の前でのみ使用可能
extern	int			SetApplicationLogSaveDirectory(			const TCHAR *DirectoryPath ) ;														// ログファイル( Log.txt ) を保存するディレクトリパスを設定する
extern	int			SetUseDateNameLogFile(					int Flag ) ;																		// ログファイル名に日付をつけるかどうかをセットする( TRUE:付ける  FALSE:付けない( デフォルト ) )
#endif // DX_NON_LOG
extern	int			SetAlwaysRunFlag(						int Flag ) ;																		// メインウインドウが非アクティブ状態でも処理を実行するかどうかを設定する( TRUE:実行する  FALSE:停止する( デフォルト ) )
extern	int			SetWindowIconID(						int ID ) ;																			// メインウインドウで使用するアイコンのＩＤをセットする
extern	int			SetWindowIconHandle(					HICON Icon ) ;																		// メインウインドウで使用するアイコンのハンドルをセットする
extern	int			SetUseASyncChangeWindowModeFunction(	int Flag , void (* CallBackFunction )( void * ) , void *Data ) ;					// 最大化ボタンやALT+ENTERキーによる非同期なウインドウモードの変更の機能の設定を行う( Flag:非同期ウインドウモード変更を有効にするかどうかのフラグ( TRUE:有効にする  FALSE:無効にする( デフォルト ) )   CallBackFunction:非同期ウインドウモード変更が行われた場合に呼ばれるコールバック関数のアドレス   Data:CallBackFunction の引数に渡される void 型のポインタ )
extern	int			SetWindowStyleMode(						int Mode ) ;																		// メインウインドウのスタイルを変更する
extern	int			SetWindowSizeChangeEnableFlag(			int Flag, int FitScreen = TRUE ) ;													// メインウインドウの端を掴んでウインドウのサイズを変更できるようにするかどうかの設定を行う( Flag:変更を可能にするかどうか( TRUE:可能にする  FALSE:不可能にする( デフォルト ) )  FitScreen:ウインドウのクライアント領域に画面をフィットさせる(拡大させる)かどうか  TRUE:フィットさせる  FALSE:フィットさせない )
extern	int			SetWindowSizeExtendRate(				double ExRateX, double ExRateY = -1.0 ) ;											// 描画画面のサイズに対するメインウインドウサイズの比率を設定する( ExRateY がマイナスの場合は ExRateX の値が ExRateY にも使用されます )
extern	int			SetWindowSize(							int Width, int Height ) ;															// メインウインドウのクライアント領域のサイズを設定する
extern	int			SetWindowPosition(						int x, int y ) ;																	// メインウインドウの位置を設定する( 枠も含めた左上座標 )
extern	int			SetSysCommandOffFlag(					int Flag , const TCHAR *HookDllPath = NULL ) ;										// タスクスイッチを有効にするかどうかを設定する
extern	int			SetHookWinProc(							WNDPROC WinProc ) ;																	// メインウインドウへのメッセージをフックするウインドウプロージャを登録する
extern	int			SetUseHookWinProcReturnValue(			int UseFlag ) ;																		// SetHookWinProc で設定したウインドウプロージャの戻り値を使用するかどうかを設定する、SetHookWinProc で設定したウインドウプロージャの中でのみ使用可能( UseFlag TRUE:戻り値を使用して、ＤＸライブラリのウインドウプロージャの処理は行わない  FALSE:戻り値は使用せず、ウインドウプロージャから出た後、ＤＸライブラリのウインドウプロージャの処理を行う )
extern	int			SetDoubleStartValidFlag(				int Flag ) ;																		// ＤＸライブラリを使用したソフトの二重起動を可能にするかどうかの設定を行う( TRUE:可能にする  FALSE:不可能にする( デフォルト ) )
extern	int			AddMessageTakeOverWindow(				HWND Window ) ;																		// メッセージ処理をＤＸライブラリに肩代わりしてもらうウインドウを追加する
extern	int			SubMessageTakeOverWindow(				HWND Window ) ;																		// メッセージ処理をＤＸライブラリに肩代わりしてもらうウインドウを減らす

extern	int			SetWindowInitPosition(					int x , int y ) ;																	// メインウインドウの初期位置を設定する
extern	int			SetNotWinFlag(							int Flag ) ;																		// ＤＸライブラリのウインドウ関連の機能を使用しないかどうかを設定する( TRUE:使用しない  FALSE:使用する( デフォルト ) )
extern	int			SetNotDrawFlag(							int Flag ) ;																		// ＤＸライブラリの描画機能を使うかどうかを設定する( TRUE:使用しない  FALSE:使用する( デフォルト ) )
extern	int			SetNotSoundFlag(						int Flag ) ;																		// ＤＸライブラリのサウンド機能を使うかどうかを設定する( TRUE:使用しない  FALSE:使用する( デフォルト ) )
extern	int			SetNotInputFlag(						int Flag ) ;																		// ＤＸライブラリの入力状態の取得機能を使うかどうかを設定する( TRUE:使用しない  FALSE:使用する( デフォルト ) )
extern	int			SetDialogBoxHandle(						HWND WindowHandle ) ;																// ＤＸライブラリでメッセージ処理を行うダイアログボックスを登録する
extern	int			SetWindowVisibleFlag(					int Flag ) ;																		// メインウインドウを表示するかどうかを設定する( TRUE:表示する  FALSE:表示しない )
extern	int			SetWindowMinimizeFlag(					int Flag ) ;																		// メインウインドウを最小化するかどうかを設定する( TRUE:最小化する  FALSE:最小化を解除 )
extern	int			SetWindowUserCloseEnableFlag(			int Flag ) ;																		// メインウインドウの×ボタンを押した時にＤＸライブラリが自動的にウインドウを閉じるかどうかを設定する( TRUE:自動的に閉じる( デフォルト )  FALSE:閉じない )
extern	int			SetDxLibEndPostQuitMessageFlag(			int Flag ) ;																		// ＤＸライブラリ終了時に PostQuitMessage を呼ぶかどうかを設定する( TRUE:PostQuitMessage を呼ぶ( デフォルト )  FALSE:呼ばない )
extern	int			SetUserWindow(							HWND WindowHandle ) ;																// ＤＸライブラリで使用するウインドウのハンドルをセットする( DxLib_Init を実行する以前でのみ有効 )
extern	int			SetUserChildWindow(						HWND WindowHandle ) ;																// ＤＸライブラリで使用する表示用の子ウインドウのハンドルをセットする( DxLib_Init を実行する以前でのみ有効 )
extern	int			SetUserWindowMessageProcessDXLibFlag(	int Flag ) ;																		// SetUseWindow で設定したウインドウのメッセージループ処理をＤＸライブラリで行うかどうかを設定する( TRUE:ＤＸライブラリで行う( デフォルト )  FALSE:ＤＸライブラリでは行わない )
extern	int			SetBackgroundColor(						int Red, int Green, int Blue ) ;													// メインウインドウの背景色を設定する( Red,Green,Blue:それぞれ ０〜２５５ )
extern	int			SetUseFPUPreserveFlag(					int Flag ) ;																		// FPUの精度を落とさない設定を使用するかどうかを設定する、DxLib_Init を呼び出す前のみ有効( TRUE:使用する(精度が落ちない)  FALSE:使用しない(精度を落とす(デフォルト) )
extern	int			SetValidMousePointerWindowOutClientAreaMoveFlag( int Flag ) ;																// マウスポインタがウインドウのクライアントエリアの外にいけるかどうかを設定する( TRUE:いける( デフォルト設定 )  FALSE:いけない )
extern	int			SetUseBackBufferTransColorFlag(			int Flag ) ;																		// バックバッファの透過色の部分を透過させるかどうかを設定する( TRUE:透過させる  FALSE:透過させない( デフォルト ) )
extern	int			SetResourceModule(						HMODULE ResourceModule ) ;															// リソースを読み込む際に使用するモジュールを設定する( NULL を指定すると初期状態に戻ります、デフォルトでは NULL )

// クリップボード関係
extern	int			GetClipboardText(			TCHAR *DestBuffer ) ;															// クリップボードに格納されているテキストデータを読み出す( DestBuffer:文字列を格納するバッファの先頭アドレス   戻り値  -1:クリップボードにテキストデータが無い  -1以外:クリップボードに格納されている文字列データのサイズ( 単位:byte ) ) 
extern	int			SetClipboardText(			const TCHAR *Text ) ;															// クリップボードにテキストデータを格納する

// ドラッグ＆ドロップされたファイル関係
extern	int			SetDragFileValidFlag(		int Flag ) ;																	// ファイルのメインウインドウへのドラッグ＆ドロップ機能を有効にするかどうかのフラグをセットする
extern	int			DragFileInfoClear(			void ) ;																		// メインウインドウへドラッグ＆ドロップされたファイルの情報をリセットする
extern	int			GetDragFilePath(			TCHAR *FilePathBuffer ) ;														// メインウインドウへドラッグ＆ドロップされたファイル名を取得する( FilePathBuffer:ファイル名を格納するバッファの先頭アドレス　　戻り値　-1:取得できなかった  0:取得できた )
extern	int			GetDragFileNum(				void ) ;																		// メインウインドウへドラッグ＆ドロップされたファイルの数を取得する

// ウインドウ描画領域設定系関数
extern	HRGN		CreateRgnFromGraph(			int Width , int Height , void *MaskData , int Pitch , int Byte ) ;				// 任意の画像イメージからRGNハンドルを作成する( Width:横ドット数  Height:縦ドット数  MaskData:ドット情報配列の先頭アドレス  Pitch:１ラインあたりのbyteサイズ  Byte:１ドット辺りのbyteサイズ( 対応しているのは 1〜4 )、ドットの数値が0かそれ以外かで判別 )
extern	HRGN		CreateRgnFromBaseImage(		BASEIMAGE *BaseImage, int TransColorR, int TransColorG, int TransColorB ) ;		// 任意の基本イメージデータと透過色からRGNハンドルを作成する( BaseImage:基本イメージデータのアドレス  TransColorR,TransColorG,TransColorB:透過色( それぞれ０〜２５５ )
extern	int			SetWindowRgnGraph(			const TCHAR *FileName ) ;														// 任意の画像ファイルからＲＧＮをセットする
extern	int			UpdateTransColorWindowRgn(	void ) ;																		// 描画先の画面の透過色の部分を透過させるＲＧＮをセットする( 使用される透過色は関数 SetTransColor で設定した色 )

// ツールバー関係
extern	int			SetupToolBar(				const TCHAR *BitmapName , int DivNum , int ResourceID = -1 ) ;															// ツールバーの準備、BitmapName に NULL, ResourceID に -1 を渡すとツールバーを解除( BitmapName:ツールバーのボタンに使用する画像ファイルパス、ResourceID に -1 以外を渡す場合は NULL にする  DivNum:ボタン画像中のボタンの数  ResourceID:ツールバーのボタンに使用するビットマップリソースのＩＤ、BitmapName に NULL を渡すとこの引数が使用される )
extern	int			AddToolBarButton(			int Type /* TOOLBUTTON_TYPE_NORMAL 等 */ , int State /* TOOLBUTTON_STATE_ENABLE 等 */ , int ImageIndex, int ID ) ;		// ツールバーにボタンを追加する( Type:ボタンタイプ( TOOLBUTTON_TYPE_NORMAL 等( 解説は #define の定義を参照してください ) )  State:初期状態( TOOLBUTTON_STATE_ENABLE 等( 解説は #define の定義を参照してください ) )  ImageIndex:使用するボタンの画像番号  ID:ボタンに割り当てる識別番号  )
extern	int			AddToolBarSep(				void ) ;																												// ツールバーに隙間を追加する
extern	int			GetToolBarButtonState(		int ID ) ;																												// ツールバーのボタンの状態を取得する( ID:AddToolBarButtonで設定したボタンの識別番号　　戻り値　TRUE:押されている or 押された  FALSE:押されていない )
extern	int			SetToolBarButtonState(		int ID , int State /* TOOLBUTTON_STATE_ENABLE 等 */ ) ;																	// ツールバーのボタンの状態を設定する( ID:AddToolBarButtonで設定したボタンの識別番号　State:設定する状態( TOOLBUTTON_STATE_ENABLE 等( 解説は #define の定義を参照してください ) )
extern	int			DeleteAllToolBarButton(		void ) ;																												// ツールバーのボタンを全て削除する

// メニュー関係
extern	int			SetUseMenuFlag(				int Flag ) ;																						// メニューを有効にするかどうかを設定する( TRUE:使用する  FALSE:使用しない )
extern	int			SetUseKeyAccelFlag(			int Flag ) ;																						// キーボードアクセラレーターを使用するかどうかを設定する( TRUE:使用する  FALSE:使用しない )

extern	int			AddKeyAccel(				const TCHAR *ItemName , int ItemID , int KeyCode , int CtrlFlag , int AltFlag , int ShiftFlag ) ;	// ショートカットキーを追加する( ItemName:ショートカットキーを割り当てるメニューのアイテム名( AddMenuItem で NewItemName に渡した名前 )、ItemID を使用する場合は NULL を渡す  ItemID:メニュー項目の識別番号( AddMenuItem の引数 NewItemID で指定したもの )、ItemName を使用する場合は -1 を渡す  KeyCode:ショートカットキーのキー( KEY_INPUT_L 等 )  CtrlFlag:同時にCTRLキーを押す必要があるようにするかどうか( TRUE:押す必要がある  FALSE:押さなくても良い )  AltFlag:同時にALTキーを押す必要があるようにするかどうか( TRUE:押す必要がある  FALSE:押さなくても良い )  ShiftFlag:同時にSHIFTキーを押す必要があるようにするかどうか( TRUE:押す必要がある  FALSE:押さなくても良い )
extern	int			AddKeyAccel_Name(			const TCHAR *ItemName , int KeyCode , int CtrlFlag , int AltFlag , int ShiftFlag ) ;				// ショートカットキーを追加する( 各引数の解説は AddKeyAccel と同じ、ItemID が無くなっただけ )
extern	int			AddKeyAccel_ID(				int ItemID, int KeyCode, int CtrlFlag, int AltFlag, int ShiftFlag ) ;								// ショートカットキーを追加する( 各引数の解説は AddKeyAccel と同じ、ItemName が無くなっただけ )
extern	int			ClearKeyAccel(				void ) ;																							// ショートカットキーの情報をリセットする

extern	int			AddMenuItem(				int AddType /* MENUITEM_ADD_CHILD等 */ , const TCHAR *ItemName, int ItemID, int SeparatorFlag, const TCHAR *NewItemName = NULL , int NewItemID = -1 ) ;	// メニューに項目を追加する( AddType:項目タイプ( MENUITEM_ADD_CHILD 等( 解説は #define の定義を参照してください ) )    ItemName:AddType が MENUITEM_ADD_CHILDの場合は親となる項目の名前、MENUITEM_ADD_INSERTの場合は挿入位置となる項目の名前、NULL を指定すると ItemID が使用される   ItemID:ItemName の代わりに識別番号で指定するもの、AddType毎の違いは ItemName の解説の通り、-1を指定すると ItemName が使用される　　SeparatorFlag:区切り線を追加するかどうか( TRUE:区切り線を追加、この場合 NewItemName と NewItemID は無視される  FALSE:追加するのは区切り線ではない )　　NewItemName:新しい項目の名前  NewItemID:新しい項目の識別番号、-1を指定すると内部で適当な番号が割り当てられる )
extern	int			DeleteMenuItem(				const TCHAR *ItemName, int ItemID ) ;																// メニューから選択項目を削除する( ItemName:削除する項目の名前( AddMenuItem で NewItemName に渡した名前 )、NULL を指定すると ItemID が使用される  ItemID:削除する項目の識別番号( AddMenuItem で NewItemID に渡した番号 )、-1 を指定すると ItemName が使用される )
extern	int			CheckMenuItemSelect(		const TCHAR *ItemName, int ItemID ) ;																// メニューが選択されたかどうかを取得する( 戻り値　 0:選択されていない  1:選択された   ItemName と ItemID については関数 DeleteMenuItem の注釈を参照してください )
extern	int			SetMenuItemEnable(			const TCHAR *ItemName, int ItemID, int EnableFlag ) ;												// メニューの項目を選択出来るかどうかを設定する( EnableFlag:項目が選択できるかどうか( TRUE:選択できる   FALSE:選択できない )   ItemName と ItemID については関数 DeleteMenuItem の注釈を参照してください )
extern	int			SetMenuItemMark(			const TCHAR *ItemName, int ItemID, int Mark ) ;														// メニューの項目にチェックマークやラジオボタンを表示するかどうかを設定する( Mark:設定するマーク( MENUITEM_MARK_NONE 等( 解説は #define の定義を参照してください )    ItemName と ItemID については関数 DeleteMenuItem の注釈を参照してください ) )
extern	int			CheckMenuItemSelectAll(		void ) ;																							// メニューの項目がどれか選択されたかどうかを取得する( 戻り値  TRUE:どれか選択された  FALSE:選択されていない )

extern	int			AddMenuItem_Name(			const TCHAR *ParentItemName, const TCHAR *NewItemName ) ;											// メニューに選択項目を追加する( ParentItemName:親となる項目の名前、親が持つリストの末端に新しい項目を追加します  NewItemName:新しい項目の名前 )
extern	int			AddMenuLine_Name(			const TCHAR *ParentItemName ) ;																		// メニューのリストに区切り線を追加する( ParentItemName:区切り線を付ける項目リストの親の名前、リストの末端に区切り線を追加します )
extern	int			InsertMenuItem_Name(		const TCHAR *ItemName, const TCHAR *NewItemName ) ;													// 指定の項目と、指定の項目の一つ上の項目との間に新しい項目を追加する
extern	int			InsertMenuLine_Name(		const TCHAR *ItemName ) ;																			// 指定の項目と、指定の項目の一つ上の項目との間に区切り線を追加する
extern	int			DeleteMenuItem_Name(		const TCHAR *ItemName ) ;																			// メニューから選択項目を削除する
extern	int			CheckMenuItemSelect_Name(	const TCHAR *ItemName ) ;																			// メニューが選択されたかどうかを取得する( 戻り値　0:選択されていない  1:選択された )
extern	int			SetMenuItemEnable_Name(		const TCHAR *ItemName, int EnableFlag ) ;															// メニューの項目を選択出来るかどうかを設定する( EnableFlag　1:選択できる  0:選択できない )
extern	int			SetMenuItemMark_Name(		const TCHAR *ItemName, int Mark ) ;																	// メニューの項目にチェックマークやラジオボタンを表示するかどうかを設定する( Mark:設定するマーク( MENUITEM_MARK_NONE 等 ) )

extern	int			AddMenuItem_ID(				int ParentItemID, const TCHAR *NewItemName, int NewItemID = -1 ) ;									// メニューに選択項目を追加する
extern	int			AddMenuLine_ID(				int ParentItemID ) ;																				// メニューのリストに区切り線を追加する
extern	int			InsertMenuItem_ID(			int ItemID, int NewItemID ) ;																		// 指定の項目と、指定の項目の一つ上の項目との間に新しい項目を追加する
extern	int			InsertMenuLine_ID(			int ItemID, int NewItemID ) ;																		// 指定の項目と、指定の項目の一つ上の項目との間に区切り線を追加する
extern	int			DeleteMenuItem_ID(			int ItemID ) ;																						// メニューから選択項目を削除する
extern	int			CheckMenuItemSelect_ID(		int ItemID ) ;																						// メニューが選択されたかどうかを取得する( 戻り値　　0:選択されていない  1:選択された )
extern	int			SetMenuItemEnable_ID(		int ItemID, int EnableFlag ) ;																		// メニューの項目を選択出来るかどうかを設定する( EnableFlag　1:選択できる  0:選択できない )
extern	int			SetMenuItemMark_ID(			int ItemID, int Mark ) ;																			// メニューの項目にチェックマークやラジオボタンを表示するかどうかを設定する( Mark:設定するマーク( MENUITEM_MARK_NONE 等 ) )

extern	int			DeleteMenuItemAll(			void ) ;																							// メニューの全ての選択項目を削除する
extern	int			ClearMenuItemSelect(		void ) ;																							// メニューが選択されたかどうかの情報をリセット
extern	int			GetMenuItemID(				const TCHAR *ItemName ) ;																			// メニューの項目名から項目識別番号を取得する
extern	int			GetMenuItemName(			int ItemID, TCHAR *NameBuffer ) ;																	// メニューの項目識別番号から項目名を取得する
extern	int 		LoadMenuResource(			int MenuResourceID ) ;																				// メニューをリソースから読み込む
extern	int			SetMenuItemSelectCallBackFunction(		void (* CallBackFunction )( const TCHAR *ItemName, int ItemID ) ) ;						// メニューの選択項目が選択されたときに呼ばれるコールバック関数を設定する( CallBackFunction:項目が選択されたときに呼ばれるコールバック関数、引数に項目名と項目の識別番号を渡されて呼ばれる )

extern	int			SetWindowMenu(				int MenuID, int (* MenuProc )( WORD ID ) ) ;														// (古い関数)ウインドウにメニューを設定する
extern	int			SetDisplayMenuFlag(			int Flag ) ;																						// メニューを表示するかどうかをセットする
extern	int			GetDisplayMenuFlag(			void ) ;																							// メニューを表示しているかどうかを取得する
extern	int			GetUseMenuFlag(				void ) ;																							// メニューを使用しているかどうかを得る
extern	int			SetAutoMenuDisplayFlag(		int Flag ) ;																						// フルスクリーン時にメニューを自動で表示したり非表示にしたりするかどうかのフラグをセットする

#endif // __WINDOWS__

// マウス関係関数
extern	int			SetMouseDispFlag(		int DispFlag ) ;												// マウスポインタの表示状態を設定する( DispFlag:マウスポインタを表示するかどうか( TRUE:表示する  FALSE:表示しない )
extern	int			GetMousePoint(			int *XBuf, int *YBuf ) ;										// マウスポインタの位置を取得する
extern	int			SetMousePoint(			int PointX, int PointY ) ;										// マウスポインタの位置を設定する
#ifndef DX_NON_INPUT
extern	int			GetMouseInput(			void ) ;														// マウスのボタンの押下状態を取得する
extern	int			GetMouseWheelRotVol(	int CounterReset = TRUE ) ;										// 垂直マウスホイールの回転量を取得する
extern	int			GetMouseHWheelRotVol(	int CounterReset = TRUE ) ;										// 水平マウスホイールの回転量を取得する
extern	float		GetMouseWheelRotVolF(	int CounterReset = TRUE ) ;										// 垂直マウスホイールの回転量を取得する( 戻り値が float 型 )
extern	float		GetMouseHWheelRotVolF(	int CounterReset = TRUE ) ;										// 水平マウスホイールの回転量を取得する( 戻り値が float 型 )
extern	int			GetMouseInputLog(		int *Button, int *ClickX, int *ClickY, int LogDelete = TRUE ) ;	// マウスのクリック情報を一つ取得する( Button:クリックされたボタン( MOUSE_INPUT_LEFT 等 )を格納する変数のアドレス  ClickX:クリックされた時のＸ座標を格納する変数のアドレス  ClickY:クリックされた時のＹ座標を格納する変数のアドレス   LogDelete:取得したクリック情報一つ分をログから削除するかどうか( TRUE:削除する  FALSE:削除しない、つまり次にこの関数が呼ばれたときに同じ値を取得することになる )　　戻り値  0:クリック情報取得できた　-1:クリック情報が無かった、つまり前回の呼び出し( または起動時から最初の呼び出し )の間に一度もマウスのボタンがクリックされなかった )
#endif // DX_NON_INPUT














// DxMemory.cpp関数プロトタイプ宣言

// メモリ確保系関数
extern	void*		DxAlloc(						size_t AllocSize , const char *File = NULL , int Line = -1 ) ;					// 指定のサイズのメモリを確保する( AllocSize:確保するメモリのサイズ( 単位:byte )  File:DxAllocを呼んだソースファイル名( デバッグ用 )  Line:DxAllocを呼んだソースファイル中の行番号( デバッグ用 )　　戻り値  NULL:メモリの確保失敗   NULL以外:確保したメモリ領域の先頭アドレス )
extern	void*		DxCalloc(						size_t AllocSize , const char *File = NULL , int Line = -1 ) ;					// 指定のサイズのメモリを確保して、０で埋める、初期化後に０で埋める以外は DxAlloc と動作は同じ
extern	void*		DxRealloc(						void *Memory , size_t AllocSize , const char *File = NULL , int Line = -1 ) ;	// メモリの再確保を行う( Memory:再確保を行うメモリ領域の先頭アドレス( DxAlloc の戻り値 )  AllocSize:新しい確保サイズ　FileとLine の説明は DxAlloc の注釈の通り 　戻り値 NULL:メモリの再確保失敗　NULL以外:再確保した新しいメモリ領域の先頭アドレス　)
extern	void		DxFree(							void *Memory ) ;																// メモリを解放する( Memory:解放するメモリ領域の先頭アドレス( DxAlloc の戻り値 ) )
extern	size_t		DxSetAllocSizeTrap(				size_t Size ) ;																	// 列挙対象にするメモリの確保容量をセットする
extern	int			DxSetAllocPrintFlag(			int Flag ) ;																	// ＤＸライブラリ内でメモリ確保が行われる時に情報を出力するかどうかをセットする
extern	size_t		DxGetAllocSize(					void ) ;																		// DxAlloc や DxCalloc で確保しているメモリサイズを取得する
extern	int			DxGetAllocNum(					void ) ;																		// DxAlloc や DxCalloc で確保しているメモリの数を取得する
extern	void		DxDumpAlloc(					void ) ;																		// DxAlloc や DxCalloc で確保しているメモリを列挙する
extern	int			DxErrorCheckAlloc(				void ) ;																		// 確保したメモリ情報が破壊されていないか調べる( -1:破壊あり  0:なし )
extern	int			DxSetAllocSizeOutFlag(			int Flag ) ;																	// メモリが確保、解放が行われる度に確保しているメモリの容量を出力するかどうかのフラグをセットする
extern	int			DxSetAllocMemoryErrorCheckFlag(	int Flag ) ;																	// メモリの確保、解放が行われる度に確保しているメモリ確保情報が破損していないか調べるかどうかのフラグをセットする
















// DxNetwork.cpp関数プロトタイプ宣言

#ifndef DX_NON_NETWORK

// 通信関係
extern	int			ProcessNetMessage(				int RunReleaseProcess = FALSE ) ;														// 通信メッセージの処理をする関数

extern	int			GetHostIPbyName(				const TCHAR *HostName, IPDATA      *IPDataBuf ) ;										// ＤＮＳサーバーを使ってホスト名からＩＰアドレスを取得する( IPv4版 )
extern	int			GetHostIPbyName_IPv6(			const TCHAR *HostName, IPDATA_IPv6 *IPDataBuf ) ;										// ＤＮＳサーバーを使ってホスト名からＩＰアドレスを取得する( IPv6版 )
extern 	int			ConnectNetWork(					IPDATA      IPData, int Port = -1 ) ;													// 他マシンに接続する( IPv4版 )
extern	int			ConnectNetWork_IPv6(			IPDATA_IPv6 IPData, int Port = -1 ) ;													// 他マシンに接続する( IPv6版 )
extern 	int			ConnectNetWork_ASync(			IPDATA      IPData, int Port = -1 ) ;													// 他マシンに接続する( IPv4版 )、非同期版
extern	int			ConnectNetWork_IPv6_ASync(		IPDATA_IPv6 IPData, int Port = -1 ) ;													// 他マシンに接続する( IPv6版 )、非同期版
extern 	int			PreparationListenNetWork(		int Port = -1 ) ;																		// 接続を受けられる状態にする( IPv4版 )
extern 	int			PreparationListenNetWork_IPv6(	int Port = -1 ) ;																		// 接続を受けられる状態にする( IPv6版 )
extern 	int			StopListenNetWork(				void ) ;																				// 接続を受けつけ状態の解除
extern 	int			CloseNetWork(					int NetHandle ) ;																		// 接続を終了する

extern 	int			GetNetWorkAcceptState(			int NetHandle ) ;																		// 接続状態を取得する
extern 	int			GetNetWorkDataLength(			int NetHandle ) ;																		// 受信データの量を得る
extern	int			GetNetWorkSendDataLength(		int NetHandle ) ;																		// 未送信のデータの量を得る 
extern 	int			GetNewAcceptNetWork(			void ) ;																				// 新たに接続した通信回線を得る
extern 	int			GetLostNetWork(					void ) ;																				// 接続を切断された通信回線を得る
extern 	int			GetNetWorkIP(					int NetHandle, IPDATA      *IpBuf ) ;													// 接続先のＩＰを得る( IPv4版 )
extern 	int			GetNetWorkIP_IPv6(				int NetHandle, IPDATA_IPv6 *IpBuf ) ;													// 接続先のＩＰを得る( IPv6版 )
extern	int			GetMyIPAddress(					IPDATA *IpBuf ) ;																		// 自分のＩＰを得る
extern	int			SetConnectTimeOutWait(			int Time ) ;																			// 接続のタイムアウトまでの時間を設定する
extern	int			SetUseDXNetWorkProtocol(		int Flag ) ;																			// ＤＸライブラリの通信形態を使うかどうかをセットする
extern	int			GetUseDXNetWorkProtocol(		void ) ; 																				// ＤＸライブラリの通信形態を使うかどうかを取得する
extern	int			SetUseDXProtocol(				int Flag ) ;																			// SetUseDXNetWorkProtocol の別名
extern	int			GetUseDXProtocol(				void ) ; 																				// GetUseDXNetWorkProtocol の別名
extern	int			SetNetWorkCloseAfterLostFlag(	int Flag ) ;																			// 接続が切断された直後に接続ハンドルを解放するかどうかのフラグをセットする
extern	int			GetNetWorkCloseAfterLostFlag(	void ) ;																				// 接続が切断された直後に接続ハンドルを解放するかどうかのフラグを取得する
//extern	int			SetProxySetting( int UseFlag, const char *Address, int Port ) ;														// ＨＴＴＰ通信で使用するプロキシ設定を行う
//extern	int			GetProxySetting( int *UseFlagBuffer, char *AddressBuffer, int *PortBuffer ) ;										// ＨＴＴＰ通信で使用するプロキシ設定を取得する
//extern	int			SetIEProxySetting( void ) ;																							// ＩＥのプロキシ設定を適応する

extern 	int			NetWorkRecv(			int NetHandle, void *Buffer, int Length ) ;														// 受信したデータを読み込む
extern	int			NetWorkRecvToPeek(		int NetHandle, void *Buffer, int Length ) ;														// 受信したデータを読み込む、読み込んだデータはバッファから削除されない
extern	int			NetWorkRecvBufferClear(	int NetHandle ) ;																				// 受信したデータをクリアする
extern 	int			NetWorkSend(			int NetHandle, void *Buffer, int Length ) ;														// データを送信する

extern	int			MakeUDPSocket(			int RecvPort = -1 ) ;																			// UDPを使用した通信を行うソケットハンドルを作成する( RecvPort を -1 にすると送信専用のソケットハンドルになります )
extern	int			MakeUDPSocket_IPv6(		int RecvPort = -1 ) ;																			// UDPを使用した通信を行うソケットハンドルを作成する( RecvPort を -1 にすると送信専用のソケットハンドルになります )( IPv6版 )
extern	int			DeleteUDPSocket(		int NetUDPHandle ) ;																			// UDPを使用した通信を行うソケットハンドルを削除する
extern	int			NetWorkSendUDP(			int NetUDPHandle, IPDATA       SendIP, int SendPort,  void *Buffer, int Length ) ;				// UDPを使用した通信で指定のＩＰにデータを送信する、Length は最大65507、SendPort を -1 にすると MakeUDPSocket に RecvPort で渡したポートが使用されます( 戻り値  0以上;送信できたデータサイズ  -1:エラー  -2:送信データが大きすぎる  -3:送信準備ができていない  )
extern	int			NetWorkSendUDP_IPv6(	int NetUDPHandle, IPDATA_IPv6  SendIP, int SendPort,  void *Buffer, int Length ) ;				// UDPを使用した通信で指定のＩＰにデータを送信する、Length は最大65507、SendPort を -1 にすると MakeUDPSocket に RecvPort で渡したポートが使用されます( 戻り値  0以上;送信できたデータサイズ  -1:エラー  -2:送信データが大きすぎる  -3:送信準備ができていない  )( IPv6版 )
extern	int			NetWorkRecvUDP(			int NetUDPHandle, IPDATA      *RecvIP, int *RecvPort, void *Buffer, int Length, int Peek ) ;	// UDPを使用した通信でデータを受信する、Peek に TRUE を渡すと受信に成功してもデータを受信キューから削除しません( 戻り値  0以上:受信したデータのサイズ  -1:エラー  -2:バッファのサイズが足りない  -3:受信データがない )
extern	int			NetWorkRecvUDP_IPv6(	int NetUDPHandle, IPDATA_IPv6 *RecvIP, int *RecvPort, void *Buffer, int Length, int Peek ) ;	// UDPを使用した通信でデータを受信する、Peek に TRUE を渡すと受信に成功してもデータを受信キューから削除しません( 戻り値  0以上:受信したデータのサイズ  -1:エラー  -2:バッファのサイズが足りない  -3:受信データがない )( IPv6版 )
//extern int		CheckNetWorkSendUDP(	int NetUDPHandle ) ;																			// UDPを使用した通信でデータが送信できる状態かどうかを調べる( 戻り値  -1:エラー  TRUE:送信可能  FALSE:送信不可能 )
extern	int			CheckNetWorkRecvUDP(	int NetUDPHandle ) ;																			// UDPを使用した通信で新たな受信データが存在するかどうかを調べる( 戻り値  -1:エラー  TRUE:受信データあり  FALSE:受信データなし )

/*	使用不可
extern	int			HTTP_FileDownload(			const char *FileURL, const char *SavePath = NULL , void **SaveBufferP = NULL , int *FileSize = NULL , char **ParamList = NULL ) ;						// HTTP を使用してネットワーク上のファイルをダウンロードする
extern	int			HTTP_GetFileSize(			const char *FileURL ) ;																		// HTTP を使用してネットワーク上のファイルのサイズを得る

extern	int			HTTP_StartFileDownload(		const char *FileURL, const char *SavePath, void **SaveBufferP = NULL , char **ParamList = NULL ) ;	// HTTP を使用したネットワーク上のファイルをダウンロードする処理を開始する
extern	int			HTTP_StartGetFileSize(		const char *FileURL ) ;																		// HTTP を使用したネットワーク上のファイルのサイズを得る処理を開始する
extern	int			HTTP_Close(					int HttpHandle ) ;																			// HTTP の処理を終了し、ハンドルを解放する
extern	int			HTTP_CloseAll(				void ) ;																					// 全てのハンドルに対して HTTP_Close を行う
extern	int			HTTP_GetState(				int HttpHandle ) ;																			// HTTP 処理の現在の状態を得る( NET_RES_COMPLETE 等 )
extern	int			HTTP_GetError(				int HttpHandle ) ;																			// HTTP 処理でエラーが発生した場合、エラーの内容を得る( HTTP_ERR_NONE 等 )
extern	int			HTTP_GetDownloadFileSize(	int HttpHandle ) ;																			// HTTP 処理で対象となっているファイルのサイズを得る( 戻り値: -1 = エラー・若しくはまだファイルのサイズを取得していない  0以上 = ファイルのサイズ )
extern	int			HTTP_GetDownloadedFileSize( int HttpHandle ) ;																			// HTTP 処理で既にダウンロードしたファイルのサイズを取得する

extern	int			fgetsForNetHandle(			int NetHandle, char *strbuffer ) ;															// fgets のネットワークハンドル版( -1:取得できず 0:取得できた )
extern	int			URLAnalys(					const char *URL, char *HostBuf = NULL , char *PathBuf = NULL , char *FileNameBuf = NULL , int *PortBuf = NULL ) ;	// ＵＲＬを解析する
extern	int			URLConvert(					char *URL, int ParamConvert = TRUE , int NonConvert = FALSE ) ;								// HTTP に渡せない記号が使われた文字列を渡せるような文字列に変換する( 戻り値: -1 = エラー  0以上 = 変換後の文字列のサイズ )
extern	int			URLParamAnalysis(			char **ParamList, char **ParamStringP ) ;													// HTTP 用パラメータリストから一つのパラメータ文字列を作成する( 戻り値:  -1 = エラー  0以上 = パラメータの文字列の長さ )
*/

#endif // DX_NON_NETWORK
















// DxInputString.cpp関数プロトタイプ宣言

#ifndef DX_NON_INPUTSTRING

// 文字コードバッファ操作関係
extern	int			StockInputChar(		TCHAR CharCode ) ;								// 文字コードバッファに文字コードをストックする
extern	int			ClearInputCharBuf(	void ) ;										// 文字コードバッファをクリアする
extern	TCHAR		GetInputChar(		int DeleteFlag ) ;								// 文字コードバッファに溜まったデータから文字コードを一つ取得する
extern	TCHAR		GetInputCharWait(	int DeleteFlag ) ;								// 文字コードバッファに溜まったデータから文字コードを一つ取得する、バッファになにも文字コードがない場合は文字コードがバッファに一文字分溜まるまで待つ

extern	int			GetOneChar(			TCHAR *CharBuffer, int DeleteFlag ) ;			// 文字コードバッファに溜まったデータから１文字分取得する
extern	int			GetOneCharWait(		TCHAR *CharBuffer, int DeleteFlag ) ;			// 文字コードバッファに溜まったデータから１文字分取得する、バッファに何も文字コードがない場合は文字コードがバッファに一文字分溜まるまで待つ
extern	int			GetCtrlCodeCmp(		TCHAR Char ) ;									// 指定の文字コードがアスキーコントロールコードか調べる

#endif // DX_NON_INPUTSTRING

#ifndef DX_NON_KEYEX

extern	int			DrawIMEInputString(				int x, int y, int SelectStringNum ) ;	// 画面上に入力中の文字列を描画する
extern	int			SetUseIMEFlag(					int UseFlag ) ;							// ＩＭＥを使用するかどうかを設定する
extern	int			SetInputStringMaxLengthIMESync(	int Flag ) ;							// ＩＭＥで入力できる最大文字数を MakeKeyInput の設定に合わせるかどうかをセットする( TRUE:あわせる  FALSE:あわせない(デフォルト) )
extern	int			SetIMEInputStringMaxLength(		int Length ) ;							// ＩＭＥで一度に入力できる最大文字数を設定する( 0:制限なし  1以上:指定の文字数で制限 )

#endif // DX_NON_KEYEX

extern	int			GetStringPoint(				const TCHAR *String, int Point ) ;			// 全角文字、半角文字入り乱れる中から指定の文字数での半角文字数を得る
extern	int			GetStringPoint2(			const TCHAR *String, int Point ) ;			// 全角文字、半角文字入り乱れる中から指定の文字数での全角文字数を得る

#ifndef DX_NON_FONT
extern	int			DrawObtainsString(			int x, int y, int AddY, const TCHAR *String, int StrColor, int StrEdgeColor = 0 , int FontHandle = -1 , int SelectBackColor = -1 , int SelectStrColor = 0 , int SelectStrEdgeColor = -1 , int SelectStart = -1 , int SelectEnd = -1 ) ;		// 描画可能領域に収まるように改行しながら文字列を描画
#endif // DX_NON_FONT
extern	int			DrawObtainsBox(				int x1, int y1, int x2, int y2, int AddY, int Color, int FillFlag ) ;																																										// 描画可能領域に収まるように補正を加えながら矩形を描画

#ifndef DX_NON_KEYEX

extern	int			InputStringToCustom(		int x, int y, int BufLength, TCHAR *StrBuffer, int CancelValidFlag, int SingleCharOnlyFlag, int NumCharOnlyFlag, int DoubleCharOnlyFlag = FALSE ) ;		// 文字列の入力取得

extern	int			KeyInputString(				int x, int y, int CharMaxLength, TCHAR *StrBuffer, int CancelValidFlag ) ;														// 文字列の入力取得
extern	int			KeyInputSingleCharString(	int x, int y, int CharMaxLength, TCHAR *StrBuffer, int CancelValidFlag ) ;														// 半角文字列のみの入力取得
extern	int			KeyInputNumber(				int x, int y, int MaxNum, int MinNum, int CancelValidFlag ) ;																	// 数値の入力取得

extern	int			GetIMEInputModeStr(			TCHAR *GetBuffer ) ;																											// IMEの入力モード文字列を取得する
extern	IMEINPUTDATA* GetIMEInputData(			void ) ;																														// IMEで入力中の文字列の情報を取得する
#if defined( DX_GCC_COMPILE ) || defined( __ANDROID )
extern	int			SetKeyInputStringColor(		ULONGLONG NmlStr, ULONGLONG NmlCur, ULONGLONG IMEStr, ULONGLONG IMECur, ULONGLONG IMELine, ULONGLONG IMESelectStr, ULONGLONG IMEModeStr , ULONGLONG NmlStrE = 0 , ULONGLONG IMESelectStrE = 0 , ULONGLONG IMEModeStrE = 0 , ULONGLONG IMESelectWinE = 0xffffffffffffffffULL ,	ULONGLONG IMESelectWinF = 0xffffffffffffffffULL , ULONGLONG SelectStrBackColor = 0xffffffffffffffffULL , ULONGLONG SelectStrColor = 0xffffffffffffffffULL , ULONGLONG SelectStrEdgeColor = 0xffffffffffffffffULL ) ;	// InputString関数使用時の文字の各色を変更する
#else // defined( DX_GCC_COMPILE ) || defined( __ANDROID )
extern	int			SetKeyInputStringColor(		ULONGLONG NmlStr, ULONGLONG NmlCur, ULONGLONG IMEStr, ULONGLONG IMECur, ULONGLONG IMELine, ULONGLONG IMESelectStr, ULONGLONG IMEModeStr , ULONGLONG NmlStrE = 0 , ULONGLONG IMESelectStrE = 0 , ULONGLONG IMEModeStrE = 0 , ULONGLONG IMESelectWinE = 0xffffffffffffffff ,	ULONGLONG IMESelectWinF = 0xffffffffffffffff , ULONGLONG SelectStrBackColor = 0xffffffffffffffff , ULONGLONG SelectStrColor = 0xffffffffffffffff , ULONGLONG SelectStrEdgeColor = 0xffffffffffffffff ) ;	// InputString関数使用時の文字の各色を変更する
#endif // defined( DX_GCC_COMPILE ) || defined( __ANDROID )
extern	int			SetKeyInputStringFont(		int FontHandle ) ;																												// キー入力文字列描画関連で使用するフォントのハンドルを変更する(-1でデフォルトのフォントハンドル)
extern	int			DrawKeyInputModeString(		int x, int y ) ;																												// 入力モード文字列を描画する

extern	int			InitKeyInput(				void ) ;																														// キー入力データ初期化
extern	int			MakeKeyInput(				int MaxStrLength, int CancelValidFlag, int SingleCharOnlyFlag, int NumCharOnlyFlag, int DoubleCharOnlyFlag = FALSE ) ;			// 新しいキー入力ハンドルの作成
extern	int			DeleteKeyInput(				int InputHandle ) ;																												// キー入力ハンドルの削除
extern	int			SetActiveKeyInput(			int InputHandle ) ;																												// 指定のキー入力ハンドルをアクティブにする( -1 を指定するとアクティブなキー入力ハンドルが無い状態になります )
extern	int			GetActiveKeyInput(			void ) ;																														// 現在アクティブになっているキー入力ハンドルを取得する
extern	int			CheckKeyInput(				int InputHandle ) ;																												// キー入力ハンドルの入力が終了しているか取得する
extern	int			ReStartKeyInput(			int InputHandle ) ;																												// 入力が完了したキー入力ハンドルを再度編集状態に戻す
extern	int			ProcessActKeyInput(			void ) ;																														// キー入力ハンドル処理関数
extern	int			DrawKeyInputString(			int x, int y, int InputHandle ) ;																								// キー入力ハンドルの入力中情報の描画

extern	int			SetKeyInputSelectArea(		int  SelectStart, int  SelectEnd, int InputHandle ) ;																			// キー入力ハンドルの指定の領域を選択状態にする( SelectStart と SelectEnd に -1 を指定すると選択状態が解除されます )
extern	int			GetKeyInputSelectArea(		int *SelectStart, int *SelectEnd, int InputHandle ) ;																			// キー入力ハンドルの選択領域を取得する
extern	int			SetKeyInputDrawStartPos(	int DrawStartPos, int InputHandle ) ;																							// キー入力ハンドルの描画開始文字位置を設定する
extern	int			GetKeyInputDrawStartPos(	int InputHandle ) ;																												// キー入力ハンドルの描画開始文字位置を取得する
extern	int			SetKeyInputCursorBrinkTime(	int Time ) ;																													// キー入力ハンドルのキー入力時のカーソルの点滅する早さをセットする
extern	int			SetKeyInputCursorBrinkFlag(	int Flag ) ;																													// キー入力ハンドルのキー入力時のカーソルを点滅させるかどうかをセットする
extern	int			SetKeyInputString(			const TCHAR *String, int InputHandle ) ;																						// キー入力ハンドルに指定の文字列をセットする
extern	int			SetKeyInputNumber(			int   Number,        int InputHandle ) ;																						// キー入力ハンドルに指定の数値を文字に置き換えてセットする
extern	int			SetKeyInputNumberToFloat(	float Number,        int InputHandle ) ;																						// キー入力ハンドルに指定の浮動小数点値を文字に置き換えてセットする
extern	int			GetKeyInputString(			TCHAR *StrBuffer,    int InputHandle ) ;																						// キー入力ハンドルの入力中の文字列を取得する
extern	int			GetKeyInputNumber(			int InputHandle ) ;																												// キー入力ハンドルの入力中の文字列を整数値として取得する
extern	float		GetKeyInputNumberToFloat(	int InputHandle ) ;																												// キー入力ハンドルの入力中の文字列を浮動小数点値として取得する
extern	int			SetKeyInputCursorPosition(	int Position,        int InputHandle ) ;																						// キー入力ハンドルの現在のカーソル位置を設定する
extern	int			GetKeyInputCursorPosition(	int InputHandle ) ;																												// キー入力ハンドルの現在のカーソル位置を取得する

#endif // DX_NON_KEYEX











// DxFile.cpp関数プロトタイプ宣言

// ファイルアクセス関数
extern	int			FileRead_open(				const TCHAR *FilePath , int ASync = FALSE ) ;					// ファイルを開く
extern	int			FileRead_size(				const TCHAR *FilePath ) ;										// ファイルのサイズを取得する
extern	int			FileRead_close(				int FileHandle ) ;												// ファイルを閉じる
extern	int			FileRead_tell(				int FileHandle ) ;												// ファイルポインタの読み込み位置を取得する
extern	int			FileRead_seek(				int FileHandle , int Offset , int Origin ) ;					// ファイルポインタの読み込み位置を変更する
extern	int			FileRead_read(				void *Buffer , int ReadSize , int FileHandle ) ;				// ファイルからデータを読み込む
extern	int			FileRead_idle_chk(			int FileHandle ) ;												// ファイル読み込みが完了しているかどうかを取得する
extern	int			FileRead_eof(				int FileHandle ) ;												// ファイルの読み込み位置が終端に達しているかどうかを取得する
extern	int			FileRead_gets(				TCHAR *Buffer , int BufferSize , int FileHandle ) ;				// ファイルから文字列を読み出す
extern	TCHAR		FileRead_getc(				int FileHandle ) ;												// ファイルから一文字読み出す
extern	int			FileRead_scanf(				int FileHandle , const TCHAR *Format , ... ) ;					// ファイルから書式化されたデータを読み出す

extern	DWORD_PTR	FileRead_createInfo(		const TCHAR *ObjectPath ) ;										// ファイル情報ハンドルを作成する( 戻り値  -1:エラー  -1以外:ファイル情報ハンドル )
extern	int			FileRead_getInfoNum(		DWORD_PTR FileInfoHandle ) ;									// ファイル情報ハンドル中のファイルの数を取得する
extern	int			FileRead_getInfo(			int Index , FILEINFO *Buffer , DWORD_PTR FileInfoHandle ) ;		// ファイル情報ハンドル中のファイルの情報を取得する
extern	int			FileRead_deleteInfo(		DWORD_PTR FileInfoHandle ) ;									// ファイル情報ハンドルを削除する

extern	DWORD_PTR	FileRead_findFirst(			const TCHAR *FilePath, FILEINFO *Buffer ) ;						// 指定のファイル又はフォルダの情報を取得し、ファイル検索ハンドルも作成する( 戻り値: -1=エラー  -1以外=ファイル検索ハンドル )
extern	int			FileRead_findNext(			DWORD_PTR FindHandle, FILEINFO *Buffer ) ;						// 条件の合致する次のファイルの情報を取得する( 戻り値: -1=エラー  0=成功 )
extern	int			FileRead_findClose(			DWORD_PTR FindHandle ) ;										// ファイル検索ハンドルを閉じる( 戻り値: -1=エラー  0=成功 )

// 設定関係関数
extern	int			GetStreamFunctionDefault(	void ) ;														// ＤＸライブラリでストリームデータアクセスに使用する関数がデフォルトのものか調べる( TRUE:デフォルトのもの  FALSE:デフォルトではない )
extern	int			ChangeStreamFunction(		STREAMDATASHREDTYPE2 *StreamThread ) ;							// ＤＸライブラリでストリームデータアクセスに使用する関数を変更する












// DxInput.cpp関数プロトタイプ宣言

#ifndef DX_NON_INPUT

// 入力状態取得関数
extern	int			CheckHitKey(							int KeyCode ) ;															// キーボードの押下状態を取得する
extern	int			CheckHitKeyAll(							int CheckType = DX_CHECKINPUT_ALL ) ;									// どれか一つでもキーが押されているかどうかを取得( 押されていたら戻り値が 0 以外になる )
extern	int			GetHitKeyStateAll(						DX_CHAR *KeyStateBuf ) ;												// すべてのキーの押下状態を取得する( KeyStateBuf:char型256個分の配列の先頭アドレス )
extern	int			SetKeyExclusiveCooperativeLevelFlag(	int Flag ) ;															// DirectInput のキーボードの協調レベルを排他レベルにするかどうかを設定する( TRUE:排他レベルにする  FALSE:標準レベルにする( デフォルト ) )、DxLib_Init の呼び出し前でのみ実行可能
extern	int			GetJoypadNum(							void ) ;																// ジョイパッドが接続されている数を取得する
extern	int			GetJoypadInputState(					int InputType ) ;														// ジョイパッドの入力状態を取得する
extern	int			GetJoypadAnalogInput(					int *XBuf, int *YBuf, int InputType ) ;									// ジョイパッドのアナログ的なスティック入力情報を得る
extern	int			GetJoypadAnalogInputRight(				int *XBuf, int *YBuf, int InputType ) ;									// ( 使用非推奨 )ジョイパッドのアナログ的なスティック入力情報を得る(右スティック用)
extern	int			GetJoypadDirectInputState(				int InputType, DINPUT_JOYSTATE *DInputState ) ;							// DirectInput から得られるジョイパッドの生のデータを取得する( DX_INPUT_KEY や DX_INPUT_KEY_PAD1 など、キーボードが絡むタイプを InputType に渡すとエラー )
extern	int			KeyboradBufferProcess(					void ) ;																// キーボードのバッファからデータを取得する処理
extern	int			GetJoypadGUID(							int PadIndex, GUID *GuidBuffer ) ;										// ジョイパッドのＧＵIＤを得る
extern	int			ConvertKeyCodeToVirtualKey(				int KeyCode ) ;															// ＤＸライブラリのキーコード( KEY_INPUT_A など )に対応する Windows の仮想キーコード( VK_LEFT など ) を取得する( KeyCode:変換したいＤＸライブラリのキーコード　戻り値：Windowsの仮想キーコード )
extern	int			ConvertVirtualKeyToKeyCode(				int VirtualKey ) ;														//  Windows の仮想キーコード( VK_LEFT など ) に対応するＤＸライブラリのキーコード( KEY_INPUT_A など )を取得する( VirtualKey:変換したいWindowsの仮想キーコード　戻り値：ＤＸライブラリのキーコード )
extern	int			SetJoypadInputToKeyInput(				int InputType, int PadInput, int KeyInput1, int KeyInput2 = -1 , int KeyInput3 = -1 , int KeyInput4 = -1  ) ; // ジョイパッドの入力に対応したキーボードの入力を設定する( InputType:設定を変更するパッドの識別子( DX_INPUT_PAD1等 )　　PadInput:設定を変更するパッドボタンの識別子( PAD_INPUT_1 等 )　　KeyInput1:PadInput を押下したことにするキーコード( KEY_INPUT_A など )その１　　KeyInput2:その２、-1で設定なし　　KeyInput3:その３、-1で設定なし　　KeyInput4:その４、-1で設定なし )
extern	int			SetJoypadDeadZone(						int InputType, double Zone ) ;											// ジョイパッドの無効ゾーンの設定を行う( InputType:設定を変更するパッドの識別子( DX_INPUT_PAD1等 )   Zone:新しい無効ゾーン( 0.0 〜 1.0 )、デフォルト値は 0.35 )
extern	int			StartJoypadVibration(					int InputType, int Power, int Time ) ;									// ジョイパッドの振動を開始する
extern	int			StopJoypadVibration(					int InputType ) ;														// ジョイパッドの振動を停止する
extern	int			GetJoypadPOVState(						int InputType, int POVNumber ) ;										// ジョイパッドのＰＯＶ入力の状態を得る( 戻り値　指定のPOVデータの角度、単位は角度の１００倍( 90度なら 9000 ) 中心位置にある場合は -1 が返る )
extern	int			GetJoypadName(							int InputType, TCHAR *InstanceNameBuffer, TCHAR *ProductNameBuffer ) ;	// ジョイパッドのデバイス登録名と製品登録名を取得する
extern	int			ReSetupJoypad(							void ) ;																// ジョイパッドの再セットアップを行う( 新たに接続されたジョイパッドがあったら検出される )

extern	int			SetKeyboardNotDirectInputFlag(			int Flag ) ;															// キーボードの入力処理に DirectInput を使わないかどうかを設定する( TRUE:DirectInput を使わず、Windows標準機能を使用する　　FALSE:DirectInput を使用する )
extern	int			SetUseDirectInputFlag(					int Flag ) ;															// 入力処理に DirectInput を使用するかどうかを設定する( TRUE:DirectInput を使用する　　FALSE:DirectInput を使わず、Windows標準機能を使用する )
extern	int			SetUseJoypadVibrationFlag(				int Flag ) ;															// ジョイパッドの振動機能を使用するかどうかを設定する( TRUE:使用する　　FALSE:使用しない )

#endif // DX_NON_INPUT







#ifndef DX_NOTUSE_DRAWFUNCTION

// 画像処理系関数プロトタイプ宣言

// グラフィックハンドル作成関係関数
extern	int			MakeGraph(						int SizeX, int SizeY, int NotUse3DFlag = FALSE ) ;							// 指定サイズのグラフィックハンドルを作成する
extern	int			MakeScreen(						int SizeX, int SizeY, int UseAlphaChannel = FALSE ) ;						// SetDrawScreen で描画対象にできるグラフィックハンドルを作成する
extern	int			DerivationGraph(				int SrcX, int SrcY, int Width, int Height, int SrcGraphHandle ) ;			// 指定のグラフィックハンドルの指定部分だけを抜き出して新たなグラフィックハンドルを作成する
extern	int			DeleteGraph(					int GrHandle, int LogOutFlag = FALSE ) ;									// グラフィックハンドルを削除する
extern	int			DeleteSharingGraph(				int GrHandle ) ;															// 指定のグラフィックハンドルと、同じグラフィックハンドルから派生しているグラフィックハンドル( DerivationGraph で派生したハンドル、LoadDivGraph 読み込んで作成された複数のハンドル )を一度に削除する
extern	int			GetGraphNum(					void ) ;																	// 有効なグラフィックハンドルの数を取得する
extern	int			FillGraph(						int GrHandle, int Red, int Green, int Blue, int Alpha = 255 ) ;				// グラフィックハンドルを指定の色で塗りつぶす
extern	int			SetGraphLostFlag(				int GrHandle, int *LostFlag ) ;												// 指定のグラフィックハンドルが削除された際に 1 にする変数のアドレスを設定する
extern	int			InitGraph(						int LogOutFlag = FALSE ) ;													// すべてのグラフィックハンドルを削除する
extern	int			ReloadFileGraphAll(				void ) ;																	// ファイルから画像を読み込んだ全てのグラフィックハンドルについて、再度ファイルから画像を読み込む

// グラフィックハンドルへの画像転送関数
extern	int			BltBmpToGraph(					COLORDATA *BmpColorData, HBITMAP RgbBmp, HBITMAP AlphaBmp, int CopyPointX, int CopyPointY,                                                                                 int GrHandle ) ;						// ＢＭＰの内容をグラフィックハンドルに転送
extern	int			BltBmpToDivGraph(				COLORDATA *BmpColorData, HBITMAP RgbBmp, HBITMAP AlphaBmp, int AllNum, int XNum, int YNum, int Width, int Height,                                                          int *GrHandle, int ReverseFlag ) ;	// ＢＭＰの内容を分割作成したグラフィックハンドルたちに転送
extern	int			BltBmpOrGraphImageToGraph(		COLORDATA *BmpColorData, HBITMAP RgbBmp, HBITMAP AlphaBmp, int BmpFlag, BASEIMAGE *RgbImage, BASEIMAGE *AlphaImage, int CopyPointX, int CopyPointY,                        int GrHandle ) ;						// ＢＭＰ か BASEIMAGE をグラフィックハンドルに転送
extern	int			BltBmpOrGraphImageToGraph2(		COLORDATA *BmpColorData, HBITMAP RgbBmp, HBITMAP AlphaBmp, int BmpFlag, BASEIMAGE *RgbImage, BASEIMAGE *AlphaImage, RECT *SrcRect, int DestX, int DestY,                   int GrHandle ) ;						// ＢＭＰ か BASEIMAGE の指定の領域をグラフィックハンドルに転送
extern	int			BltBmpOrGraphImageToDivGraph(	COLORDATA *BmpColorData, HBITMAP RgbBmp, HBITMAP AlphaBmp, int BmpFlag, BASEIMAGE *RgbImage, BASEIMAGE *AlphaImage, int AllNum, int XNum, int YNum, int Width, int Height, int *GrHandle, int ReverseFlag ) ;	// ＢＭＰ か BASEIMAGE を分割作成したグラフィックハンドルたちに転送

// 画像からグラフィックハンドルを作成する関数
extern	int			LoadBmpToGraph(					const TCHAR *FileName, int TextureFlag, int ReverseFlag, int SurfaceMode = DX_MOVIESURFACE_NORMAL ) ;								// 画像ファイルからグラフィックハンドルを作成する
extern	int			LoadGraph(						const TCHAR *FileName, int NotUse3DFlag = FALSE ) ;																					// 画像ファイルからグラフィックハンドルを作成する
extern	int			LoadReverseGraph(				const TCHAR *FileName, int NotUse3DFlag = FALSE ) ;																					// 画像ファイルを反転したものでグラフィックハンドルを作成する
extern	int			LoadDivGraph(					const TCHAR *FileName, int AllNum, int XNum, int YNum, int XSize, int YSize, int *HandleBuf, int NotUse3DFlag = FALSE ) ;			// 画像ファイルを分割してグラフィックハンドルを作成する
extern	int			LoadDivBmpToGraph(				const TCHAR *FileName, int AllNum, int XNum, int YNum, int SizeX, int SizeY, int *HandleBuf, int TextureFlag, int ReverseFlag ) ;	// 画像ファイルを分割してグラフィックハンドルを作成する
extern	int			LoadReverseDivGraph(			const TCHAR *FileName, int AllNum, int XNum, int YNum, int XSize, int YSize, int *HandleBuf, int NotUse3DFlag = FALSE ) ;			// 画像ファイルを反転したものを分割してグラフィックハンドルを作成する
extern	int			LoadBlendGraph(					const TCHAR *FileName ) ;																											// 画像ファイルからブレンド用グラフィックハンドルを作成する
#ifdef __WINDOWS__
extern	int			LoadGraphToResource(			int ResourceID ) ;																													// 画像リソースからグラフィックハンドルを作成する
extern	int			LoadDivGraphToResource(			int ResourceID, int AllNum, int XNum, int YNum, int XSize, int YSize, int *HandleBuf ) ;											// 画像リソースを分割してグラフィックハンドルを作成する
extern	int			LoadGraphToResource(			const TCHAR *ResourceName, const TCHAR *ResourceType ) ;																			// 画像リソースからグラフィックハンドルを作成する
extern	int			LoadDivGraphToResource(			const TCHAR *ResourceName, const TCHAR *ResourceType, int AllNum, int XNum, int YNum, int XSize, int YSize, int *HandleBuf ) ;		// 画像リソースを分割してグラフィックハンドルを作成する
#endif // __WINDOWS__

extern	int			CreateGraphFromMem(				void *RGBFileImage, int RGBFileImageSize,               void *AlphaFileImage = NULL , int AlphaFileImageSize = 0 ,      int TextureFlag = TRUE , int ReverseFlag = FALSE ) ;																// メモリ上の画像イメージからグラフィックハンドルを作成する
extern	int			ReCreateGraphFromMem(           void *RGBFileImage, int RGBFileImageSize, int GrHandle, void *AlphaFileImage = NULL , int AlphaFileImageSize = 0 ,      int TextureFlag = TRUE , int ReverseFlag = FALSE ) ;																// メモリ上の画像イメージから既存のグラフィックハンドルにデータを転送する
extern	int			CreateDivGraphFromMem(          void *RGBFileImage, int RGBFileImageSize, int AllNum, int XNum, int YNum, int SizeX, int SizeY, int *HandleBuf,         int TextureFlag = TRUE , int ReverseFlag = FALSE , void *AlphaFileImage = NULL , int AlphaFileImageSize = 0 ) ;		// メモリ上の画像イメージから分割グラフィックハンドルを作成する
extern	int			ReCreateDivGraphFromMem(        void *RGBFileImage, int RGBFileImageSize, int AllNum, int XNum, int YNum, int SizeX, int SizeY, int *HandleBuf,         int TextureFlag = TRUE , int ReverseFlag = FALSE , void *AlphaFileImage = NULL , int AlphaFileImageSize = 0 ) ;		// メモリ上の画像イメージから既存の分割グラフィックハンドルにデータを転送する
extern	int			CreateGraphFromBmp(             BITMAPINFO *RGBBmpInfo, void *RGBBmpImage,               BITMAPINFO *AlphaBmpInfo = NULL , void *AlphaBmpImage = NULL , int TextureFlag = TRUE , int ReverseFlag = FALSE ) ;																// ビットマップデータからグラフィックハンドルを作成する
extern	int			ReCreateGraphFromBmp(           BITMAPINFO *RGBBmpInfo, void *RGBBmpImage, int GrHandle, BITMAPINFO *AlphaBmpInfo = NULL , void *AlphaBmpImage = NULL , int TextureFlag = TRUE , int ReverseFlag = FALSE ) ;																// ビットマップデータから既存のグラフィックハンドルにデータを転送する
extern	int			CreateDivGraphFromBmp(          BITMAPINFO *RGBBmpInfo, void *RGBBmpImage, int AllNum, int XNum, int YNum, int SizeX, int SizeY, int *HandleBuf,        int TextureFlag = TRUE , int ReverseFlag = FALSE , BITMAPINFO *AlphaBmpInfo = NULL , void *AlphaBmpImage = NULL ) ;	// ビットマップデータから分割グラフィックハンドルを作成する
extern	int			ReCreateDivGraphFromBmp(        BITMAPINFO *RGBBmpInfo, void *RGBBmpImage, int AllNum, int XNum, int YNum, int SizeX, int SizeY, int *HandleBuf,        int TextureFlag = TRUE , int ReverseFlag = FALSE , BITMAPINFO *AlphaBmpInfo = NULL , void *AlphaBmpImage = NULL ) ;	// ビットマップデータから既存の分割グラフィックハンドルにデータを転送する
extern	int			CreateDXGraph(					BASEIMAGE *RgbImage, BASEIMAGE *AlphaImage,																				int TextureFlag ) ;																									// 基本イメージデータからサイズを割り出し、それに合ったグラフィックハンドルを作成する
extern	int			CreateGraphFromGraphImage(      BASEIMAGE *RGBImage,                                                                                                    int TextureFlag = TRUE , int ReverseFlag = FALSE ) ;																// 基本イメージデータからグラフィックハンドルを作成する
extern	int			CreateGraphFromGraphImage(      BASEIMAGE *RGBImage, BASEIMAGE *AlphaImage,                                                                             int TextureFlag = TRUE , int ReverseFlag = FALSE ) ;																// 基本イメージデータからグラフィックハンドルを作成する
extern	int			ReCreateGraphFromGraphImage(    BASEIMAGE *RGBImage,                        int GrHandle,                                                               int TextureFlag = TRUE , int ReverseFlag = FALSE ) ;																// 基本イメージデータから既存のグラフィックハンドルにデータを転送する
extern	int			ReCreateGraphFromGraphImage(    BASEIMAGE *RGBImage, BASEIMAGE *AlphaImage, int GrHandle,                                                               int TextureFlag = TRUE , int ReverseFlag = FALSE ) ;																// 基本イメージデータから既存のグラフィックハンドルにデータを転送する
extern	int			CreateDivGraphFromGraphImage(   BASEIMAGE *RGBImage,                        int AllNum, int XNum, int YNum, int SizeX, int SizeY, int *HandleBuf,       int TextureFlag = TRUE , int ReverseFlag = FALSE ) ;																// 基本イメージデータから分割グラフィックハンドルを作成する
extern	int			CreateDivGraphFromGraphImage(   BASEIMAGE *RGBImage, BASEIMAGE *AlphaImage, int AllNum, int XNum, int YNum, int SizeX, int SizeY, int *HandleBuf,       int TextureFlag = TRUE , int ReverseFlag = FALSE ) ;																// 基本イメージデータから分割グラフィックハンドルを作成する
extern	int			ReCreateDivGraphFromGraphImage( BASEIMAGE *RGBImage,                        int AllNum, int XNum, int YNum, int SizeX, int SizeY, int *HandleBuf,       int TextureFlag = TRUE , int ReverseFlag = FALSE ) ;																// 基本イメージデータから既存の分割グラフィックハンドルにデータを転送する
extern	int			ReCreateDivGraphFromGraphImage( BASEIMAGE *RGBImage, BASEIMAGE *AlphaImage, int AllNum, int XNum, int YNum, int SizeX, int SizeY, int *HandleBuf,       int TextureFlag = TRUE , int ReverseFlag = FALSE ) ;																// 基本イメージデータから既存の分割グラフィックハンドルにデータを転送する
extern	int			CreateGraph(                    int Width, int Height, int Pitch, void *RGBImage, void *AlphaImage = NULL , int GrHandle = -1 ) ;																																			// メモリ上のビットマップイメージからグラフィックハンドルを作成する
extern	int			CreateDivGraph(                 int Width, int Height, int Pitch, void *RGBImage, int AllNum, int XNum, int YNum, int SizeX, int SizeY, int *HandleBuf, void *AlphaImage = NULL ) ;																							// メモリ上のビットマップイメージから分割グラフィックハンドルを作成する
extern	int			ReCreateGraph(                  int Width, int Height, int Pitch, void *RGBImage, int GrHandle, void *AlphaImage = NULL ) ;																																					// メモリ上のビットマップイメージからグラフィックハンドルを再作成する
#ifndef DX_NON_SOFTIMAGE
extern	int			CreateBlendGraphFromSoftImage(  int SIHandle ) ;																													// ソフトウエアで扱うイメージからブレンド用画像グラフィックハンドルを作成する( -1:エラー  -1以外:ブレンド用グラフィックハンドル )
extern	int			CreateGraphFromSoftImage(       int SIHandle ) ;																													// ソフトウエアで扱うイメージからグラフィックハンドルを作成する( -1:エラー  -1以外:グラフィックハンドル )
extern	int			CreateGraphFromRectSoftImage(   int SIHandle, int x, int y, int SizeX, int SizeY ) ;																				// ソフトウエアで扱うイメージの指定の領域を使ってグラフィックハンドルを作成する( -1:エラー  -1以外:グラフィックハンドル )
extern	int			ReCreateGraphFromSoftImage(     int SIHandle, int GrHandle ) ;																										// ソフトウエアで扱うイメージから既存のグラフィックハンドルに画像データを転送する
extern	int			ReCreateGraphFromRectSoftImage( int SIHandle, int x, int y, int SizeX, int SizeY, int GrHandle ) ;																	// ソフトウエアで扱うイメージから既存のグラフィックハンドルに画像データを転送する
extern	int			CreateDivGraphFromSoftImage(    int SIHandle, int AllNum, int XNum, int YNum, int SizeX, int SizeY, int *HandleBuf ) ;												// ソフトウエアで扱うイメージから分割グラフィックハンドルを作成する
#endif // DX_NON_SOFTIMAGE
extern	int			CreateGraphFromBaseImage(       BASEIMAGE *BaseImage ) ;																											// 基本イメージデータからグラフィックハンドルを作成する
extern	int			CreateGraphFromRectBaseImage(   BASEIMAGE *BaseImage, int x, int y, int SizeX, int SizeY ) ;																		// 基本イメージデータの指定の領域を使ってグラフィックハンドルを作成する
extern	int			ReCreateGraphFromBaseImage(     BASEIMAGE *BaseImage,                                     int GrHandle ) ;															// 基本イメージデータから既存のグラフィックハンドルに画像データを転送する
extern	int			ReCreateGraphFromRectBaseImage( BASEIMAGE *BaseImage, int x, int y, int SizeX, int SizeY, int GrHandle ) ;															// 基本イメージデータの指定の領域を使って既存のグラフィックハンドルに画像データを転送する
extern	int			CreateDivGraphFromBaseImage(    BASEIMAGE *BaseImage, int AllNum, int XNum, int YNum, int SizeX, int SizeY, int *HandleBuf ) ;										// 基本イメージデータから分割グラフィックハンドルを作成する
extern	int			ReloadGraph(					const TCHAR *FileName, int GrHandle, int ReverseFlag = FALSE ) ;																	// 画像ファイルからグラフィックハンドルへ画像データを転送する
extern	int			ReloadDivGraph(					const TCHAR *FileName, int AllNum, int XNum, int YNum, int XSize, int YSize, int *HandleBuf, int ReverseFlag = FALSE ) ;			// 画像ファイルからグラフィックハンドルたちへ画像データを分割転送する
extern	int			ReloadReverseGraph(				const TCHAR *FileName, int GrHandle ) ;																								// ReloadGraph の画像反転処理追加版
extern	int			ReloadReverseDivGraph(			const TCHAR *FileName, int AllNum, int XNum, int YNum, int XSize, int YSize, int *HandleBuf ) ;										// ReloadDivGraph の画像反転処理追加版

// グラフィックハンドル作成時設定係関数
extern	int			SetGraphColorBitDepth(						int ColorBitDepth ) ;							// SetCreateGraphColorBitDepth の旧名称
extern 	int			GetGraphColorBitDepth(						void ) ;										// GetCreateGraphColorBitDepth の旧名称
extern	int			SetCreateGraphColorBitDepth(				int BitDepth ) ;								// 作成するグラフィックハンドルの色深度を設定する
extern	int			GetCreateGraphColorBitDepth(				void ) ;										// 作成するグラフィックハンドルの色深度を取得する
extern	int			SetCreateGraphChannelBitDepth(				int BitDepth ) ;								// 作成するグラフィックハンドルの１チャンネル辺りのビット深度を設定する
extern	int			GetCreateGraphChannelBitDepth(				void ) ;										// 作成するグラフィックハンドルの１チャンネル辺りのビット深度を取得する
extern	int			SetDrawValidGraphCreateFlag(				int Flag ) ;									// SetDrawScreen に引数として渡せる( 描画対象として使用できる )グラフィックハンドルを作成するかどうかを設定する( TRUE:描画可能グラフィックハンドルを作成する  FLASE:通常のグラフィックハンドルを作成する( デフォルト ) )
extern	int			GetDrawValidGraphCreateFlag(				void ) ;										// SetDrawScreen に引数として渡せる( 描画対象として使用できる )グラフィックハンドルを作成するかどうかを設定を取得する
extern	int			SetDrawValidFlagOf3DGraph(					int Flag ) ;									// SetDrawValidGraphCreateFlag の旧名称
extern	int			SetLeftUpColorIsTransColorFlag(				int Flag ) ;									// 画像ファイルからグラフィックハンドルを作成する際に画像左上の色を透過色として扱うかどうかを設定する( TRUE:透過色として扱う 　FALSE:透過色として扱わない( デフォルト ) )
extern	int			SetUseBlendGraphCreateFlag(					int Flag ) ;									// ブレンド処理用画像を作成するかどうか( 要は画像の赤成分をα成分として扱うかどうか )の設定を行う( TRUE:ブレンド画像として読み込む  FALSE:通常画像として読み込む( デフォルト ) )
extern	int			GetUseBlendGraphCreateFlag(					void ) ;										// ブレンド処理用画像を作成するかどうか( 要は画像の赤成分をα成分として扱うかどうか )の設定を取得する
extern	int			SetUseAlphaTestGraphCreateFlag(				int Flag ) ;									// アルファテストを使用するグラフィックハンドルを作成するかどうかを設定する( TRUE:アルファテストを使用する( デフォルト )  FALSE:アルファテストを使用しない )
extern	int			GetUseAlphaTestGraphCreateFlag(				void ) ;										// アルファテストを使用するグラフィックハンドルを作成するかどうかを取得する
extern	int			SetUseAlphaTestFlag(						int Flag ) ;									// SetUseAlphaTestGraphCreateFlag の旧名称
extern	int			GetUseAlphaTestFlag(						void ) ;										// GetUseAlphaTestGraphCreateFlag の旧名称
extern	int			SetUseNoBlendModeParam(						int Flag ) ;									// SetDrawBlendMode 関数の第一引数に DX_BLENDMODE_NOBLEND を代入した際に、デフォルトでは第二引数は内部で２５５を指定したことになるが、その自動２５５化をしないかどうかを設定する( TRUE:しない(第二引数の値が使用される)   FALSE:する(第二引数の値は無視されて 255 が常に使用される)(デフォルト) )αチャンネル付き画像に対して描画を行う場合のみ意味がある関数
extern	int			SetDrawValidAlphaChannelGraphCreateFlag(	int Flag ) ;									// SetDrawScreen の引数として渡せる( 描画対象として使用できる )αチャンネル付きグラフィックハンドルを作成するかどうかを設定する( SetDrawValidGraphCreateFlag 関数で描画対象として使用できるグラフィックハンドルを作成するように設定されていないと効果ありません )( TRUE:αチャンネル付き   FALSE:αチャンネルなし( デフォルト ) )
extern	int			GetDrawValidAlphaChannelGraphCreateFlag(	void ) ;										// SetDrawScreen の引数として渡せる( 描画対象として使用できる )αチャンネル付きグラフィックハンドルを作成するかどうかを取得する
extern	int			SetDrawValidFloatTypeGraphCreateFlag(		int Flag ) ;									// SetDrawScreen の引数として渡せる( 描画対象として使用できる )ピクセルフォーマットが浮動小数点型のグラフィックハンドルを作成するかどうかを設定する( SetDrawValidGraphCreateFlag 関数で描画対象として使用できるグラフィックハンドルを作成するように設定されていないと効果ありません )、グラフィックスデバイスが浮動小数点型のピクセルフォーマットに対応していない場合はグラフィックハンドルの作成に失敗する( TRUE:浮動小数点型　　FALSE:整数型( デフォルト ) )
extern	int			GetDrawValidFloatTypeGraphCreateFlag(		void ) ;										// SetDrawScreen の引数として渡せる( 描画対象として使用できる )ピクセルフォーマットが浮動小数点型のグラフィックハンドルを作成するかどうかを取得する
extern	int			SetDrawValidGraphCreateZBufferFlag(			int Flag ) ;									// SetDrawScreen の引数として渡せる( 描画対象として使用できる )グラフィックハンドルを作成する際に専用のＺバッファも作成するかどうかを設定する( TRUE:専用のＺバッファを作成する( デフォルト )  FALSE:専用のＺバッファは作成しない )
extern	int			GetDrawValidGraphCreateZBufferFlag(			void ) ;										// SetDrawScreen の引数として渡せる( 描画対象として使用できる )グラフィックハンドルを作成する際に専用のＺバッファも作成するかどうかを取得する
extern	int			SetCreateDrawValidGraphChannelNum(			int ChannelNum ) ;								// SetDrawScreen の引数として渡せる( 描画対象として使用できる )グラフィックハンドルに適用する色のチャンネル数を設定する( ChannelNum:チャンネル数( 指定可能な値は 1, 2, 4 の何れか( SetDrawValidGraphCreateFlag 関数で描画対象として使用できるグラフィックハンドルを作成するように設定されていないと効果ありません )
extern	int			GetCreateDrawValidGraphChannelNum(			void ) ;										// SetDrawScreen の引数として渡せる( 描画対象として使用できる )グラフィックハンドルに適用する色のチャンネル数を取得する
extern	int			SetDrawValidMultiSample(					int Samples, int Quality ) ;					// SetDrawScreen の引数として渡せる( 描画対象として使用できる )グラフィックハンドルに適用するマルチサンプリング( アンチエイリアシング )設定を行う( Samples:マルチサンプル処理に使用するドット数( 多いほど重くなります )  Quality:マルチサンプル処理の品質 )
extern	int			GetMultiSampleQuality(						int Samples ) ;									// 指定のマルチサンプル数で使用できる最大クオリティ値を取得する( 戻り値がマイナスの場合は引数のサンプル数が使用できないことを示します )
extern	int			SetUseTransColor(							int Flag ) ;									// 透過色機能を使用するかどうかを設定する( TRUE:使用する( デフォルト )  FALSE:使用しない )
extern	int			SetUseTransColorGraphCreateFlag(			int Flag ) ;									// 透過色機能を使用することを前提とした画像データの読み込み処理を行うかどうかを設定する( TRUE にすると SetDrawMode( DX_DRAWMODE_BILINEAR ); をした状態で DrawGraphF 等の浮動小数点型座標を受け取る関数で小数点以下の値を指定した場合に発生する描画結果の不自然を緩和する効果があります ( デフォルトは FALSE ) )
extern 	int			SetUseGraphAlphaChannel(					int Flag ) ;									// SetUseAlphaChannelGraphCreateFlag の旧名称
extern 	int			GetUseGraphAlphaChannel(					void ) ;										// GetUseAlphaChannelGraphCreateFlag の旧名称
extern 	int			SetUseAlphaChannelGraphCreateFlag(			int Flag ) ;									// αチャンネル付きグラフィックハンドルを作成するかどうかを設定する( TRUE:αチャンネル付き   FALSE:αチャンネル無し )
extern 	int			GetUseAlphaChannelGraphCreateFlag(			void ) ;										// αチャンネル付きグラフィックハンドルを作成するかどうかを取得する( TRUE:αチャンネル付き   FALSE:αチャンネル無し )
extern	int			SetUseNotManageTextureFlag(					int Flag ) ;									// Direct3D の管理テクスチャ機能を使用するグラフィックハンドルを作成するかどうかを設定する( TRUE:管理機能を使用する( デフォルト )  FALSE:管理機能を使用しない )、管理機能を使用するとグラフィックスデバイスのＶＲＡＭ容量以上の画像を扱うことができる代わりにシステムメモリの使用量が増えます
extern	int			GetUseNotManageTextureFlag(					void ) ;										// Direct3D の管理テクスチャ機能を使用するグラフィックハンドルを作成するかどうかを取得する
extern	int			SetTransColor(								int Red, int Green, int Blue ) ;				// 作成するグラフィックハンドルに適用する透過色を設定する( Red,Green,Blue:透過色を光の３原色で表したもの( 各色０〜２５５ ) )
extern	int			GetTransColor(								int *Red, int *Green, int *Blue ) ;				// 作成するグラフィックハンドルに適用する透過色を取得する
extern	int			SetUseDivGraphFlag(							int Flag ) ;									// ２のｎ乗ではないサイズの画像を複数のテクスチャを使用してＶＲＡＭの無駄を省くかどうかを設定する( TRUE:複数のテクスチャを使用する   FALSE:なるべく一枚のテクスチャで済ます( デフォルト ) )、複数のテクスチャを使用する場合はＶＲＡＭ容量の節約ができる代わりに速度の低下やバイリニアフィルタリング描画時にテクスチャとテクスチャの境目が良く見るとわかる等の弊害があります
extern	int			SetUseMaxTextureSize(						int Size ) ;									// 使用するテクスチャーの最大サイズを設定する( デフォルトではグラフィックスデバイスが対応している最大テクスチャーサイズ、引数に 0 を渡すとデフォルト設定になります )
extern	int			SetUseGraphBaseDataBackup(					int Flag ) ;									// グラフィックハンドルを作成する際に使用した画像データのバックアップをして Direct3DDevice のデバイスロスト時に使用するかどうかを設定する( TRUE:バックアップをする( デフォルト )  FALSE:バックアップをしない )、バックアップをしないとメモリの節約になりますが、復帰に掛かる時間が長くなり、メモリ上のファイルイメージからグラフィックハンドルを作成した場合は自動復帰ができないなどの弊害があります
extern	int			GetUseGraphBaseDataBackup(					void ) ;										// グラフィックハンドルを作成する際に使用した画像データのバックアップをして Direct3DDevice のデバイスロスト時に使用するかどうかを取得する
extern	int			SetUseSystemMemGraphCreateFlag(				int Flag ) ;									// ( 現在効果なし )グラフィックハンドルが持つ画像データをシステムメモリ上に作成するかどうかを設定する( TRUE:システムメモリ上に作成  FALSE:ＶＲＡＭ上に作成( デフォルト ) )
extern	int			GetUseSystemMemGraphCreateFlag(				void ) ;										// ( 現在効果なし )グラフィックハンドルが持つ画像データをシステムメモリ上に作成するかどうかを取得する

// 画像情報関係関数
extern	DWORD*		GetFullColorImage(				int GrHandle ) ;																		// 指定のグラフィックハンドルのＡＲＧＢ８イメージを取得する( 現在動画ファイルをグラフィックハンドルで読み込んだ場合のみ使用可能 )

extern	int			GraphLock(						int GrHandle, int *PitchBuf, void **DataPointBuf, COLORDATA **ColorDataPP = NULL ) ;	// グラフィックメモリ領域のロック
extern	int			GraphUnLock(					int GrHandle ) ;																		// グラフィックメモリ領域のロック解除

extern	int			SetUseGraphZBuffer(				int GrHandle, int UseFlag ) ;															// グラフィックハンドル専用のＺバッファを持つかどうかを設定する( GrHandle:対象となるグラフィックハンドル( 描画対象として使用可能なグラフィックハンドルのみ有効 )  UseFlag:専用のＺバッファを持つかどうか( TRUE:持つ( デフォルト )  FALSE:持たない ) )
extern	int			CopyGraphZBufferImage(			int DestGrHandle, int SrcGrHandle ) ;													// グラフィックハンドルのＺバッファの状態を別のグラフィックハンドルのＺバッファにコピーする( DestGrHandle も SrcGrHandle もＺバッファを持っている描画対象にできるグラフィックハンドルで、サイズが同じであり、且つマルチサンプリング( アンチエイリアス )設定が無いことが条件 )

extern	int			GetGraphSize(					int GrHandle, int *SizeXBuf, int *SizeYBuf ) ;											// グラフィックハンドルが持つ画像のサイズを得る
extern	int			GetGraphTextureSize(			int GrHandle, int *SizeXBuf, int *SizeYBuf ) ;											// グラフィックハンドルが持つ一つ目のテクスチャのサイズを得る
extern	int			GetGraphMipmapCount(			int GrHandle ) ;																		// グラフィックハンドルが持つテクスチャのミップマップレベル数を取得する
extern	int			GetGraphFilePath(				int GrHandle, TCHAR *FilePathBuffer ) ;													// グラフィックハンドルが画像ファイルから読み込まれていた場合、その画像のファイルパスを取得する

extern	COLORDATA*	GetTexColorData(				int AlphaCh, int AlphaTest, int ColorBitDepth, int DrawValid = FALSE ) ;				// カラーデータを得る
extern	COLORDATA*	GetTexColorData(				IMAGEFORMATDESC *Format ) ;																// フォーマットに基づいたカラーデータを得る
extern	COLORDATA*	GetTexColorData(				int FormatIndex ) ;																		// 指定のフォーマットインデックスのカラーデータを得る
extern	int			GetMaxGraphTextureSize(			int *SizeX, int *SizeY ) ;																// グラフィックスデバイスが対応している最大テクスチャサイズを取得する
extern	int			GetValidRestoreShredPoint(		void ) ;																				// グラフィックハンドルの画像を復元する関数が登録されているかどうかを取得する( TRUE:登録されている  FALSE:登録されていない )
extern	int			GetCreateGraphColorData(		COLORDATA *ColorData, IMAGEFORMATDESC *Format ) ;										// これから新たにグラフィックを作成する場合に使用するカラー情報を取得する

// 画像パレット操作関係関数( ソフトウエア画像のみ使用可能 )
extern	int			GetGraphPalette(				int GrHandle, int ColorIndex, int *Red, int *Green, int *Blue ) ;						// グラフィックハンドルのパレットを取得する( ソフトウエアレンダリングモードで、且つパレット画像の場合のみ使用可能 )
extern  int			GetGraphOriginalPalette(		int GrHandle, int ColorIndex, int *Red, int *Green, int *Blue ) ;						// グラフィックハンドルの SetGraphPalette で変更する前のパレットを取得する( ソフトウエアレンダリングモードで、且つパレット画像の場合のみ使用可能 )
extern	int			SetGraphPalette(				int GrHandle, int ColorIndex, int Color ) ;												// グラフィックハンドルのパレットを変更する( ソフトウエアレンダリングモードで、且つパレット画像の場合のみ使用可能 )
extern	int			ResetGraphPalette(				int GrHandle ) ;																		// SetGraphPalette で変更したパレットを全て元に戻す( ソフトウエアレンダリングモードで、且つパレット画像の場合のみ使用可能 )

// 図形描画関数
extern	int			DrawLine(       int x1, int y1, int x2, int y2,                                 int Color, int Thickness = 1 ) ;		// 線を描画する
extern	int			DrawBox(        int x1, int y1, int x2, int y2,                                 int Color, int FillFlag ) ;				// 四角形の描画する
extern	int			DrawFillBox(    int x1, int y1, int x2, int y2,                                 int Color ) ;							// 中身を塗りつぶす四角形を描画する
extern	int			DrawLineBox(    int x1, int y1, int x2, int y2,                                 int Color ) ;							// 枠だけの四角形の描画 する
extern	int			DrawCircle(     int x, int y, int r,                                            int Color, int FillFlag = TRUE ) ;		// 円を描画する
extern	int			DrawOval(       int x, int y, int rx, int ry,                                   int Color, int FillFlag ) ;				// 楕円を描画する
extern	int			DrawTriangle(   int x1, int y1, int x2, int y2, int x3, int y3,                 int Color, int FillFlag ) ;				// 三角形を描画する
extern	int			DrawQuadrangle( int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int Color, int FillFlag ) ;				// 四角形を描画する
extern 	int			DrawPixel(      int x, int y,                                                   int Color ) ;							// 点を描画する

extern	int			Paint(			int x, int y, int FillColor, int BoundaryColor = -1 ) ;													// 指定点から境界色があるところまで塗りつぶす(境界色を -1 にすると指定点の色の領域を塗りつぶす)

extern 	int			DrawPixelSet(   POINTDATA *PointData, int Num ) ;																		// 点の集合を描画する
extern	int			DrawLineSet(    LINEDATA *LineData,   int Num ) ;																		// 線の集合を描画する

extern	int			DrawPixel3D(    VECTOR Pos,                                                            int Color ) ;					// ３Ｄの点を描画する
extern	int			DrawLine3D(     VECTOR Pos1, VECTOR Pos2,                                              int Color ) ;					// ３Ｄの線分を描画する
extern	int			DrawTriangle3D( VECTOR Pos1, VECTOR Pos2, VECTOR Pos3,                                 int Color, int FillFlag ) ;		// ３Ｄの三角形を描画する
extern	int			DrawCube3D(     VECTOR Pos1, VECTOR Pos2,                             int DifColor, int SpcColor, int FillFlag ) ;		// ３Ｄの立方体を描画する
extern	int			DrawSphere3D(   VECTOR CenterPos,                float r, int DivNum, int DifColor, int SpcColor, int FillFlag ) ;		// ３Ｄの球体を描画する
extern	int			DrawCapsule3D(  VECTOR Pos1, VECTOR Pos2,        float r, int DivNum, int DifColor, int SpcColor, int FillFlag ) ;		// ３Ｄのカプセルを描画する
extern	int			DrawCone3D(     VECTOR TopPos, VECTOR BottomPos, float r, int DivNum, int DifColor, int SpcColor, int FillFlag ) ;		// ３Ｄの円錐を描画する

// 画像描画関数
extern	int			LoadGraphScreen(          int x, int y, const TCHAR *GraphName, int TransFlag ) ;										// 画像ファイルを読みこんで画面に描画する

extern	int			DrawGraph(                int x, int y,                                                                 int GrHandle, int TransFlag ) ;										// 画像の等倍描画
extern	int			DrawExtendGraph(          int x1, int y1, int x2, int y2,                                               int GrHandle, int TransFlag ) ;										// 画像の拡大描画
extern	int			DrawRotaGraph(            int x, int y,                 double ExRate,                    double Angle, int GrHandle, int TransFlag, int TurnFlag = FALSE  ) ;				// 画像の回転描画
extern	int			DrawRotaGraph2(           int x, int y, int cx, int cy, double ExtRate,                   double Angle, int GrHandle, int TransFlag, int TurnFlag = FALSE  ) ;				// 画像の回転描画２( 回転中心指定付き )
extern	int			DrawRotaGraph3(           int x, int y, int cx, int cy, double ExtRateX, double ExtRateY, double Angle, int GrHandle, int TransFlag, int TurnFlag = FALSE ) ; 				// 画像の回転描画３( 回転中心指定付き＋縦横拡大率別指定版 )
extern	int			DrawModiGraph(            int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4,               int GrHandle, int TransFlag ) ;										// 画像の自由変形描画
extern	int			DrawTurnGraph(            int x, int y,                                                                 int GrHandle, int TransFlag ) ;										// 画像の左右反転描画

extern	int			DrawGraphF(               float xf, float yf,                                                                       int GrHandle, int TransFlag ) ;							// 画像の描画( 座標指定が float 版 )
extern	int			DrawExtendGraphF(         float x1f, float y1f, float x2f, float y2,                                                int GrHandle, int TransFlag ) ;							// 画像の拡大描画( 座標指定が float 版 )
extern	int			DrawRotaGraphF(           float xf, float yf,                       double ExRate,                    double Angle, int GrHandle, int TransFlag, int TurnFlag = FALSE  ) ;	// 画像の回転描画( 座標指定が float 版 )
extern	int			DrawRotaGraph2F(          float xf, float yf, float cxf, float cyf, double ExtRate,                   double Angle, int GrHandle, int TransFlag, int TurnFlag = FALSE  ) ;	// 画像の回転描画２( 回転中心指定付き )( 座標指定が float 版 )
extern	int			DrawRotaGraph3F(          float xf, float yf, float cxf, float cyf, double ExtRateX, double ExtRateY, double Angle, int GrHandle, int TransFlag, int TurnFlag = FALSE ) ; 	// 画像の回転描画３( 回転中心指定付き＋縦横拡大率別指定版 )( 座標指定が float 版 )
extern	int			DrawModiGraphF(           float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4,           int GrHandle, int TransFlag ) ;							// 画像の自由変形描画( 座標指定が float 版 )
extern	int			DrawTurnGraphF(           float xf, float yf,                                                                       int GrHandle, int TransFlag ) ;							// 画像の左右反転描画( 座標指定が float 版 )

extern	int			DrawChipMap(              int Sx, int Sy, int XNum, int YNum, int *MapData, int ChipTypeNum, int MapDataPitch, int *ChipGrHandle, int TransFlag ) ;																											// チップ画像を使った２Ｄマップ描画
extern	int			DrawChipMap(              int MapWidth, int MapHeight,        int *MapData, int ChipTypeNum,                   int *ChipGrHandle, int TransFlag, int MapDrawPointX, int MapDrawPointY, int MapDrawWidth, int MapDrawHeight, int ScreenX, int ScreenY ) ;	// チップ画像を使った２Ｄマップ描画
extern	int			DrawTile(                 int x1, int y1, int x2, int y2, int Tx, int Ty, double ExtRate, double Angle, int GrHandle, int TransFlag ) ;																														// 画像を指定領域にタイル状に描画する

extern	int			DrawRectGraph(            int DestX,  int DestY,                          int SrcX, int SrcY, int    Width, int    Height,                         int GraphHandle, int TransFlag, int TurnFlag ) ;				// 画像の指定矩形部分のみを等倍描画
extern	int			DrawRectExtendGraph(      int DestX1, int DestY1, int DestX2, int DestY2, int SrcX, int SrcY, int SrcWidth, int SrcHeight,                         int GraphHandle, int TransFlag ) ;							// 画像の指定矩形部分のみを拡大描画
extern	int			DrawRectRotaGraph(        int x, int y, int SrcX, int SrcY, int Width, int Height, double ExtRate, double Angle,                                   int GraphHandle, int TransFlag, int TurnFlag ) ;				// 画像の指定矩形部分のみを回転描画
extern	int			DrawRectRotaGraph2(       int x, int y, int SrcX, int SrcY, int Width, int Height, int cx, int cy, double ExtRate,  double Angle,                  int GraphHandle, int TransFlag, int TurnFlag ) ;				// 画像の指定矩形部分のみを回転描画２( 回転中心指定付き )
extern	int			DrawRectRotaGraph3(       int x, int y, int SrcX, int SrcY, int Width, int Height, int cx, int cy, double ExtRateX, double ExtRateY, double Angle, int GraphHandle, int TransFlag, int TurnFlag ) ;				// 画像の指定矩形部分のみを回転描画３( 回転中心指定付き＋縦横拡大率別指定版 )

extern	int			DrawRectGraphF(           float DestX,  float DestY,                              int SrcX, int SrcY, int    Width, int    Height,                           int GraphHandle, int TransFlag, int TurnFlag ) ;	// 画像の指定矩形部分のみを等倍描画( 座標指定が float 版 )
extern	int			DrawRectExtendGraphF(     float DestX1, float DestY1, float DestX2, float DestY2, int SrcX, int SrcY, int SrcWidth, int SrcHeight,                           int GraphHandle, int TransFlag ) ;					// 画像の指定矩形部分のみを拡大描画( 座標指定が float 版 )
extern	int			DrawRectRotaGraphF(       float x, float y, int SrcX, int SrcY, int Width, int Height,                       double ExtRate,                   double Angle, int GraphHandle, int TransFlag, int TurnFlag ) ;	// 画像の指定矩形部分のみを回転描画( 座標指定が float 版 )
extern	int			DrawRectRotaGraph2F(      float x, float y, int SrcX, int SrcY, int Width, int Height, float cxf, float cyf, double ExtRate,                   double Angle, int GraphHandle, int TransFlag, int TurnFlag ) ;	// 画像の指定矩形部分のみを回転描画２( 回転中心指定付き )( 座標指定が float 版 )
extern	int			DrawRectRotaGraph3F(      float x, float y, int SrcX, int SrcY, int Width, int Height, float cxf, float cyf, double ExtRateX, double ExtRateY, double Angle, int GraphHandle, int TransFlag, int TurnFlag ) ;	// 画像の指定矩形部分のみを回転描画３( 回転中心指定付き＋縦横拡大率別指定版 )( 座標指定が float 版 )

extern	int			DrawBlendGraph(           int x, int y, int GrHandle, int TransFlag,                 int BlendGraph, int BorderParam, int BorderRange ) ;									// ブレンド画像と合成して画像を等倍描画する
extern	int			DrawBlendGraphPos(        int x, int y, int GrHandle, int TransFlag, int bx, int by, int BlendGraph, int BorderParam, int BorderRange ) ;									// ブレンド画像と合成して画像を等倍描画する( ブレンド画像の起点座標を指定する引数付き )

extern	int			DrawCircleGauge(          int CenterX, int CenterY, double Percent, int GrHandle, double StartPercent = 0.0 ) ;																				// 円グラフ的な描画を行う( GrHandle の画像の上下左右の端は透過色にしておく必要があります )

extern	int			DrawGraphToZBuffer(       int X, int Y,                                                                 int GrHandle, int WriteZMode /* DX_ZWRITE_MASK 等 */ ) ;							// Ｚバッファに対して画像の等倍描画
extern	int			DrawTurnGraphToZBuffer(   int x, int y,                                                                 int GrHandle, int WriteZMode /* DX_ZWRITE_MASK 等 */ ) ;							// Ｚバッファに対して画像の左右反転描画
extern	int			DrawExtendGraphToZBuffer( int x1, int y1, int x2, int y2,                                               int GrHandle, int WriteZMode /* DX_ZWRITE_MASK 等 */ ) ;							// Ｚバッファに対して画像の拡大描画
extern	int			DrawRotaGraphToZBuffer(   int x, int y, double ExRate, double Angle,                                    int GrHandle, int WriteZMode /* DX_ZWRITE_MASK 等 */ , int TurnFlag = FALSE ) ;		// Ｚバッファに対して画像の回転描画
extern	int			DrawRotaGraph2ToZBuffer(  int x, int y, int cx, int cy, double ExtRate,                   double Angle, int GrHandle, int WriteZMode /* DX_ZWRITE_MASK 等 */ , int TurnFlag = FALSE ) ;		// Ｚバッファに対して画像の回転描画２( 回転中心指定付き )
extern	int			DrawRotaGraph3ToZBuffer(  int x, int y, int cx, int cy, double ExtRateX, double ExtRateY, double Angle, int GrHandle, int WriteZMode /* DX_ZWRITE_MASK 等 */ , int TurnFlag = FALSE ) ; 	// Ｚバッファに対して画像の回転描画３( 回転中心指定付き＋縦横拡大率別指定版 )
extern	int			DrawModiGraphToZBuffer(   int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4,               int GrHandle, int WriteZMode /* DX_ZWRITE_MASK 等 */ ) ;							// Ｚバッファに対して画像の自由変形描画
extern	int			DrawBoxToZBuffer(         int x1, int y1, int x2, int y2,                                               int FillFlag, int WriteZMode /* DX_ZWRITE_MASK 等 */ ) ;							// Ｚバッファに対して矩形の描画
extern	int			DrawCircleToZBuffer(      int x, int y, int r,                                                          int FillFlag, int WriteZMode /* DX_ZWRITE_MASK 等 */ ) ;							// Ｚバッファに対して円の描画

extern	int			DrawPolygon(                             VERTEX    *Vertex, int PolygonNum,                                                                                              int GrHandle, int TransFlag, int UVScaling = FALSE ) ;		// ２Ｄポリゴンを描画する( Vertex:三角形を形成する頂点配列の先頭アドレス( 頂点の数はポリゴンの数×３ )  PolygonNum:描画するポリゴンの数  GrHandle:使用するグラフィックハンドル  TransFlag:透過色処理を行うかどうか( TRUE:行う  FALSE:行わない )  UVScaling:基本FALSEでOK )
extern	int			DrawPolygon2D(                           VERTEX2D  *Vertex, int PolygonNum,                                                                                              int GrHandle, int TransFlag ) ;							// ２Ｄポリゴンを描画する
extern	int			DrawPolygon3D(                           VERTEX3D  *Vertex, int PolygonNum,                                                                                              int GrHandle, int TransFlag ) ;							// ３Ｄポリゴンを描画する
extern	int			DrawPolygonIndexed2D(                    VERTEX2D  *Vertex, int VertexNum, unsigned short *Indices, int PolygonNum,                                                      int GrHandle, int TransFlag ) ;							// ２Ｄポリゴンを描画する( 頂点インデックスを使用 )
extern	int			DrawPolygonIndexed3D(                    VERTEX3D  *Vertex, int VertexNum, unsigned short *Indices, int PolygonNum,                                                      int GrHandle, int TransFlag ) ;							// ３Ｄポリゴンを描画する( 頂点インデックスを使用 )
extern	int			DrawPolygonIndexed3DBase(                VERTEX_3D *Vertex, int VertexNum, unsigned short *Indices, int IndexNum,   int PrimitiveType /* DX_PRIMTYPE_TRIANGLELIST 等 */, int GrHandle, int TransFlag ) ;							// ３Ｄポリゴンを描画する( 頂点インデックスを使用 )( 旧バージョン用 )
extern	int			DrawPolygon3DBase(                       VERTEX_3D *Vertex, int VertexNum,                                          int PrimitiveType /* DX_PRIMTYPE_TRIANGLELIST 等 */, int GrHandle, int TransFlag ) ;							// ３Ｄポリゴンを描画する( 旧バージョン用 )
extern	int			DrawPolygon3D(                           VERTEX_3D *Vertex, int PolygonNum,                                                                                              int GrHandle, int TransFlag ) ;							// ３Ｄポリゴンを描画する( 旧バージョン用 )

extern	int			DrawPolygonBase(                         VERTEX    *Vertex, int VertexNum,                                          int PrimitiveType /* DX_PRIMTYPE_TRIANGLELIST 等 */, int GrHandle, int TransFlag, int UVScaling = FALSE ) ;		// ２Ｄプリミティブを描画する
extern	int			DrawPrimitive2D(                         VERTEX2D  *Vertex, int VertexNum,                                          int PrimitiveType /* DX_PRIMTYPE_TRIANGLELIST 等 */, int GrHandle, int TransFlag ) ;							// ２Ｄプリミティブを描画する
extern	int			DrawPrimitive3D(                         VERTEX3D  *Vertex, int VertexNum,                                          int PrimitiveType /* DX_PRIMTYPE_TRIANGLELIST 等 */, int GrHandle, int TransFlag ) ;							// ３Ｄプリミティブを描画する
extern	int			DrawPrimitiveIndexed2D(                  VERTEX2D  *Vertex, int VertexNum, unsigned short *Indices, int IndexNum,   int PrimitiveType /* DX_PRIMTYPE_TRIANGLELIST 等 */, int GrHandle, int TransFlag ) ;							// ２Ｄプリミティブを描画する(頂点インデックス使用)
extern	int			DrawPrimitiveIndexed3D(                  VERTEX3D  *Vertex, int VertexNum, unsigned short *Indices, int IndexNum,   int PrimitiveType /* DX_PRIMTYPE_TRIANGLELIST 等 */, int GrHandle, int TransFlag ) ;							// ３Ｄプリミティブを描画する(頂点インデックス使用)

extern	int			DrawPolygon3D_UseVertexBuffer(           int VertexBufHandle,                                                                                                                                                               int GrHandle, int TransFlag ) ;		// 頂点バッファを使用して３Ｄポリゴンを描画する
extern	int			DrawPrimitive3D_UseVertexBuffer(         int VertexBufHandle,                     int PrimitiveType  /* DX_PRIMTYPE_TRIANGLELIST 等 */,                                                                                     int GrHandle, int TransFlag ) ;		// 頂点バッファを使用して３Ｄプリミティブを描画する
extern	int			DrawPrimitive3D_UseVertexBuffer2(        int VertexBufHandle,                     int PrimitiveType  /* DX_PRIMTYPE_TRIANGLELIST 等 */,                 int StartVertex, int UseVertexNum,                                  int GrHandle, int TransFlag ) ;		// 頂点バッファを使用して３Ｄプリミティブを描画する
extern	int			DrawPolygonIndexed3D_UseVertexBuffer(    int VertexBufHandle, int IndexBufHandle,                                                                                                                                           int GrHandle, int TransFlag ) ;		// 頂点バッファとインデックスバッファを使用して３Ｄポリゴンを描画する
extern	int			DrawPrimitiveIndexed3D_UseVertexBuffer(  int VertexBufHandle, int IndexBufHandle, int PrimitiveType  /* DX_PRIMTYPE_TRIANGLELIST 等 */,                                                                                     int GrHandle, int TransFlag ) ;		// 頂点バッファとインデックスバッファを使用して３Ｄプリミティブを描画する
extern	int			DrawPrimitiveIndexed3D_UseVertexBuffer2( int VertexBufHandle, int IndexBufHandle, int PrimitiveType  /* DX_PRIMTYPE_TRIANGLELIST 等 */, int BaseVertex, int StartVertex, int UseVertexNum, int StartIndex, int UseIndexNum, int GrHandle, int TransFlag ) ;		// 頂点バッファとインデックスバッファを使用して３Ｄプリミティブを描画する

extern	int			DrawGraph3D(                             float x, float y, float z,                                                                     int GrHandle, int TransFlag ) ;								// 画像の３Ｄ描画
extern	int			DrawExtendGraph3D(                       float x, float y, float z, double ExRateX, double ExRateY,                                     int GrHandle, int TransFlag ) ;								// 画像の拡大３Ｄ描画
extern	int			DrawRotaGraph3D(                         float x, float y, float z, double ExRate, double Angle,                                        int GrHandle, int TransFlag, int TurnFlag = FALSE ) ;		// 画像の回転３Ｄ描画
extern	int			DrawRota2Graph3D(                        float x, float y, float z, float cx, float cy, double ExtRateX, double ExtRateY, double Angle, int GrHandle, int TransFlag, int TurnFlag = FALSE ) ;		// 画像の回転３Ｄ描画(回転中心指定型)
extern	int			DrawModiBillboard3D(                     VECTOR Pos, float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4,    int GrHandle, int TransFlag ) ;								// 画像の自由変形３Ｄ描画
extern	int			DrawBillboard3D(                         VECTOR Pos, float cx, float cy, float Size, float Angle,                                       int GrHandle, int TransFlag, int TurnFlag = FALSE ) ;		// ３Ｄ空間上に画像を描画


// 描画設定関係関数
extern	int			SetDrawMode(						int DrawMode ) ;												// 描画モードを設定する
extern	int			GetDrawMode(						void ) ;														// 描画モードを取得する
extern	int			SetDrawBlendMode(					int BlendMode, int BlendParam ) ;								// 描画ブレンドモードを設定する
extern	int			GetDrawBlendMode(					int *BlendMode, int *BlendParam ) ;								// 描画ブレンドモードを取得する
extern	int			SetDrawAlphaTest(					int TestMode, int TestParam ) ;									// 描画時のアルファテストの設定を行う( TestMode:テストモード( DX_CMP_GREATER等 -1でデフォルト動作に戻す )  TestParam:描画アルファ値との比較に使用する値( 0〜255 ) )
extern	int			SetBlendGraph(						int BlendGraph, int BorderParam, int BorderRange ) ;			// ( SetBlendGraphParam の BlendType = DX_BLENDGRAPHTYPE_WIPE の処理を行う旧関数 )描画処理時に描画する画像とブレンドするαチャンネル付き画像をセットする( BlendGraph を -1 でブレンド機能を無効 )
extern	int			SetBlendGraphParam(					int BlendGraph, int BlendType, ... ) ;							// 描画処理時に描画する画像とブレンドする画像のブレンド設定を行う、BlendGraph を -1 にすれば設定を解除、その場合 BlendType とその後ろのパラメータは無視される
//		int			SetBlendGraphParam(					int BlendGraph, int BlendType = DX_BLENDGRAPHTYPE_NORMAL, int Ratio = ( 0( ブレンド率０％ )〜255( ブレンド率１００％ ) ) ) ;
//		int			SetBlendGraphParam(					int BlendGraph, int BlendType = DX_BLENDGRAPHTYPE_WIPE, int BorderParam, int BorderRange ) ;
//		int			SetBlendGraphParam(					int BlendGraph, int BlendType = DX_BLENDGRAPHTYPE_ALPHA ) ;
extern	int			SetBlendGraphPosition(				int x, int y ) ;												// ブレンド画像の起点座標をセットする
extern	int			SetDrawBright(						int RedBright, int GreenBright, int BlueBright ) ;				// 描画輝度を設定する
extern	int			GetDrawBright(						int *Red, int *Green, int *Blue ) ;								// 描画輝度を取得する
extern	int			SetIgnoreDrawGraphColor(			int EnableFlag ) ;												// 描画する画像のＲＧＢ成分を無視するかどうかを指定する( EnableFlag:この機能を使うかどうか( TRUE:使う  FALSE:使わない( デフォルト ) ) )
extern	int			SetMaxAnisotropy(					int MaxAnisotropy ) ;											// 最大異方性値を設定する

extern	int			SetUseZBufferFlag(					int Flag ) ;													// Ｚバッファを使用するかどうかを設定する( ２Ｄと３Ｄ描画に影響 )( TRUE:Ｚバッファを使用する  FALSE:Ｚバッファを使用しない( デフォルト ) )
extern	int			SetWriteZBufferFlag(				int Flag ) ;													// Ｚバッファに書き込みを行うかどうかを設定する( ２Ｄと３Ｄ描画に影響 )( TRUE:書き込みを行う  FALSE:書き込みを行わない( デフォルト ) )
extern	int			SetZBufferCmpType(					int CmpType /* DX_CMP_NEVER 等 */ ) ;							// ＺバッファのＺ値と書き込むＺ値との比較モードを設定する( ２Ｄと３Ｄ描画に影響 )( CmpType:DX_CMP_NEVER等( デフォルト:DX_CMP_LESSEQUAL ) )
extern	int			SetZBias(							int Bias ) ;													// 書き込むＺ値のバイアスを設定する( ２Ｄと３Ｄ描画に影響 )( Bias:バイアス値( デフォルト:0 ) )
extern	int			SetUseZBuffer3D(					int Flag ) ;													// Ｚバッファを使用するかどうかを設定する( ３Ｄ描画のみに影響 )( TRUE:Ｚバッファを使用する  FALSE:Ｚバッファを使用しない( デフォルト ) )
extern	int			SetWriteZBuffer3D(					int Flag ) ;													// Ｚバッファに書き込みを行うかどうかを設定する( ３Ｄ描画のみに影響 )( TRUE:書き込みを行う  FALSE:書き込みを行わない( デフォルト ) )
extern	int			SetZBufferCmpType3D(				int CmpType /* DX_CMP_NEVER 等 */ ) ;							// ＺバッファのＺ値と書き込むＺ値との比較モードを設定する( ３Ｄ描画のみに影響 )( CmpType:DX_CMP_NEVER等( デフォルト:DX_CMP_LESSEQUAL ) )
extern	int			SetZBias3D(							int Bias ) ;													// 書き込むＺ値のバイアスを設定する( ３Ｄ描画のみに影響 )( Bias:バイアス値( デフォルト:0 ) )
extern	int			SetDrawZ(							float Z ) ;														// ２Ｄ描画でＺバッファに書き込むＺ値を設定する( Z:書き込むＺ値( デフォルト:0.2f ) )

extern	int			SetDrawArea(						int x1, int y1, int x2, int y2 ) ;								// 描画可能領域の設定する
extern	int			GetDrawArea(						RECT *Rect ) ;													// 描画可能領域を取得する
extern	int			SetDrawAreaFull(					void ) ;														// 描画可能領域を描画対象画面全体にする
extern	int			SetDraw3DScale(						float Scale ) ;													// ３Ｄ描画の拡大率を設定する

extern	int			SetRestoreShredPoint(				void (* ShredPoint )( void ) ) ;								// SetRestoreGraphCallback の旧名
extern	int			SetRestoreGraphCallback(			void (* Callback )( void ) ) ;									// グラフィックハンドル復元関数を登録する
extern	int			RunRestoreShred(					void ) ;														// グラフィック復元関数を実行する
extern	int			SetGraphicsDeviceRestoreCallbackFunction( void (* Callback )( void *Data ), void *CallbackData ) ;	// グラフィックスデバイスがロストから復帰した際に呼ばれるコールバック関数を設定する
extern	int			SetGraphicsDeviceLostCallbackFunction(    void (* Callback )( void *Data ), void *CallbackData ) ;	// グラフィックスデバイスがロストから復帰する前に呼ばれるコールバック関数を設定する

extern	int			SetTransformToWorld(				MATRIX *Matrix ) ;												// ローカル座標からワールド座標に変換するための行列を設定する
extern	int			GetTransformToWorldMatrix(			MATRIX *MatBuf ) ;												// ローカル座標からワールド座標に変換するための行列を取得する
extern	int			SetTransformToView(					MATRIX *Matrix ) ;												// ワールド座標からビュー座標に変換するための行列を設定する
extern	int			GetTransformToViewMatrix(			MATRIX *MatBuf ) ;												// ワールド座標からビュー座標に変換するための行列を取得する
extern	int			SetTransformToProjection(			MATRIX *Matrix ) ;												// ビュー座標からプロジェクション座標に変換するための行列を設定する
extern	int			GetTransformToProjectionMatrix(		MATRIX *MatBuf ) ;												// ビュー座標からプロジェクション座標に変換するための行列を取得する
extern	int			SetTransformToViewport(				MATRIX *Matrix ) ;												// ビューポート行列を設定する
extern	int			GetTransformToViewportMatrix(		MATRIX *MatBuf ) ;												// ビューポート行列を取得する
extern	int			GetTransformToAPIViewportMatrix(	MATRIX *MatBuf ) ;												// Direct3Dで自動適用されるビューポート行列を取得する
extern	int			SetDefTransformMatrix(				void ) ;														// デフォルトの変換行列を設定する
extern	int			GetTransformPosition(				VECTOR *LocalPos, float *x, float *y ) ;						// ローカル座標からスクリーン座標を取得する
extern	float		GetBillboardPixelSize(				VECTOR WorldPos, float WorldSize ) ;							// ワールド空間上のビルボードのサイズからスクリーンに投影した場合のピクセル単位のサイズを取得する
extern	VECTOR		ConvWorldPosToViewPos(				VECTOR WorldPos ) ;												// ワールド座標をビュー座標に変換する
extern	VECTOR		ConvWorldPosToScreenPos(			VECTOR WorldPos ) ;												// ワールド座標をスクリーン座標に変換する
extern	FLOAT4		ConvWorldPosToScreenPosPlusW(		VECTOR WorldPos ) ;												// ワールド座標をスクリーン座標に変換する、最後のＸＹＺ座標をＷで割る前の値を得る
extern	VECTOR		ConvScreenPosToWorldPos(			VECTOR ScreenPos ) ;											// スクリーン座標をワールド座標に変換する
extern	VECTOR		ConvScreenPosToWorldPos_ZLinear(	VECTOR ScreenPos ) ;											// スクリーン座標をワールド座標に変換する( Z座標が線形 )

extern	int			SetUseCullingFlag(					int Flag ) ;													// SetUseBackCulling の旧名称
extern	int			SetUseBackCulling(					int Flag /* DX_CULLING_LEFT 等 */ ) ;							// ポリゴンカリングモードを設定する

extern	int			SetTextureAddressMode(				int Mode /* DX_TEXADDRESS_WRAP 等 */ , int Stage = -1 ) ;		// テクスチャアドレスモードを設定する
extern	int			SetTextureAddressModeUV(			int ModeU, int ModeV, int Stage = -1 ) ;						// テクスチャアドレスモードを設定する( U と V を別々に設定する )
extern	int			SetTextureAddressTransform(			float TransU, float TransV, float ScaleU, float ScaleV, float RotCenterU, float RotCenterV, float Rotate ) ;	// テクスチャ座標変換パラメータを設定する
extern	int			SetTextureAddressTransformMatrix(	MATRIX Matrix ) ;												// テクスチャ座標変換行列を設定する
extern	int			ResetTextureAddressTransform(		void ) ;														// テクスチャ座標変換設定をリセットする

extern	int			SetFogEnable(						int Flag ) ;													// フォグを有効にするかどうかを設定する( TRUE:有効  FALSE:無効 )
extern	int			SetFogMode(							int Mode /* DX_FOGMODE_NONE 等 */ ) ;							// フォグモードを設定する
extern	int			SetFogColor(						int r, int g, int b ) ;											// フォグカラーを設定する
extern	int			SetFogStartEnd(						float start, float end ) ;										// フォグが始まる距離と終了する距離を設定する( 0.0f 〜 1.0f )
extern	int			SetFogDensity(						float density ) ;												// フォグの密度を設定する( 0.0f 〜 1.0f )


// 画面関係関数
extern	int				GetPixel(									int x, int y ) ;																// 指定座標の色を取得する
extern	int				GetDrawScreenGraph(							                             int x1, int y1, int x2, int y2,                       int GrHandle, int UseClientFlag = TRUE ) ;	// 描画先の画面から指定領域の画像情報をグラフィックハンドルに転送する
extern	int				BltDrawValidGraph(							int TargetDrawValidGrHandle, int x1, int y1, int x2, int y2, int DestX, int DestY, int DestGrHandle ) ;							// SetDrawScreen で描画対象にできるグラフィックハンドルから指定領域の画像情報を別のグラフィックハンドルに転送する
extern	int				ScreenFlip(									void ) ;																		// 裏画面と表画面の内容を交換する
extern 	int				ScreenCopy(									void ) ;																		// 裏画面の内容を表画面に転送する
extern	int				WaitVSync(									int SyncNum ) ;																	// 垂直同期信号を待つ
extern	int				ClearDrawScreen(					        RECT *ClearRect = NULL ) ;														// 画面をクリアする
extern	int				ClearDrawScreenZBuffer(						RECT *ClearRect = NULL ) ;														// 画面のＺバッファをクリアする
extern	int				ClsDrawScreen(								void ) ;																		// ClearDrawScreenの旧名称
extern	int				SetDrawScreen(								int DrawScreen ) ;																// 描画先画面を設定する( MakeScreen で作成したグラフィックハンドルも渡すことができます )
extern	int				GetDrawScreen(								void ) ;																		// 描画先画面を取得する
extern	int				GetActiveGraph(								void ) ;																		// GetDrawScreen の旧名称
extern	int				SetDrawZBuffer(								int DrawScreen ) ;																// 描画先Ｚバッファのセット( DrawScreen 付属のＺバッファを描画先Ｚバッファにする、DrawScreen を -1 にするとデフォルトの描画先Ｚバッファに戻る )
#ifdef __WINDOWS__
extern	int				BltBackScreenToWindow(						HWND Window, int ClientX, int ClientY ) ;										// 裏画面の内容を指定のウインドウに転送する
extern	int				BltRectBackScreenToWindow(					HWND Window, RECT BackScreenRect, RECT WindowClientRect ) ;						// 裏画面の指定の領域をウインドウのクライアント領域の指定の領域に転送する
#endif // __WINDOWS__
extern	int				SetGraphMode(								int ScreenSizeX, int ScreenSizeY, int ColorBitDepth, int RefreshRate = 60 ) ;	// 画面モードを設定する
extern	int				SetEmulation320x240(						int Flag ) ;																	// ６４０ｘ４８０の画面で３２０ｘ２４０の画面解像度にするかどうかを設定する、６４０ｘ４８０以外の解像度では無効( TRUE:有効  FALSE:無効 )
extern	int				SetZBufferSize(								int ZBufferSizeX, int ZBufferSizeY ) ;											// 画面用のＺバッファのサイズを設定する
extern	int				SetWaitVSyncFlag(							int Flag ) ;																	// ScreenFlip 実行時にＶＳＹＮＣ待ちをするかどうかを設定する
extern	int				GetWaitVSyncFlag(							void ) ;																		// ScreenFlip 実行時にＶＳＹＮＣ待ちをするかどうかを取得する
extern	int				SetFullSceneAntiAliasingMode(				int Samples, int Quality ) ;													// 画面のフルスクリーンアンチエイリアスモードの設定を行う( DxLib_Init の前でのみ使用可能 )
extern	int				SetGraphDisplayArea(						int x1, int y1, int x2, int y2 ) ;												// ScreenFlip 時に表画面全体に転送する裏画面の領域を設定する( DxLib_Init の前でのみ使用可能 )
extern	int				SetChangeScreenModeGraphicsSystemResetFlag(	int Flag ) ;																	// 画面モード変更時( とウインドウモード変更時 )にグラフィックスシステムの設定やグラフィックハンドルをリセットするかどうかを設定する( TRUE:リセットする( デフォルト )  FALSE:リセットしない )
extern	int				GetScreenState(								int *SizeX, int *SizeY, int *ColorBitDepth ) ;									// 現在の画面の解像度とカラービット数を得る 
extern	int				GetDrawScreenSize(							int *XBuf, int *YBuf ) ;														// 描画先のサイズを取得する
extern	int				GetScreenBitDepth(							void ) ;																		// 画面のカラービット数を取得する
extern	int				GetColorBitDepth(							void ) ;																		// GetScreenBitDepth の旧名称
extern	int				GetChangeDisplayFlag(						void ) ;																		// 画面モードが変更されているかどうかを取得する
extern	int				GetVideoMemorySize(							int *AllSize, int *FreeSize ) ;													// ( 現在正常に動作しません )ビデオメモリの容量を得る
extern	int				GetRefreshRate(								void ) ;																		// 現在の画面のリフレッシュレートを取得する
extern	int				GetDisplayModeNum(							void ) ;																		// 変更可能なディスプレイモードの数を取得する
extern	DISPLAYMODEDATA	GetDisplayMode(								int ModeIndex ) ;																// 変更可能なディスプレイモードの情報を取得する( ModeIndex は 0 〜 GetDisplayModeNum の戻り値-1 )
extern	COLORDATA*		GetDispColorData(							void ) ;																		// ディスプレイのカラーデータアドレスを取得する
extern	int				GetMultiDrawScreenNum(						void ) ;																		// 同時に描画を行うことができる画面の数を取得する
extern	int				SetDisplayRefreshRate(						int RefreshRate ) ;																// ( 現在効果なし )フルスクリーン時の画面のリフレッシュレートを変更する

// その他設定関係関数
extern	int			SetUseNormalDrawShader(						int Flag ) ;									// 通常描画にプログラマブルシェーダーを使用するかどうかを設定する( TRUE:使用する( デフォルト )  FALSE:使用しない )
extern	int			SetUseSoftwareRenderModeFlag(				int Flag ) ;									// ソフトウエアレンダリングモードを使用するかどうかを設定する( TRUE:使用する  FALSE:使用しない( デフォルト ) )( DxLib_Init の前に呼ぶ必要があります )
extern	int			SetNotUse3DFlag(							int Flag ) ;									// ( 同効果のSetUseSoftwareRenderModeFlag を使用して下さい )３Ｄ機能を使わないかどうかを設定する
extern	int			SetUse3DFlag(								int Flag ) ;									// ( 同効果のSetUseSoftwareRenderModeFlag を使用して下さい )３Ｄ機能を使うかどうかを設定する
extern	int			GetUse3DFlag(								void ) ;										// 描画に３Ｄ機能を使うかどうかを取得する
extern	int			SetScreenMemToVramFlag(						int Flag ) ;									// ( 同効果のSetUseSoftwareRenderModeFlag を使用して下さい )画面のピクセルデータをＶＲＡＭに置くかどうかを設定する
extern	int			GetScreenMemToSystemMemFlag(				void ) ;										// 画面のピクセルデータがシステムメモリ上に存在するかを取得する

extern	int			SetWindowDrawRect(							RECT *DrawRect ) ;								// 通常使用しない
extern	int			RestoreGraphSystem(							void ) ;										// ＤＸライブラリのグラフィックス処理関連の復帰処理を行う
extern	int			SetAeroDisableFlag(							int Flag ) ;									// Vista,7 の Windows Aero を無効にするかどうかを設定する( TRUE:無効にする( デフォルト )  FALSE:有効にする )( DxLib_Init の前に呼ぶ必要があります )
extern	int			SetUseDirect3D9Ex(							int Flag ) ;									// Vista以降の環境で Direct3D9Ex を使用するかどうかを設定する( TRUE:使用する( デフォルト )  FALSE:使用しない )( DxLib_Init の前に呼ぶ必要があります )
extern	int			SetUseHardwareVertexProcessing(				int Flag ) ;									// ハードウエアの頂点演算処理機能を使用するかどうかを設定する( TRUE:使用する( デフォルト )  FALSE:使用しない )( DxLib_Init の前に呼ぶ必要があります )
extern	int			SetMultiThreadFlag(							int Flag ) ;									// DirectDraw や Direct3D の協調レベルをマルチスレッド対応にするかどうかをセットする( TRUE:マルチスレッド対応にする  FALSE:マルチスレッド対応にしない( デフォルト ) )
extern	int			SetUseDirectDrawDeviceIndex(				int Index ) ;									// 使用する DirectDraw デバイスのインデックスを設定する
extern	int			SetUseOldDrawModiGraphCodeFlag(				int Flag ) ;									// 古いバージョンの DrawModiGraph 関数のコードを使用するかどうかを設定する
extern	int			SetUseVramFlag(								int Flag ) ;									// ( 現在効果なし )ＶＲＡＭを使用するかのフラグをセットする
extern	int			GetUseVramFlag(								void ) ;										// ( 現在効果なし )２Ｄグラフィックサーフェス作成時にシステムメモリーを使用するかのフラグ取得
extern	int			SetBasicBlendFlag(							int Flag ) ;									// ( 現在効果なし )簡略化ブレンド処理を行うか否かのフラグをセットする
extern	int			SetUseBasicGraphDraw3DDeviceMethodFlag(		int Flag ) ;									// ( 現在効果なし )単純図形の描画に３Ｄデバイスの機能を使用するかどうかを設定する
#ifdef __WINDOWS__
extern	int			SetUseDirectDrawFlag(						int Flag ) ;									// ( 同効果のSetUseSoftwareRenderModeFlag を使用して下さい )DirectDrawを使用するかどうかを設定する
extern	int			SetUseGDIFlag(								int Flag ) ;									// GDI描画を使用するかどうかを設定する
extern	int			GetUseGDIFlag(								void ) ;										// GDI描画を使用するかどうかを取得する
extern	int			SetDDrawUseGuid(							GUID *Guid ) ;									// DirectDrawが使用するGUIDを設定する
extern	void*		GetUseDDrawObj(								void ) ;										// 現在使用しているDirectDrawオブジェクトのアドレスを取得する( 戻り値を IDirectDraw7 * にキャストして下さい )
extern	GUID*		GetDirectDrawDeviceGUID(					int Number ) ;									// 有効な DirectDraw デバイスの GUID を取得する
extern	int			GetDirectDrawDeviceDescription(				int Number, char *StringBuffer ) ;				// 有効な DirectDraw デバイスの名前を取得する
extern	int			GetDirectDrawDeviceNum(						void ) ;										// 有効な DirectDraw デバイスの数を取得する
extern	DX_DIRECT3DDEVICE9* GetUseDirect3DDevice9(				void ) ;										// 使用中のDirect3DDevice9オブジェクトを取得する
extern	DX_DIRECT3DSURFACE9* GetUseDirect3D9BackBufferSurface(	void ) ;										// 使用中のバックバッファのDirect3DSurface9オブジェクトを取得する
#endif // __WINDOWS__
extern	int			RefreshDxLibDirect3DSetting(				void ) ;										// ＤＸライブラリが行ったDirect3Dの設定を再度行う( 特殊用途 )
extern	int			RenderVertex(								void ) ;										// 頂点バッファに溜まった頂点データを描画する( 特殊用途 )

#ifndef DX_NON_SAVEFUNCTION

// 描画先画面保存関数
// Jpeg_Quality         = 0:低画質〜100:高画質
// Png_CompressionLevel = 0:無圧縮〜  9:最高圧縮
extern	int			SaveDrawScreen(       int x1, int y1, int x2, int y2, const TCHAR *FileName, int SaveType = DX_IMAGESAVETYPE_BMP , int Jpeg_Quality = 80 , int Jpeg_Sample2x1 = TRUE , int Png_CompressionLevel = -1 ) ;		// 現在描画対象になっている画面をファイルで保存する
extern	int			SaveDrawScreenToBMP(  int x1, int y1, int x2, int y2, const TCHAR *FileName ) ;																																	// 現在描画対象になっている画面をＢＭＰ形式で保存する
extern	int			SaveDrawScreenToJPEG( int x1, int y1, int x2, int y2, const TCHAR *FileName, int Quality = 80 , int Sample2x1 = TRUE ) ;																						// 現在描画対象になっている画面をＪＰＥＧ形式で保存する Quality = 画質、値が大きいほど低圧縮高画質,0〜100 
extern	int			SaveDrawScreenToPNG(  int x1, int y1, int x2, int y2, const TCHAR *FileName, int CompressionLevel = -1 ) ;																										// 現在描画対象になっている画面をＰＮＧ形式で保存する CompressionLevel = 圧縮率、値が大きいほど高圧縮率高負荷、０は無圧縮,0〜9

#endif // DX_NON_SAVEFUNCTION

// 頂点バッファ関係関数
extern	int			CreateVertexBuffer(		int VertexNum, int VertexType /* DX_VERTEX_TYPE_NORMAL_3D 等 */ ) ;						// 頂点バッファを作成する( -1:エラー  0以上:頂点バッファハンドル )
extern	int			DeleteVertexBuffer(		int VertexBufHandle ) ;																	// 頂点バッファを削除する
extern	int			InitVertexBuffer(		void ) ;																				// すべての頂点バッファを削除する
extern	int			SetVertexBufferData(	int SetIndex, void *VertexData, int VertexNum, int VertexBufHandle ) ;					// 頂点バッファに頂点データを転送する
extern	int			CreateIndexBuffer(		int IndexNum, int IndexType /* DX_INDEX_TYPE_16BIT 等 */  ) ;							// インデックスバッファを作成する( -1:エラー　0以上：インデックスバッファハンドル )
extern	int			DeleteIndexBuffer(		int IndexBufHandle ) ;																	// インデックスバッファを削除する
extern	int			InitIndexBuffer(		void ) ;																				// すべてのインデックスバッファを削除する
extern	int			SetIndexBufferData(		int SetIndex, void *IndexData, int IndexNum, int IndexBufHandle ) ;						// インデックスバッファにインデックスデータを転送する

// シェーダー関係関数
extern	int			GetValidShaderVersion(		void ) ;												// 使用できるシェーダーのバージョンを取得する( 0=使えない  200=シェーダーモデル２．０が使用可能  300=シェーダーモデル３．０が使用可能 )

extern	int			LoadVertexShader(			const TCHAR *FileName ) ;								// 頂点シェーダーバイナリをファイルから読み込み頂点シェーダーハンドルを作成する( 戻り値 -1:エラー  -1以外:シェーダーハンドル )
extern	int			LoadPixelShader(			const TCHAR *FileName ) ;								// ピクセルシェーダーバイナリをファイルから読み込みピクセルシェーダーハンドルを作成する( 戻り値 -1:エラー  -1以外:シェーダーハンドル )
extern	int			LoadVertexShaderFromMem(	void *ImageAddress, int ImageSize ) ;					// メモリに読み込まれた頂点シェーダーバイナリから頂点シェーダーハンドルを作成する( 戻り値 -1:エラー  -1以外:シェーダーハンドル )
extern	int			LoadPixelShaderFromMem(		void *ImageAddress, int ImageSize ) ;					// メモリに読み込まれたピクセルシェーダーバイナリからピクセルシェーダーハンドルを作成する( 戻り値 -1:エラー  -1以外:シェーダーハンドル )
extern	int			DeleteShader(				int ShaderHandle ) ;									// シェーダーハンドルの削除( 頂点シェーダー・ピクセルシェーダー共通 )
extern	int			InitShader(					void ) ;												// シェーダーハンドルを全て削除する( 頂点シェーダーハンドル・ピクセルシェーダーハンドルどちらもすべて削除 )

extern	int			GetConstIndexToShader(           const TCHAR *ConstantName, int ShaderHandle ) ;	// 指定の名前を持つ定数が使用するシェーダー定数の番号を取得する
extern	int			GetConstCountToShader(           const TCHAR *ConstantName, int ShaderHandle ) ;	// 指定の名前を持つ定数が使用するシェーダー定数の数を取得する
extern	const FLOAT4 *GetConstDefaultParamFToShader( const TCHAR *ConstantName, int ShaderHandle ) ;	// 指定の名前を持つ浮動小数点数定数のデフォルトパラメータが格納されているメモリアドレスを取得する
extern	int			SetVSConstSF(         int ConstantIndex, float  Param ) ;							// 頂点シェーダーの float 型定数を設定する
extern	int			SetVSConstF(          int ConstantIndex, FLOAT4 Param ) ;							// 頂点シェーダーの float 型定数を設定する
extern	int			SetVSConstFMtx(       int ConstantIndex, MATRIX Param ) ;							// 頂点シェーダーの float 型定数に行列を設定する
extern	int			SetVSConstFMtxT(      int ConstantIndex, MATRIX Param ) ;							// 頂点シェーダーの float 型定数に転置した行列を設定する
extern	int			SetVSConstSI(         int ConstantIndex, int    Param ) ;							// 頂点シェーダーの int   型定数を設定する
extern	int			SetVSConstI(          int ConstantIndex, INT4   Param ) ;							// 頂点シェーダーの int   型定数を設定する
extern	int			SetVSConstB(          int ConstantIndex, BOOL   Param ) ;							// 頂点シェーダーの BOOL  型定数を設定する
extern	int			SetVSConstSFArray(    int ConstantIndex, float  *ParamArray, int ParamNum ) ;		// 頂点シェーダーの float 型定数を設定する( 配列を使って連番インデックスに一度に設定 )
extern	int			SetVSConstFArray(     int ConstantIndex, FLOAT4 *ParamArray, int ParamNum ) ;		// 頂点シェーダーの float 型定数を設定する( 配列を使って連番インデックスに一度に設定 )
extern	int			SetVSConstFMtxArray(  int ConstantIndex, MATRIX *ParamArray, int ParamNum ) ;		// 頂点シェーダーの float 型定数に行列を設定する( 配列を使って連番インデックスに一度に設定 )
extern	int			SetVSConstFMtxTArray( int ConstantIndex, MATRIX *ParamArray, int ParamNum ) ;		// 頂点シェーダーの float 型定数に転置した行列を設定する( 配列を使って連番インデックスに一度に設定 )
extern	int			SetVSConstSIArray(    int ConstantIndex, int    *ParamArray, int ParamNum ) ;		// 頂点シェーダーの int   型定数を設定する( 配列を使って連番インデックスに一度に設定 )
extern	int			SetVSConstIArray(     int ConstantIndex, INT4   *ParamArray, int ParamNum ) ;		// 頂点シェーダーの int   型定数を設定する( 配列を使って連番インデックスに一度に設定 )
extern	int			SetVSConstBArray(     int ConstantIndex, BOOL   *ParamArray, int ParamNum ) ;		// 頂点シェーダーの BOOL  型定数を設定する( 配列を使って連番インデックスに一度に設定 )
extern	int			ResetVSConstF(        int ConstantIndex, int ParamNum ) ;							// 頂点シェーダーの float 型定数の設定をリセットする
extern	int			ResetVSConstI(        int ConstantIndex, int ParamNum ) ;							// 頂点シェーダーの int   型定数の設定をリセットする
extern	int			ResetVSConstB(        int ConstantIndex, int ParamNum ) ;							// 頂点シェーダーの BOOL  型定数の設定をリセットする

extern	int			SetPSConstSF(         int ConstantIndex, float  Param ) ;							// ピクセルシェーダーの float 型定数を設定する
extern	int			SetPSConstF(          int ConstantIndex, FLOAT4 Param ) ;							// ピクセルシェーダーの float 型定数を設定する
extern	int			SetPSConstFMtx(       int ConstantIndex, MATRIX Param ) ;							// ピクセルシェーダーの float 型定数に行列を設定する
extern	int			SetPSConstFMtxT(      int ConstantIndex, MATRIX Param ) ;							// ピクセルシェーダーの float 型定数に転置した行列を設定する
extern	int			SetPSConstSI(         int ConstantIndex, int    Param ) ;							// ピクセルシェーダーの int   型定数を設定する
extern	int			SetPSConstI(          int ConstantIndex, INT4   Param ) ;							// ピクセルシェーダーの int   型定数を設定する
extern	int			SetPSConstB(          int ConstantIndex, BOOL   Param ) ;							// ピクセルシェーダーの BOOL  型定数を設定する
extern	int			SetPSConstSFArray(    int ConstantIndex, float  *ParamArray, int ParamNum ) ;		// ピクセルシェーダーの float 型定数を設定する( 配列を使って連番インデックスに一度に設定 )
extern	int			SetPSConstFArray(     int ConstantIndex, FLOAT4 *ParamArray, int ParamNum ) ;		// ピクセルシェーダーの float 型定数を設定する( 配列を使って連番インデックスに一度に設定 )
extern	int			SetPSConstFMtxArray(  int ConstantIndex, MATRIX *ParamArray, int ParamNum ) ;		// ピクセルシェーダーの float 型定数に行列を設定する( 配列を使って連番インデックスに一度に設定 )
extern	int			SetPSConstFMtxTArray( int ConstantIndex, MATRIX *ParamArray, int ParamNum ) ;		// ピクセルシェーダーの float 型定数に転置した行列を設定する( 配列を使って連番インデックスに一度に設定 )
extern	int			SetPSConstSIArray(    int ConstantIndex, int    *ParamArray, int ParamNum ) ;		// ピクセルシェーダーの int   型定数を設定する( 配列を使って連番インデックスに一度に設定 )
extern	int			SetPSConstIArray(     int ConstantIndex, INT4   *ParamArray, int ParamNum ) ;		// ピクセルシェーダーの int   型定数を設定する( 配列を使って連番インデックスに一度に設定 )
extern	int			SetPSConstBArray(     int ConstantIndex, BOOL   *ParamArray, int ParamNum ) ;		// ピクセルシェーダーの BOOL  型定数を設定する( 配列を使って連番インデックスに一度に設定 )
extern	int			ResetPSConstF(        int ConstantIndex, int ParamNum ) ;							// ピクセルシェーダーの float 型定数の設定をリセットする
extern	int			ResetPSConstI(        int ConstantIndex, int ParamNum ) ;							// ピクセルシェーダーの int   型定数の設定をリセットする
extern	int			ResetPSConstB(        int ConstantIndex, int ParamNum ) ;							// ピクセルシェーダーの BOOL  型定数の設定をリセットする

extern	int			SetRenderTargetToShader( int TargetIndex, int DrawScreen ) ;						// シェーダーを使用した描画での描画先を設定する
extern	int			SetUseTextureToShader(   int StageIndex, int GraphHandle ) ;						// シェーダーを使用した描画で使用するグラフィックハンドルを設定する
extern	int			SetUseVertexShader(      int ShaderHandle ) ;										// シェーダーを使用した描画に使用する頂点シェーダーを設定する( -1を渡すと解除 )
extern	int			SetUsePixelShader(       int ShaderHandle ) ;										// シェーダーを使用した描画に使用するピクセルシェーダーを設定する( -1を渡すと解除 )

extern	int			CalcPolygonBinormalAndTangentsToShader(        VERTEX3DSHADER *Vertex, int PolygonNum ) ;												// ポリゴンの頂点の接線と従法線をＵＶ座標から計算してセットする
extern	int			CalcPolygonIndexedBinormalAndTangentsToShader( VERTEX3DSHADER *Vertex, int VertexNum, unsigned short *Indices, int PolygonNum ) ;		// ポリゴンの頂点の接線と従法線をＵＶ座標から計算してセットする( 頂点インデックスを使用する )

extern	int			DrawPolygon2DToShader(          VERTEX2DSHADER *Vertex, int PolygonNum ) ;																												// シェーダーを使って２Ｄポリゴンを描画する
extern	int			DrawPolygon3DToShader(          VERTEX3DSHADER *Vertex, int PolygonNum ) ;																												// シェーダーを使って３Ｄポリゴンを描画する
extern	int			DrawPolygonIndexed2DToShader(   VERTEX2DSHADER *Vertex, int VertexNum, unsigned short *Indices, int PolygonNum ) ;																		// シェーダーを使って２Ｄポリゴンを描画する( 頂点インデックスを使用する )
extern	int			DrawPolygonIndexed3DToShader(   VERTEX3DSHADER *Vertex, int VertexNum, unsigned short *Indices, int PolygonNum ) ;																		// シェーダーを使って３Ｄポリゴンを描画する( 頂点インデックスを使用する )
extern	int			DrawPrimitive2DToShader(        VERTEX2DSHADER *Vertex, int VertexNum,                                        int PrimitiveType /* DX_PRIMTYPE_TRIANGLELIST 等 */ ) ;					// シェーダーを使って２Ｄプリミティブを描画する
extern	int			DrawPrimitive3DToShader(        VERTEX3DSHADER *Vertex, int VertexNum,                                        int PrimitiveType /* DX_PRIMTYPE_TRIANGLELIST 等 */ ) ;					// シェーダーを使って３Ｄプリミティブを描画する
extern	int			DrawPrimitiveIndexed2DToShader( VERTEX2DSHADER *Vertex, int VertexNum, unsigned short *Indices, int IndexNum, int PrimitiveType /* DX_PRIMTYPE_TRIANGLELIST 等 */ ) ;					// シェーダーを使って２Ｄプリミティブを描画する( 頂点インデックスを使用する )
extern	int			DrawPrimitiveIndexed3DToShader( VERTEX3DSHADER *Vertex, int VertexNum, unsigned short *Indices, int IndexNum, int PrimitiveType /* DX_PRIMTYPE_TRIANGLELIST 等 */ ) ;					// シェーダーを使って３Ｄプリミティブを描画する( 頂点インデックスを使用する )
extern	int			DrawPolygon3DToShader_UseVertexBuffer(           int VertexBufHandle ) ;																												// シェーダーを使って３Ｄポリゴンを描画する( 頂点バッファ使用版 )
extern	int			DrawPolygonIndexed3DToShader_UseVertexBuffer(    int VertexBufHandle, int IndexBufHandle ) ;																							// シェーダーを使って３Ｄポリゴンを描画する( 頂点バッファとインデックスバッファ使用版 )
extern	int			DrawPrimitive3DToShader_UseVertexBuffer(         int VertexBufHandle,                     int PrimitiveType /* DX_PRIMTYPE_TRIANGLELIST 等 */ ) ;										// シェーダーを使って３Ｄプリミティブを描画する( 頂点バッファ使用版 )
extern	int			DrawPrimitive3DToShader_UseVertexBuffer2(        int VertexBufHandle,                     int PrimitiveType /* DX_PRIMTYPE_TRIANGLELIST 等 */, int StartVertex, int UseVertexNum ) ;	// シェーダーを使って３Ｄプリミティブを描画する( 頂点バッファ使用版 )
extern	int			DrawPrimitiveIndexed3DToShader_UseVertexBuffer(  int VertexBufHandle, int IndexBufHandle, int PrimitiveType /* DX_PRIMTYPE_TRIANGLELIST 等 */ ) ;										// シェーダーを使って３Ｄプリミティブを描画する( 頂点バッファとインデックスバッファ使用版 )
extern	int			DrawPrimitiveIndexed3DToShader_UseVertexBuffer2( int VertexBufHandle, int IndexBufHandle, int PrimitiveType /* DX_PRIMTYPE_TRIANGLELIST 等 */, int BaseVertex, int StartVertex, int UseVertexNum, int StartIndex, int UseIndexNum ) ;	// シェーダーを使って３Ｄプリミティブを描画する( 頂点バッファとインデックスバッファ使用版 )

// フィルター関係関数
#ifndef DX_NON_FILTER
extern	int			GraphFilter(         int    GrHandle,                                                                                                               int FilterType /* DX_GRAPH_FILTER_GAUSS 等 */ , ... ) ;		// 画像にフィルター処理を行う
extern	int			GraphFilterBlt(      int SrcGrHandle, int DestGrHandle,                                                                                             int FilterType /* DX_GRAPH_FILTER_GAUSS 等 */ , ... ) ;		// 画像のフィルター付き転送を行う
extern	int			GraphFilterRectBlt(  int SrcGrHandle, int DestGrHandle, int SrcX1, int SrcY1, int SrcX2, int SrcY2, int DestX,  int DestY,                          int FilterType /* DX_GRAPH_FILTER_GAUSS 等 */ , ... ) ;		// 画像のフィルター付き転送を行う( 矩形指定 )
//		int			GraphFilter( int GrHandle, int FilterType = DX_GRAPH_FILTER_MONO, int Cb = 青色差( -255 〜 255 ), int Cr = 赤色差( -255 〜 255 ) ) ;
//		int			GraphFilter( int GrHandle, int FilterType = DX_GRAPH_FILTER_GAUSS, int PixelWidth = 使用ピクセル幅( 8 , 16 , 32 の何れか ), int Param = ぼかしパラメータ( 100 で約1ピクセル分の幅 ) ) ;
//		int			GraphFilter( int GrHandle, int FilterType = DX_GRAPH_FILTER_DOWN_SCALE, int DivNum = 元のサイズの何分の１か、という値( 2 , 4 , 8 の何れか ) ) ;
//		int			GraphFilter( int GrHandle, int FilterType = DX_GRAPH_FILTER_BRIGHT_CLIP, int CmpType = クリップタイプ( DX_CMP_LESS:CmpParam以下をクリップ  又は  DX_CMP_GREATER:CmpParam以上をクリップ ), int CmpParam = クリップパラメータ( 0 〜 255 ), int ClipFillFlag = クリップしたピクセルを塗りつぶすかどうか( TRUE:塗りつぶす  FALSE:塗りつぶさない ), int ClipFillColor = クリップしたピクセルに塗る色値( GetColor で取得する )( ClipFillFlag が FALSE の場合は使用しない ), int ClipFillAlpha = クリップしたピクセルに塗るα値( 0 〜 255 )( ClipFillFlag が FALSE の場合は使用しない ) ) ;
//		int			GraphFilter( int GrHandle, int FilterType = DX_GRAPH_FILTER_HSB, int HueType = Hue の意味( 0:相対値  1:絶対値 ), int Hue = 色相パラメータ( HueType が 0 の場合 = ピクセルの色相に対する相対値( -180 〜 180 )   HueType が 1 の場合 = 色相の絶対値( 0 〜 360 ) ), int Saturation = 彩度( -255 〜 ), int Bright = 輝度( -255 〜 255 ) ) ;
//		int			GraphFilter( int GrHandle, int FilterType = DX_GRAPH_FILTER_INVERT ) ;
//		int			GraphFilter( int GrHandle, int FilterType = DX_GRAPH_FILTER_LEVEL, int Min = 変換元の下限値( 0 〜 255 ), int Max = 変換元の上限値( 0 〜 255 ), int Gamma = ガンマ値( 100 でガンマ補正無し、0 とそれ以下の値は不可 ), int AfterMin = 変換後の最低値( 0 〜 255 ), int AfterMax = 変換後の最大値( 0 〜 255 ) ) ;
//		int			GraphFilter( int GrHandle, int FilterType = DX_GRAPH_FILTER_TWO_COLOR, int Threshold = 閾値( 0 〜 255 ), int LowColor = 閾値より値が低かったピクセルの変換後の色値( GetColor で取得する ), int LowAlpha = 閾値より値が低かったピクセルの変換後のα値( 0 〜 255 ), int HighColor = 閾値より値が高かったピクセルの変換後の色値( GetColor で取得する ), int HighAlpha = 閾値より値が高かったピクセルの変換後のα値( 0 〜 255 ) ) ;
//		int			GraphFilter( int GrHandle, int FilterType = DX_GRAPH_FILTER_GRADIENT_MAP, int MapGrHandle = グラデーションマップのグラフィックハンドル( 元画像の輝度からグラデーションマップ画像の x 座標を算出しますので縦幅は1dotでもＯＫ ), int Reverse = グラデーションマップ左右反転フラグ( TRUE : グラデーションマップを左右反転して使う  FALSE : 左右反転しない ) ) ;

extern	int			GraphBlend(         int    GrHandle, int BlendGrHandle,                                                                                                                                         int BlendRatio /* ブレンド効果の影響度( 0:０％  255:１００％ ) */ , int BlendType /* DX_GRAPH_BLEND_ADD 等 */ , ... ) ;	// 二つの画像をブレンドする
extern	int			GraphBlendBlt(      int SrcGrHandle, int BlendGrHandle, int DestGrHandle,                                                                                                                       int BlendRatio /* ブレンド効果の影響度( 0:０％  255:１００％ ) */ , int BlendType /* DX_GRAPH_BLEND_ADD 等 */ , ... ) ;	// 二つの画像をブレンドして結果を指定の画像に出力する
extern	int			GraphBlendRectBlt(  int SrcGrHandle, int BlendGrHandle, int DestGrHandle, int SrcX1, int SrcY1, int SrcX2, int SrcY2, int BlendX,  int BlendY,                            int DestX, int DestY, int BlendRatio /* ブレンド効果の影響度( 0:０％  255:１００％ ) */ , int BlendType /* DX_GRAPH_BLEND_ADD 等 */ , ... ) ;	// 二つの画像をブレンドして結果を指定の画像に出力する( 矩形指定 )
//		int			GraphBlend( int GrHandle, int BlendGrHandle, int BlendRatio, int BlendType = DX_GRAPH_BLEND_NORMAL ) ;
//		int			GraphBlend( int GrHandle, int BlendGrHandle, int BlendRatio, int BlendType = DX_GRAPH_BLEND_RGBA_SELECT_MIX, int SelectR = ( 出力の赤分となる成分 DX_RGBA_SELECT_SRC_R 等 ), int SelectG = ( 出力の緑成分となる成分 DX_RGBA_SELECT_SRC_R 等 ), int SelectB = ( 出力の青成分となる成分 DX_RGBA_SELECT_SRC_R 等 ), int SelectA = ( 出力のα成分となる成分 DX_RGBA_SELECT_SRC_R 等 ) ) ;
//		int			GraphBlend( int GrHandle, int BlendGrHandle, int BlendRatio, int BlendType = DX_GRAPH_BLEND_MULTIPLE ) ;
//		int			GraphBlend( int GrHandle, int BlendGrHandle, int BlendRatio, int BlendType = DX_GRAPH_BLEND_DIFFERENCE ) ;
//		int			GraphBlend( int GrHandle, int BlendGrHandle, int BlendRatio, int BlendType = DX_GRAPH_BLEND_ADD ) ;
//		int			GraphBlend( int GrHandle, int BlendGrHandle, int BlendRatio, int BlendType = DX_GRAPH_BLEND_SCREEN ) ;
//		int			GraphBlend( int GrHandle, int BlendGrHandle, int BlendRatio, int BlendType = DX_GRAPH_BLEND_OVERLAY ) ;
//		int			GraphBlend( int GrHandle, int BlendGrHandle, int BlendRatio, int BlendType = DX_GRAPH_BLEND_DODGE ) ;
//		int			GraphBlend( int GrHandle, int BlendGrHandle, int BlendRatio, int BlendType = DX_GRAPH_BLEND_BURN ) ;
//		int			GraphBlend( int GrHandle, int BlendGrHandle, int BlendRatio, int BlendType = DX_GRAPH_BLEND_DARKEN ) ;
//		int			GraphBlend( int GrHandle, int BlendGrHandle, int BlendRatio, int BlendType = DX_GRAPH_BLEND_LIGHTEN ) ;
//		int			GraphBlend( int GrHandle, int BlendGrHandle, int BlendRatio, int BlendType = DX_GRAPH_BLEND_SOFTLIGHT ) ;
//		int			GraphBlend( int GrHandle, int BlendGrHandle, int BlendRatio, int BlendType = DX_GRAPH_BLEND_HARDLIGHT ) ;
//		int			GraphBlend( int GrHandle, int BlendGrHandle, int BlendRatio, int BlendType = DX_GRAPH_BLEND_EXCLUSION ) ;
//		int			GraphBlend( int GrHandle, int BlendGrHandle, int BlendRatio, int BlendType = DX_GRAPH_BLEND_HUE ) ;
//		int			GraphBlend( int GrHandle, int BlendGrHandle, int BlendRatio, int BlendType = DX_GRAPH_BLEND_SATURATION ) ;
//		int			GraphBlend( int GrHandle, int BlendGrHandle, int BlendRatio, int BlendType = DX_GRAPH_BLEND_COLOR ) ;
//		int			GraphBlend( int GrHandle, int BlendGrHandle, int BlendRatio, int BlendType = DX_GRAPH_BLEND_BRIGHT ) ;
#endif // DX_NON_FILTER

#ifndef DX_NON_MOVIE
// ムービーグラフィック関係関数
extern	int			PlayMovie(						const TCHAR *FileName, int ExRate, int PlayType ) ;						// 動画ファイルの再生
extern	int			OpenMovieToGraph(				const TCHAR *FileName, int FullColor = TRUE ) ;							// 動画ファイルを開く
extern 	int			PlayMovieToGraph(				int GraphHandle, int PlayType = DX_PLAYTYPE_BACK , int SysPlay = 0 ) ;	// 動画ファイルを使用するグラフィックハンドルの動画ファイルの再生を開始する
extern 	int			PauseMovieToGraph(				int GraphHandle, int SysPause = 0 ) ;									// 動画ファイルを使用するグラフィックハンドルの動画ファイルの再生を停止する
extern	int			AddMovieFrameToGraph(			int GraphHandle, unsigned int FrameNum ) ;								// 動画ファイルの再生フレームを進める、戻すことは出来ない( 動画ファイルが停止状態で、且つ Ogg Theora のみ有効 )
extern	int			SeekMovieToGraph(				int GraphHandle, int Time ) ;											// 動画ファイルの再生位置を設定する(ミリ秒単位)
extern 	int			GetMovieStateToGraph(			int GraphHandle ) ;														// 動画ファイルの再生状態を得る
extern	int			SetMovieVolumeToGraph(			int Volume, int GraphHandle ) ;											// 動画ファイルの音量を設定する(0〜10000)
extern	int			ChangeMovieVolumeToGraph(		int Volume, int GraphHandle ) ;											// 動画ファイルの音量を設定する(0〜255)
extern	BASEIMAGE*	GetMovieBaseImageToGraph(		int GraphHandle ) ;														// 動画ファイルの基本イメージデータを取得する
extern	int			GetMovieTotalFrameToGraph(		int GraphHandle ) ;														// 動画ファイルの総フレーム数を得る( Ogg Theora でのみ有効 )
extern	int			TellMovieToGraph(				int GraphHandle ) ;														// 動画ファイルの再生位置を取得する(ミリ秒単位)
extern	int			TellMovieToGraphToFrame(		int GraphHandle ) ;														// 動画ファイルの再生位置を取得する(フレーム単位)
extern	int			SeekMovieToGraphToFrame(		int GraphHandle, int Frame ) ;											// 動画ファイルの再生位置を設定する(フレーム単位)
extern	LONGLONG	GetOneFrameTimeMovieToGraph(	int GraphHandle ) ;														// 動画ファイルの１フレームあたりの時間を取得する
extern	int			GetLastUpdateTimeMovieToGraph(	int GraphHandle ) ;														// 動画ファイルのイメージを最後に更新した時間を得る(ミリ秒単位)
extern	int			SetMovieRightImageAlphaFlag(	int Flag ) ;															// 動画ファイル映像の右半分の赤成分をα情報として扱うかどうかをセットする( TRUE:α情報として扱う  FALSE:α情報として扱わない( デフォルト ) )
#endif // DX_NON_MOVIE

// カメラ関係関数
extern	int			SetCameraNearFar(					float Near, float Far ) ;											// カメラの Nearクリップ面と Farクリップ面の距離を設定する
extern	int			SetCameraPositionAndTarget_UpVecY(  VECTOR Position, VECTOR Target ) ;									// カメラの視点、注視点、アップベクトルを設定する( アップベクトルはＹ軸方向から導き出す )
extern	int			SetCameraPositionAndTargetAndUpVec( VECTOR Position, VECTOR TargetPosition, VECTOR UpVector ) ;			// カメラの視点、注視点、アップベクトルを設定する
extern	int			SetCameraPositionAndAngle(			VECTOR Position, float VRotate, float HRotate, float TRotate ) ;	// カメラの視点、注視点、アップベクトルを設定する( 注視点とアップベクトルは垂直回転角度、水平回転角度、捻り回転角度から導き出す )
extern	int			SetCameraViewMatrix(				MATRIX ViewMatrix ) ;												// ビュー行列を直接設定する
extern	int			SetCameraScreenCenter(				float x, float y ) ;												// 画面上におけるカメラが見ている映像の中心の座標を設定する

extern	int			SetupCamera_Perspective(			float Fov ) ;														// 遠近法カメラをセットアップする
extern	int			SetupCamera_Ortho(					float Size ) ;														// 正射影カメラをセットアップする
extern	int			SetupCamera_ProjectionMatrix(		MATRIX ProjectionMatrix ) ;											// 射影行列を直接設定する
extern	int			SetCameraDotAspect(					float DotAspect ) ;													// カメラのドットアスペクト比を設定する

extern	int			CheckCameraViewClip(				VECTOR CheckPos ) ;													// 指定の座標がカメラの視界に入っているかどうかを判定する( 戻り値 TRUE:視界に入っていない  FALSE:視界に入っている )
extern	int			CheckCameraViewClip_Dir(			VECTOR CheckPos ) ;													// 指定の座標がカメラの視界に入っているかどうかを判定する、戻り値で外れている方向も知ることができる( 戻り値 0:視界に入っている  0以外:視界に入っていない( DX_CAMERACLIP_LEFT や DX_CAMERACLIP_RIGHT が or 演算で混合されたもの、and 演算で方向を確認できる ) )
extern	int			CheckCameraViewClip_Box(			VECTOR BoxPos1, VECTOR BoxPos2 ) ;									// 二つの座標で表されるボックスがカメラの視界に入っているかどうかを判定する( 戻り値 TRUE:視界に入っていない  FALSE:視界に入っている )

extern	float		GetCameraNear(						void ) ;															// カメラの Near クリップ面の距離を取得する
extern	float		GetCameraFar(						void ) ;															// カメラの Far クリップ面の距離を取得する

extern	VECTOR		GetCameraPosition(					void ) ;															// カメラの位置を取得する
extern	VECTOR		GetCameraTarget(					void ) ;															// カメラの注視点を取得する
extern	VECTOR		GetCameraUpVector(					void ) ;															// カメラの視線に垂直な上方向のベクトルを取得する
extern	float		GetCameraAngleHRotate(				void ) ;															// カメラの水平方向の向きを取得する
extern	float		GetCameraAngleVRotate(				void ) ;															// カメラの垂直方向の向きを取得する
extern	float		GetCameraAngleTRotate(				void ) ;															// カメラの向きの捻り角度を取得する

extern	MATRIX		GetCameraViewMatrix(				void ) ;															// ビュー行列を取得する
extern	MATRIX		GetCameraBillboardMatrix(			void ) ;															// ビルボード行列を取得する
extern	float		GetCameraFov(						void ) ;															// カメラの視野角を取得する
extern	float		GetCameraSize(						void ) ;															// カメラの視野サイズを取得する
extern	MATRIX		GetCameraProjectionMatrix(			void ) ;															// 射影行列を取得する
extern	float		GetCameraDotAspect(					void ) ;															// カメラのドットアスペクト比を得る
extern	MATRIX		GetCameraViewportMatrix(			void ) ;															// ビューポート行列を取得する
extern	MATRIX		GetCameraAPIViewportMatrix(			void ) ;															// Direct3Dで自動適用されるビューポート行列を取得する

// ライト関係関数
extern	int			SetUseLighting(				int Flag ) ;																// ライティングを使用するかどうかを設定する
extern	int			SetMaterialUseVertDifColor( int UseFlag ) ;																// ３Ｄ描画のライティング計算で頂点カラーのディフューズカラーを使用するかどうかを設定する
extern	int			SetMaterialUseVertSpcColor( int UseFlag ) ;																// ３Ｄ描画のライティング計算で頂点カラーのスペキュラカラーを使用するかどうかを設定する
extern	int			SetMaterialParam(			MATERIALPARAM Material ) ;													// ３Ｄ描画のライティング計算で使用するマテリアルパラメータを設定する
extern	int			SetUseSpecular(				int UseFlag ) ;																// ３Ｄ描画にスペキュラを使用するかどうかを設定する
extern	int			SetGlobalAmbientLight(		COLOR_F Color ) ;															// グローバルアンビエントライトカラーを設定する

extern	int			ChangeLightTypeDir(			VECTOR Direction ) ;														// デフォルトライトのタイプをディレクショナルライトにする
extern	int			ChangeLightTypeSpot(		VECTOR Position, VECTOR Direction, float OutAngle, float InAngle, float Range, float Atten0, float Atten1, float Atten2 ) ;	// デフォルトライトのタイプをスポットライトにする
extern	int			ChangeLightTypePoint(		VECTOR Position, float Range, float Atten0, float Atten1, float Atten2 ) ;	// デフォルトライトのタイプをポイントライトにする
extern	int			GetLightType(				void ) ;																	// デフォルトライトのタイプを取得する( 戻り値は DX_LIGHTTYPE_DIRECTIONAL 等 )
extern	int			SetLightEnable(				int EnableFlag ) ;															// デフォルトライトを使用するかどうかを設定する
extern	int			GetLightEnable(				void ) ;																	// デフォルトライトを使用するかどうかを取得する( 戻り値　TRUE:有効  FALSE:無効 )
extern	int			SetLightDifColor(			COLOR_F Color ) ;															// デフォルトライトのディフューズカラーを設定する
extern	COLOR_F		GetLightDifColor(			void ) ;																	// デフォルトライトのディフューズカラーを取得する
extern	int			SetLightSpcColor(			COLOR_F Color ) ;															// デフォルトライトのスペキュラカラーを設定する
extern	COLOR_F		GetLightSpcColor(			void ) ;																	// デフォルトライトのスペキュラカラーを取得する
extern	int			SetLightAmbColor(			COLOR_F Color ) ;															// デフォルトライトのアンビエントカラーを設定する
extern	COLOR_F		GetLightAmbColor(			void ) ;																	// デフォルトライトのアンビエントカラーを取得する
extern	int			SetLightDirection(			VECTOR Direction ) ;														// デフォルトライトの方向を設定する
extern	VECTOR		GetLightDirection(			void ) ;																	// デフォルトライトの方向を取得する
extern	int			SetLightPosition(			VECTOR Position ) ;															// デフォルトライトの位置を設定する
extern	VECTOR		GetLightPosition(			void ) ;																	// デフォルトライトの位置を取得する
extern	int			SetLightRangeAtten(			float Range, float Atten0, float Atten1, float Atten2 ) ;					// デフォルトライトの距離減衰パラメータを設定する( 有効距離、距離減衰係数０、１、２ )
extern	int			GetLightRangeAtten(			float *Range, float *Atten0, float *Atten1, float *Atten2 )	;				// デフォルトライトの距離減衰パラメータを取得する( 有効距離、距離減衰係数０、１、２ )
extern	int			SetLightAngle(				float OutAngle, float InAngle ) ;											// デフォルトライトのスポットライトのパラメータを設定する( 外部コーン角度、内部コーン角度 )
extern	int			GetLightAngle(				float *OutAngle, float *InAngle ) ;											// デフォルトライトのスポットライトのパラメータを取得する( 外部コーン角度、内部コーン角度 )

extern	int			CreateDirLightHandle(       VECTOR Direction ) ;														// ディレクショナルライトハンドルを作成する
extern	int			CreateSpotLightHandle(      VECTOR Position, VECTOR Direction, float OutAngle, float InAngle, float Range, float Atten0, float Atten1, float Atten2 ) ;	// スポットライトハンドルを作成する
extern	int			CreatePointLightHandle(     VECTOR Position, float Range, float Atten0, float Atten1, float Atten2 ) ;	// ポイントライトハンドルを作成する
extern	int			DeleteLightHandle(          int LHandle ) ;																// ライトハンドルを削除する
extern	int			DeleteLightHandleAll(       void ) ;																	// ライトハンドルを全て削除する
extern	int			SetLightTypeHandle(         int LHandle, int LightType ) ;												// ライトハンドルのライトのタイプを変更する( DX_LIGHTTYPE_DIRECTIONAL 等 )
extern	int			SetLightEnableHandle(       int LHandle, int EnableFlag ) ;												// ライトハンドルのライト効果の有効、無効を設定する( TRUE:有効  FALSE:無効 )
extern	int			SetLightDifColorHandle(     int LHandle, COLOR_F Color ) ;												// ライトハンドルのライトのディフューズカラーを設定する
extern	int			SetLightSpcColorHandle(     int LHandle, COLOR_F Color ) ;												// ライトハンドルのライトのスペキュラカラーを設定する
extern	int			SetLightAmbColorHandle(     int LHandle, COLOR_F Color ) ;												// ライトハンドルのライトのアンビエントカラーを設定する
extern	int			SetLightDirectionHandle(    int LHandle, VECTOR Direction ) ;											// ライトハンドルのライトの方向を設定する
extern	int			SetLightPositionHandle(     int LHandle, VECTOR Position ) ;											// ライトハンドルのライトの位置を設定する
extern	int			SetLightRangeAttenHandle(   int LHandle, float Range, float Atten0, float Atten1, float Atten2 ) ;		// ライトハンドルのライトの距離減衰パラメータを設定する( 有効距離、距離減衰係数０、１、２ )
extern	int			SetLightAngleHandle(        int LHandle, float OutAngle, float InAngle ) ;								// ライトハンドルのライトのスポットライトのパラメータを設定する( 外部コーン角度、内部コーン角度 )
extern	int			GetLightTypeHandle(         int LHandle ) ;																// ライトハンドルのライトのタイプを取得する( 戻り値は DX_LIGHTTYPE_DIRECTIONAL 等 )
extern	int			GetLightEnableHandle(       int LHandle ) ;																// ライトハンドルのライト効果の有効、無効を取得する( TRUE:有効  FALSE:無効 )
extern	COLOR_F		GetLightDifColorHandle(     int LHandle ) ;																// ライトハンドルのライトのディフューズカラーを取得する
extern	COLOR_F		GetLightSpcColorHandle(     int LHandle ) ;																// ライトハンドルのライトのスペキュラカラーを取得する
extern	COLOR_F		GetLightAmbColorHandle(     int LHandle ) ;																// ライトハンドルのライトのアンビエントカラーを取得する
extern	VECTOR		GetLightDirectionHandle(    int LHandle ) ;																// ライトハンドルのライトの方向を取得する
extern	VECTOR		GetLightPositionHandle(     int LHandle ) ;																// ライトハンドルのライトの位置を取得する
extern	int			GetLightRangeAttenHandle(   int LHandle, float *Range, float *Atten0, float *Atten1, float *Atten2 ) ;	// ライトハンドルのライトの距離減衰パラメータを取得する( 有効距離、距離減衰係数０、１、２ )
extern	int			GetLightAngleHandle(        int LHandle, float *OutAngle, float *InAngle ) ;							// ライトハンドルのライトのスポットライトのパラメータを取得する( 外部コーン角度、内部コーン角度 )

extern	int			GetEnableLightHandleNum(	void ) ;																	// 有効になっているライトハンドルの数を取得する
extern	int			GetEnableLightHandle(		int Index ) ;																// 有効になっているライトハンドルを取得する

// 色情報取得用関数
extern	int			GetTexFormatIndex(			IMAGEFORMATDESC *Format ) ;																									// テクスチャフォーマットのインデックスを得る
extern	int			ColorKaiseki(				void *PixelData, COLORDATA* ColorData ) ;																					// 色ビット情報解析
#ifdef __WINDOWS__
extern	int			CreatePixelFormat(			D_DDPIXELFORMAT *PixelFormatBuf, int ColorBitDepth, DWORD RedMask, DWORD GreenMask, DWORD BlueMask, DWORD AlphaMask ) ;		// DDPIXELFORMATデータを作成する
#endif // __WINDOWS__








// DxMask.cpp 関数プロトタイプ宣言

#ifndef DX_NON_MASK

// マスク関係 
extern	int			CreateMaskScreen(				void ) ;																						// マスクスクリーンを作成する
extern	int			DeleteMaskScreen(				void ) ;																						// マスクスクリーンを削除する
extern	int			DrawMaskToDirectData(			int x, int y, int Width, int Height, void *MaskData , int TransMode ) ;							// マスクスクリーンにメモリ上のビットマップデータを転送する( MaskData は 1byte で 1dot 表す１ラインあたり Width byte のデータ配列の先頭アドレス )
extern	int			DrawFillMaskToDirectData(		int x1, int y1, int x2, int y2,  int Width, int Height, void *MaskData ) ;						// マスクスクリーンにメモリ上のビットマップデータで指定矩形内を塗りつぶすように転送する

extern	int			SetUseMaskScreenFlag(			int ValidFlag ) ;																				// マスクスクリーンを使用するかどうかを設定する( ValidFlag:使用するかどうか( TRUE:使用する  FALSE:使用しない( デフォルト ) )
extern	int			GetUseMaskScreenFlag(			void ) ;																						// マスクスクリーンを使用するかどうかを取得する
extern	int			FillMaskScreen(					int Flag ) ;																					// マスクスクリーンを指定の色で塗りつぶす

extern	int			InitMask(						void ) ;																						// マスクハンドルをすべて削除する
extern	int			MakeMask(						int Width, int Height ) ;																		// マスクハンドルを作成する
extern	int			GetMaskSize(					int *WidthBuf, int *HeightBuf, int MaskHandle ) ;												// マスクハンドルが持つマスクイメージのサイズを取得する
extern	int			SetDataToMask(					int Width, int Height, void *MaskData, int MaskHandle ) ;										// マスクハンドルにビットマップイメージを転送する
extern	int			DeleteMask(						int MaskHandle ) ;																				// マスクハンドルを削除する
extern	int			BmpBltToMask(					HBITMAP Bmp, int BmpPointX, int BmpPointY, int MaskHandle ) ;									// マスクハンドルにＢＭＰデータを転送する
extern	int			LoadMask(						const TCHAR *FileName ) ;																		// 画像ファイルを読み込みマスクハンドルを作成する
extern	int			LoadDivMask(					const TCHAR *FileName, int AllNum, int XNum, int YNum, int XSize, int YSize, int *HandleBuf ) ;	// 画像ファイルを分割読み込みしてマスクハンドルを作成する
extern	int			DrawMask(						int x, int y, int MaskHandle, int TransMode ) ;													// マスクスクリーンにマスクハンドルの持つマスクイメージを書き込む
#ifndef DX_NON_FONT
extern	int			DrawFormatStringMask(			int x, int y, int Flag,                 const TCHAR *FormatString, ... ) ;						// 書式指定ありの文字列をマスクスクリーンに描画する
extern	int			DrawFormatStringMaskToHandle(	int x, int y, int Flag, int FontHandle, const TCHAR *FormatString, ... ) ;						// 書式指定ありの文字列をマスクスクリーンに描画する( フォントハンドル指定版 )( SetFontCacheToTextureFlag( FALSE ) ; にして作成したフォントハンドルのみ使用可能 )
extern	int			DrawStringMask(					int x, int y, int Flag,                 const TCHAR *String ) ;									// 文字列をマスクスクリーンに描画する
extern	int			DrawStringMaskToHandle(			int x, int y, int Flag, int FontHandle, const TCHAR *String ) ;									// 文字列をマスクスクリーンに描画する( フォントハンドル指定版 )( SetFontCacheToTextureFlag( FALSE ) ; にして作成したフォントハンドルのみ使用可能 )
#endif // DX_NON_FONT
extern	int			DrawFillMask(					int x1, int y1, int x2, int y2, int MaskHandle ) ;												// マスクハンドルが持つマスクイメージをマスクスクリーンいっぱいに描画する( タイル状に並べる )
extern	int			SetMaskReverseEffectFlag(		int ReverseFlag ) ;																				// マスクイメージ内の数値に対する効果を逆転させる( 旧バージョンとの互換性の為の機能 )

extern 	int			GetMaskScreenData(				int x1, int y1, int x2, int y2, int MaskHandle ) ;												// マスクスクリーンの指定矩形部分をマスクハンドルに転送する
extern	int			GetMaskUseFlag(					void ) ;																						// マスクスクリーンを使用する設定になっているかどうかを取得する

#endif // DX_NON_MASK
















// DxFont.cpp 関数プロトタイプ宣言

#ifndef DX_NON_FONT

// フォント、文字列描画関係関数
extern	int			EnumFontName(                           TCHAR *NameBuffer, int NameBufferNum, int JapanOnlyFlag = TRUE ) ;								// 使用可能なフォントの名前を列挙する( NameBuffer に 64バイト区切りで名前が格納されます )
extern	int			EnumFontNameEx(                         TCHAR *NameBuffer, int NameBufferNum, int CharSet = -1 /* DX_CHARSET_DEFAULT 等 */ ) ;			// 使用可能なフォントの名前を列挙する( NameBuffer に 64バイト区切りで名前が格納されます )( 文字セット指定版 )
extern	int			EnumFontNameEx2(						TCHAR *NameBuffer, int NameBufferNum, TCHAR *EnumFontName, int CharSet = -1 /* DX_CHARSET_DEFAULT 等 */ ) ;	// 指定のフォント名のフォントを列挙する
extern	int			InitFontToHandle(                       void ) ;																						// 全てのフォントハンドルを削除する

extern	int			CreateFontToHandle(                     const TCHAR *FontName, int Size, int Thick, int FontType = -1 , int CharSet = -1 , int EdgeSize = -1 , int Italic = FALSE , int Handle = -1 ) ;		// フォントハンドルを作成する
extern	int			SetFontSpaceToHandle(                   int Point, int FontHandle ) ;																	// フォントハンドルの字間を変更する
extern	int			DeleteFontToHandle(                     int FontHandle ) ;																				// フォントハンドルを削除する
extern	int			SetFontLostFlag(                        int FontHandle, int *LostFlag ) ;																// フォントハンドルを削除した際に TRUE を代入する変数のアドレスを設定する

extern	int			ChangeFont(                             const TCHAR *FontName, int CharSet = -1 /* DX_CHARSET_SHFTJIS 等 */ ) ;							// デフォルトフォントハンドルで使用するフォントを変更
extern	int			ChangeFontType(                         int FontType ) ;																				// デフォルトフォントハンドルのフォントタイプの変更
extern	int			SetFontSize(                            int FontSize ) ;																				// デフォルトフォントハンドルのサイズを設定する
extern	int			GetFontSize(                            void ) ;																						// デフォルトフォントハンドルのサイズを取得する
extern	int			SetFontThickness(                       int ThickPal ) ;																				// デフォルトフォントハンドルの太さを設定する
extern	int			SetFontSpace(                           int Point ) ;																					// デフォルトフォントハンドルの字間を変更する
extern	int			SetDefaultFontState(                    const TCHAR *FontName, int Size, int Thick ) ;													// デフォルトフォントハンドルの設定を変更する
extern	int			GetDefaultFontHandle(                   void ) ;																						// デフォルトフォントハンドルを取得する
extern	int			GetFontMaxWidth(                        void ) ;																						// デフォルトフォントハンドルの文字の最大幅を取得する
extern	int			GetDrawStringWidth(                     const TCHAR *String, int StrLen, int VerticalFlag = FALSE ) ;									// デフォルトフォントハンドルを使用した文字列の描画幅を取得する
extern	int			GetDrawFormatStringWidth(               const TCHAR *FormatString, ... ) ;																// デフォルトフォントハンドルを使用した書式付き文字列の描画幅を取得する
extern	int			GetDrawExtendStringWidth(               double ExRateX, const TCHAR *String, int StrLen, int VerticalFlag = FALSE ) ;					// デフォルトフォントハンドルを使用した文字列の描画幅を取得する( 拡大率付き )
extern	int			GetDrawExtendFormatStringWidth(         double ExRateX, const TCHAR *FormatString, ... ) ;												// デフォルトフォントハンドルを使用した書式付き文字列の描画幅を取得する( 拡大率付き )

extern	int			GetFontMaxWidthToHandle(                int FontHandle ) ;																				// フォントハンドルの文字の最大幅を取得する
extern	int			GetFontSizeToHandle(                    int FontHandle ) ;																				// フォントハンドルのサイズを取得する
extern	int			GetFontCharInfo(                        int FontHandle, const TCHAR *Char, int *DrawX, int *DrawY, int *NextCharX, int *SizeX, int *SizeY ) ;	// フォントハンドルの指定の文字の描画情報を取得する
extern	int			GetDrawStringWidthToHandle(             const TCHAR *String, int StrLen, int FontHandle, int VerticalFlag = FALSE ) ;					// フォントハンドルを使用した文字列の描画幅を取得する
extern	int			GetDrawFormatStringWidthToHandle(       int FontHandle, const TCHAR *FormatString, ... ) ;												// フォントハンドルを使用した書式付き文字列の描画幅を取得する
extern	int			GetDrawExtendStringWidthToHandle(       double ExRateX, const TCHAR *String, int StrLen, int FontHandle, int VerticalFlag = FALSE ) ;	// フォントハンドルを使用した文字列の描画幅を取得する
extern	int			GetDrawExtendFormatStringWidthToHandle( double ExRateX, int FontHandle, const TCHAR *FormatString, ... ) ;								// フォントハンドルを使用した書式付き文字列の描画幅を取得する
extern	int			GetFontStateToHandle(                   TCHAR *FontName, int *Size, int *Thick, int FontHandle) ;										// フォントハンドルの情報を取得する
extern	int			CheckFontCacheToTextureFlag(            int FontHandle ) ;																				// フォントハンドルがテクスチャキャッシュを使用しているかどうかを取得する
extern	int			CheckFontChacheToTextureFlag(           int FontHandle ) ;																				// CheckFontCacheToTextureFlag の誤字版
extern	int			CheckFontHandleValid(                   int FontHandle ) ;																				// フォントハンドルが有効かどうかを取得する

extern	int			SetFontCacheToTextureFlag(              int Flag ) ;																					// フォントのキャッシュにテクスチャを使用するかどうかを設定する( TRUE:テクスチャを使用する( デフォルト )  FALSE:テクスチャは使用しない )
extern	int			GetFontCacheToTextureFlag(              void ) ;																						// フォントのキャッシュにテクスチャを使用するかどうかを設定する
extern	int			SetFontChacheToTextureFlag(             int Flag ) ;																					// SetFontCacheToTextureFlag の誤字版
extern	int			GetFontChacheToTextureFlag(             void ) ;																						// GetFontCacheToTextureFlag の誤字版
extern	int			SetFontCacheTextureColorBitDepth(		int ColorBitDepth ) ;																			// フォントのキャッシュとして使用するテクスチャのカラービット深度を設定する( 16 又は 32 のみ指定可能  デフォルトは 32 )
extern	int			GetFontCacheTextureColorBitDepth(		void ) ;																						// フォントのキャッシュとして使用するテクスチャのカラービット深度を取得する
extern	int			SetFontCacheCharNum(                    int CharNum ) ;																					// フォントキャッシュでキャッシュできる文字数を設定する
extern	int			GetFontCacheCharNum(                    void ) ;																						// フォントキャッシュでキャッシュできる文字数を取得する( 戻り値  0:デフォルト  1以上:指定文字数 )

// FontCacheStringDraw の代わりに DrawString を使ってください
extern	int			FontCacheStringDrawToHandle(            int x, int y, const TCHAR *StrData, int Color, int EdgeColor, BASEIMAGE *DestImage, RECT *ClipRect /* NULL 可 */ , int FontHandle, int VerticalFlag = FALSE , SIZE *DrawSizeP = NULL ) ;
extern	int			FontBaseImageBlt(                       int x, int y, const TCHAR *StrData, BASEIMAGE *DestImage, BASEIMAGE *DestEdgeImage,                 int VerticalFlag = FALSE ) ;	// 基本イメージに文字列を描画する( デフォルトフォントハンドルを使用する )
extern	int			FontBaseImageBltToHandle(               int x, int y, const TCHAR *StrData, BASEIMAGE *DestImage, BASEIMAGE *DestEdgeImage, int FontHandle, int VerticalFlag = FALSE ) ;	// 基本イメージに文字列を描画する

extern	int			MultiByteCharCheck(                     const char *Buf, int CharSet /* DX_CHARSET_SHFTJIS */ ) ;										// ２バイト文字か調べる( TRUE:２バイト文字  FALSE:１バイト文字 )

// 文字列描画関数
extern	int			DrawString(                             int x, int y, const TCHAR *String, int Color,                 int EdgeColor = 0 ) ;																				// デフォルトフォントハンドルを使用して文字列を描画する
extern	int			DrawVString(                            int x, int y, const TCHAR *String, int Color,                 int EdgeColor = 0 ) ;																				// デフォルトフォントハンドルを使用して文字列を描画する( 縦書き )
extern	int			DrawFormatString(                       int x, int y, int Color,                 const TCHAR *FormatString, ... ) ;																						// デフォルトフォントハンドルを使用して書式指定文字列を描画する
extern	int			DrawFormatVString(                      int x, int y, int Color,                 const TCHAR *FormatString, ... ) ;																						// デフォルトフォントハンドルを使用して書式指定文字列を描画する( 縦書き )
extern	int			DrawExtendString(                       int x, int y, double ExRateX, double ExRateY, const TCHAR *String, int Color,                 int EdgeColor = 0 ) ;												// デフォルトフォントハンドルを使用して文字列の拡大描画
extern	int			DrawExtendVString(                      int x, int y, double ExRateX, double ExRateY, const TCHAR *String, int Color,                 int EdgeColor = 0 ) ;												// デフォルトフォントハンドルを使用して文字列の拡大描画( 縦書き )
extern	int			DrawExtendFormatString(                 int x, int y, double ExRateX, double ExRateY, int Color,                 const TCHAR *FormatString, ... ) ;														// デフォルトフォントハンドルを使用して書式指定文字列を拡大描画する
extern	int			DrawExtendFormatVString(                int x, int y, double ExRateX, double ExRateY, int Color,                 const TCHAR *FormatString, ... ) ;														// デフォルトフォントハンドルを使用して書式指定文字列を拡大描画する( 縦書き )

extern	int			DrawNumberToI(                          int x, int y,                          int    Num, int RisesNum, int Color, int EdgeColor = 0 ) ;																// デフォルトフォントハンドルを使用して整数型の数値を描画する
extern	int			DrawNumberToF(                          int x, int y,                          double Num, int Length,   int Color, int EdgeColor = 0 ) ;																// デフォルトフォントハンドルを使用して浮動小数点型の数値を描画する
extern	int			DrawNumberPlusToI(                      int x, int y, const TCHAR *NoteString, int    Num, int RisesNum, int Color, int EdgeColor = 0 ) ;																// デフォルトフォントハンドルを使用して整数型の数値とその説明の文字列を一度に描画する
extern 	int			DrawNumberPlusToF(                      int x, int y, const TCHAR *NoteString, double Num, int Length,   int Color, int EdgeColor = 0 ) ;																// デフォルトフォントハンドルを使用して浮動小数点型の数値とその説明の文字列を一度に描画する

extern	int			DrawStringToZBuffer(                    int x, int y, const TCHAR *String,                                                 int WriteZMode /* DX_ZWRITE_MASK 等 */ ) ;									// デフォルトフォントハンドルを使用してＺバッファに対して文字列を描画する
extern	int			DrawVStringToZBuffer(                   int x, int y, const TCHAR *String,                                                 int WriteZMode /* DX_ZWRITE_MASK 等 */ ) ;									// デフォルトフォントハンドルを使用してＺバッファに対して文字列を描画する( 縦書き )
extern	int			DrawFormatStringToZBuffer(              int x, int y,                                                                      int WriteZMode /* DX_ZWRITE_MASK 等 */, const TCHAR *FormatString, ... ) ;	// デフォルトフォントハンドルを使用してＺバッファに対して書式指定文字列を描画する
extern	int			DrawFormatVStringToZBuffer(             int x, int y,                                                                      int WriteZMode /* DX_ZWRITE_MASK 等 */, const TCHAR *FormatString, ... ) ;	// デフォルトフォントハンドルを使用してＺバッファに対して書式指定文字列を描画する( 縦書き )
extern	int			DrawExtendStringToZBuffer(              int x, int y, double ExRateX, double ExRateY, const TCHAR *String,                 int WriteZMode /* DX_ZWRITE_MASK 等 */ ) ;									// デフォルトフォントハンドルを使用してＺバッファに対して文字列を拡大描画する
extern	int			DrawExtendVStringToZBuffer(             int x, int y, double ExRateX, double ExRateY, const TCHAR *String,                 int WriteZMode /* DX_ZWRITE_MASK 等 */ ) ;									// デフォルトフォントハンドルを使用してＺバッファに対して文字列を拡大描画する( 縦書き )
extern	int			DrawExtendFormatStringToZBuffer(        int x, int y, double ExRateX, double ExRateY,                                      int WriteZMode /* DX_ZWRITE_MASK 等 */, const TCHAR *FormatString, ... ) ;	// デフォルトフォントハンドルを使用してＺバッファに対して書式指定文字列を拡大描画する
extern	int			DrawExtendFormatVStringToZBuffer(       int x, int y, double ExRateX, double ExRateY,                                      int WriteZMode /* DX_ZWRITE_MASK 等 */, const TCHAR *FormatString, ... ) ;	// デフォルトフォントハンドルを使用してＺバッファに対して書式指定文字列を拡大描画する( 縦書き )


extern	int			DrawStringToHandle(                     int x, int y, const TCHAR *String, int Color, int FontHandle, int EdgeColor = 0 , int VerticalFlag = FALSE ) ;													// フォントハンドルを使用して文字列を描画する
extern	int			DrawVStringToHandle(                    int x, int y, const TCHAR *String, int Color, int FontHandle, int EdgeColor = 0 ) ;																				// フォントハンドルを使用して文字列を描画する( 縦書き )
extern	int			DrawFormatStringToHandle(               int x, int y, int Color, int FontHandle, const TCHAR *FormatString, ... ) ;																						// フォントハンドルを使用して書式指定文字列を描画する
extern	int			DrawFormatVStringToHandle(              int x, int y, int Color, int FontHandle, const TCHAR *FormatString, ... ) ;																						// フォントハンドルを使用して書式指定文字列を描画する( 縦書き )
extern	int			DrawExtendStringToHandle(               int x, int y, double ExRateX, double ExRateY, const TCHAR *String, int Color, int FontHandle, int EdgeColor = 0 , int VerticalFlag = FALSE ) ;					// フォントハンドルを使用して文字列を拡大描画する
extern	int			DrawExtendVStringToHandle(              int x, int y, double ExRateX, double ExRateY, const TCHAR *String, int Color, int FontHandle, int EdgeColor = 0 ) ;												// フォントハンドルを使用して文字列を拡大描画する( 縦書き )
extern	int			DrawExtendFormatStringToHandle(         int x, int y, double ExRateX, double ExRateY, int Color, int FontHandle, const TCHAR *FormatString, ... ) ;														// フォントハンドルを使用して書式指定文字列を拡大描画する
extern	int			DrawExtendFormatVStringToHandle(        int x, int y, double ExRateX, double ExRateY, int Color, int FontHandle, const TCHAR *FormatString, ... ) ;														// フォントハンドルを使用して書式指定文字列を拡大描画する( 縦書き )

extern	int			DrawNumberToIToHandle(                  int x, int y,                          int    Num, int RisesNum, int Color, int FontHandle, int EdgeColor = 0 ) ;												// フォントハンドルを使用して整数型の数値を描画する
extern	int			DrawNumberToFToHandle(                  int x, int y,                          double Num, int Length,   int Color, int FontHandle, int EdgeColor = 0 ) ;												// フォントハンドルを使用して浮動小数点型の数値を描画する
extern	int			DrawNumberPlusToIToHandle(              int x, int y, const TCHAR *NoteString, int    Num, int RisesNum, int Color, int FontHandle, int EdgeColor = 0 ) ;												// フォントハンドルを使用して整数型の数値とその説明の文字列を一度に描画する
extern	int			DrawNumberPlusToFToHandle(              int x, int y, const TCHAR *NoteString, double Num, int Length,   int Color, int FontHandle, int EdgeColor = 0 ) ;												// フォントハンドルを使用して浮動小数点型の数値とその説明の文字列を一度に描画する

extern	int			DrawStringToHandleToZBuffer(            int x, int y, const TCHAR *String, int FontHandle,                                 int WriteZMode /* DX_ZWRITE_MASK 等 */ , int VerticalFlag = FALSE ) ;		// フォントハンドルを使用してＺバッファに対して文字列を描画する
extern	int			DrawVStringToHandleToZBuffer(           int x, int y, const TCHAR *String, int FontHandle,                                 int WriteZMode /* DX_ZWRITE_MASK 等 */ ) ;									// フォントハンドルを使用してＺバッファに対して文字列を描画する( 縦書き )
extern	int			DrawFormatStringToHandleToZBuffer(      int x, int y, int FontHandle,                                                      int WriteZMode /* DX_ZWRITE_MASK 等 */, const TCHAR *FormatString, ... ) ;	// フォントハンドルを使用してＺバッファに対して書式指定文字列を描画する
extern	int			DrawFormatVStringToHandleToZBuffer(     int x, int y, int FontHandle,                                                      int WriteZMode /* DX_ZWRITE_MASK 等 */, const TCHAR *FormatString, ... ) ;	// フォントハンドルを使用してＺバッファに対して書式指定文字列を描画する( 縦書き )
extern	int			DrawExtendStringToHandleToZBuffer(      int x, int y, double ExRateX, double ExRateY, const TCHAR *String, int FontHandle, int WriteZMode /* DX_ZWRITE_MASK 等 */ , int VerticalFlag = FALSE ) ;		// フォントハンドルを使用してＺバッファに対して文字列を拡大描画する
extern	int			DrawExtendVStringToHandleToZBuffer(     int x, int y, double ExRateX, double ExRateY, const TCHAR *String, int FontHandle, int WriteZMode /* DX_ZWRITE_MASK 等 */ ) ;									// フォントハンドルを使用してＺバッファに対して文字列を拡大描画する( 縦書き )
extern	int			DrawExtendFormatStringToHandleToZBuffer(  int x, int y, double ExRateX, double ExRateY, int FontHandle,                    int WriteZMode /* DX_ZWRITE_MASK 等 */, const TCHAR *FormatString, ... ) ;	// フォントハンドルを使用してＺバッファに対して書式指定文字列を拡大描画する
extern	int			DrawExtendFormatVStringToHandleToZBuffer( int x, int y, double ExRateX, double ExRateY, int FontHandle,                    int WriteZMode /* DX_ZWRITE_MASK 等 */, const TCHAR *FormatString, ... ) ;	// フォントハンドルを使用してＺバッファに対して書式指定文字列を拡大描画する( 縦書き )

#endif // DX_NON_FONT








// DxMath.cpp 関数プロトタイプ宣言

// 演算ライブラリ
extern	int			CreateIdentityMatrix(         MATRIX *Out ) ;															// 単位行列を作成する
extern	int			CreateLookAtMatrix(           MATRIX *Out, VECTOR *Eye, VECTOR *At, VECTOR *Up ) ;						// ビュー行列を作成する
extern	int			CreateLookAtMatrix2(          MATRIX *Out, VECTOR *Eye, double XZAngle, double Oira ) ;					// ビュー行列を作成する(方向を回転値で指定)
extern	int			CreateLookAtMatrixRH(         MATRIX *Out, VECTOR *Eye, VECTOR *At, VECTOR *Up ) ;						// ビュー行列を作成する(右手座標系用)
extern	int			CreateMultiplyMatrix(         MATRIX *Out, MATRIX *In1, MATRIX *In2 ) ;									// 行列の積を求める
extern	int			CreatePerspectiveFovMatrix(   MATRIX *Out, float fov, float zn, float zf, float aspect = -1.0f ) ;		// 射影行列を作成する
extern	int			CreatePerspectiveFovMatrixRH( MATRIX *Out, float fov, float zn, float zf, float aspect = -1.0f ) ;		// 射影行列を作成する(右手座標系用)
extern	int			CreateOrthoMatrix(            MATRIX *Out, float size, float zn, float zf, float aspect = -1.0f ) ;		// 正射影行列を作成する
extern	int			CreateOrthoMatrixRH(          MATRIX *Out, float size, float zn, float zf, float aspect = -1.0f ) ;		// 正射影行列を作成する(右手座標系用)
extern	int			CreateScalingMatrix(          MATRIX *Out, float sx, float sy, float sz ) ;								// スケーリング行列を作成する
extern	int			CreateRotationXMatrix(        MATRIX *Out, float Angle ) ;												// Ｘ軸を中心とした回転行列を作成する
extern	int			CreateRotationYMatrix(        MATRIX *Out, float Angle ) ;												// Ｙ軸を中心とした回転行列を作成する
extern	int			CreateRotationZMatrix(        MATRIX *Out, float Angle ) ;												// Ｚ軸を中心とした回転行列を作成する
extern	int			CreateTranslationMatrix(      MATRIX *Out, float x, float y, float z ) ;								// 平行移動行列を作成する
extern	int			CreateTransposeMatrix(        MATRIX *Out, MATRIX *In ) ;												// 転置行列を作成する
extern	int			CreateInverseMatrix(          MATRIX *Out, MATRIX *In ) ;												// 逆行列を作成する
extern	int			CreateViewportMatrix(         MATRIX *Out, float CenterX, float CenterY, float Width, float Height ) ;	// ビューポート行列を作成する
extern	int			CreateRotationXYZMatrix(      MATRIX *Out, float XRot, float YRot, float ZRot ) ;						// Ｘ軸回転→Ｙ軸回転→Ｚ軸回転を合成した行列を作成する
extern	int			CreateRotationXZYMatrix(      MATRIX *Out, float XRot, float YRot, float ZRot ) ;						// Ｘ軸回転→Ｚ軸回転→Ｙ軸回転を合成した行列を作成する
extern	int			CreateRotationYXZMatrix(      MATRIX *Out, float XRot, float YRot, float ZRot ) ;						// Ｙ軸回転→Ｘ軸回転→Ｚ軸回転を合成した行列を作成する
extern	int			CreateRotationYZXMatrix(      MATRIX *Out, float XRot, float YRot, float ZRot ) ;						// Ｙ軸回転→Ｚ軸回転→Ｘ軸回転を合成した行列を作成する
extern	int			CreateRotationZXYMatrix(      MATRIX *Out, float XRot, float YRot, float ZRot ) ;						// Ｚ軸回転→Ｘ軸回転→Ｙ軸回転を合成した行列を作成する
extern	int			CreateRotationZYXMatrix(      MATRIX *Out, float XRot, float YRot, float ZRot ) ;						// Ｚ軸回転→Ｙ軸回転→Ｘ軸回転を合成した行列を作成する
extern	int			GetMatrixXYZRotation(         MATRIX *In, float *OutXRot, float *OutYRot, float *OutZRot ) ;			// 行列からＸＹＺ軸回転の値を取得する( 戻り値　-1:ジンバルロック発生  0:成功 )
extern	int			GetMatrixXZYRotation(         MATRIX *In, float *OutXRot, float *OutYRot, float *OutZRot ) ;			// 行列からＸＺＹ軸回転の値を取得する( 戻り値　-1:ジンバルロック発生  0:成功 )
extern	int			GetMatrixYXZRotation(         MATRIX *In, float *OutXRot, float *OutYRot, float *OutZRot ) ;			// 行列からＹＸＺ軸回転の値を取得する( 戻り値　-1:ジンバルロック発生  0:成功 )
extern	int			GetMatrixYZXRotation(         MATRIX *In, float *OutXRot, float *OutYRot, float *OutZRot ) ;			// 行列からＹＺＸ軸回転の値を取得する( 戻り値　-1:ジンバルロック発生  0:成功 )
extern	int			GetMatrixZXYRotation(         MATRIX *In, float *OutXRot, float *OutYRot, float *OutZRot ) ;			// 行列からＺＸＹ軸回転の値を取得する( 戻り値　-1:ジンバルロック発生  0:成功 )
extern	int			GetMatrixZYXRotation(         MATRIX *In, float *OutXRot, float *OutYRot, float *OutZRot ) ;			// 行列からＺＹＸ軸回転の値を取得する( 戻り値　-1:ジンバルロック発生  0:成功 )
extern	int			VectorNormalize(              VECTOR *Out, VECTOR *In ) ;												// ベクトルを正規化する
extern	int			VectorScale(                  VECTOR *Out, VECTOR *In, float Scale ) ;									// ベクトルをスカラー倍する
extern	int			VectorMultiply(               VECTOR *Out, VECTOR *In1, VECTOR *In2 ) ;									// ベクトルの掛け算をする
extern	int			VectorSub(                    VECTOR *Out, VECTOR *In1, VECTOR *In2 ) ;									// Out = In1 - In2 のベクトル計算をする 
extern	int			VectorAdd(                    VECTOR *Out, VECTOR *In1, VECTOR *In2 ) ;									// Out = In1 + In2 のベクトル計算をする 
extern	int			VectorOuterProduct(           VECTOR *Out, VECTOR *In1, VECTOR *In2 ) ;									// In1とIn2の外積を計算する
extern	float		VectorInnerProduct(           VECTOR *In1, VECTOR *In2 ) ;												// In1とIn2の内積を計算する
extern	int			VectorRotationX(              VECTOR *Out, VECTOR *In, double Angle ) ;									// ベクトルのＸ軸を軸にした回転を行う
extern	int			VectorRotationY(              VECTOR *Out, VECTOR *In, double Angle ) ;									// ベクトルのＹ軸を軸にした回転を行う
extern	int			VectorRotationZ(              VECTOR *Out, VECTOR *In, double Angle ) ;									// ベクトルのＺ軸を軸にした回転を行う
extern	int			VectorTransform(              VECTOR *Out, VECTOR *InVec, MATRIX *InMatrix ) ;							// ベクトル行列と4x4正方行列を乗算する( w は 1 と仮定 )
extern	int			VectorTransform4(             VECTOR *Out, float *V4Out, VECTOR *InVec, float *V4In, MATRIX *InMatrix ) ; // ベクトル行列と4x4正方行列を乗算する( w の要素を渡す )

extern	void		TriangleBarycenter(           VECTOR TrianglePos1, VECTOR TrianglePos2, VECTOR TrianglePos3, VECTOR Position, float *u, float *v, float *w ) ;	// 指定の座標から三角形の重心を求める

extern	float		Segment_Segment_MinLength(         VECTOR SegmentAPos1, VECTOR SegmentAPos2, VECTOR SegmentBPos1, VECTOR SegmentBPos2 ) ;						// 二つの線分の最近点間の距離を得る
extern	float		Segment_Segment_MinLength_Square(  VECTOR SegmentAPos1, VECTOR SegmentAPos2, VECTOR SegmentBPos1, VECTOR SegmentBPos2 ) ;						// 二つの線分の最近点間の距離の二乗を得る
extern	float		Segment_Triangle_MinLength(        VECTOR SegmentPos1, VECTOR SegmentPos2, VECTOR TrianglePos1, VECTOR TrianglePos2, VECTOR TrianglePos3 ) ;	// 線分と三角形の最近点間の距離を得る 
extern	float		Segment_Triangle_MinLength_Square( VECTOR SegmentPos1, VECTOR SegmentPos2, VECTOR TrianglePos1, VECTOR TrianglePos2, VECTOR TrianglePos3 ) ;	// 線分と三角形の最近点間の距離の二乗を得る 
extern	float		Segment_Point_MinLength(           VECTOR SegmentPos1, VECTOR SegmentPos2, VECTOR PointPos ) ;													// 線分と点の一番近い距離を得る
extern	float		Segment_Point_MinLength_Square(    VECTOR SegmentPos1, VECTOR SegmentPos2, VECTOR PointPos ) ;													// 線分と点の一番近い距離の二乗を得る
extern	float		Triangle_Point_MinLength(          VECTOR TrianglePos1, VECTOR TrianglePos2, VECTOR TrianglePos3, VECTOR PointPos ) ;							// 三角形と点の一番近い距離を得る
extern	float		Triangle_Point_MinLength_Square(   VECTOR TrianglePos1, VECTOR TrianglePos2, VECTOR TrianglePos3, VECTOR PointPos ) ;							// 三角形と点の一番近い距離の二乗を得る
extern	VECTOR		Plane_Point_MinLength_Position(    VECTOR PlanePos, VECTOR PlaneNormal, VECTOR PointPos ) ;														// 点に一番近い平面上の座標を得る
extern	float		Plane_Point_MinLength(             VECTOR PlanePos, VECTOR PlaneNormal, VECTOR PointPos ) ;														// 平面と点の一番近い距離を得る

extern	HITRESULT_LINE HitCheck_Line_Triangle(         VECTOR LinePos1, VECTOR LinePos2, VECTOR TrianglePos1, VECTOR TrianglePos2, VECTOR TrianglePos3 ) ;										// 三角形と線の当たり判定
extern	int			HitCheck_Triangle_Triangle(        VECTOR Triangle1Pos1, VECTOR Triangle1Pos2, VECTOR Triangle1Pos3, VECTOR Triangle2Pos1, VECTOR Triangle2Pos2, VECTOR Triangle2Pos3 ) ;	// 三角形と三角形の当たり判定( TRUE:当たっている  FALSE:当たっていない )
extern	int			HitCheck_Line_Sphere(              VECTOR LinePos1, VECTOR LinePos2, VECTOR SphereCenterPos, float SphereR ) ;																// 線と球の当たり判定( TRUE:当たっている  FALSE:当たっていない )
extern	int			HitCheck_Sphere_Sphere(            VECTOR Sphere1CenterPos, float Sphere1R, VECTOR Sphere2CenterPos, float Sphere2R ) ;														// 球と球の当たり判定( TRUE:当たっている  FALSE:当たっていない )
extern	int			HitCheck_Sphere_Triangle(          VECTOR SphereCenterPos, float SphereR, VECTOR TrianglePos1, VECTOR TrianglePos2, VECTOR TrianglePos3 ) ;									// 球と三角形の当たり判定( TRUE:当たっている  FALSE:当たっていない )
extern	int			HitCheck_Capsule_Capsule(          VECTOR Cap1Pos1, VECTOR Cap1Pos2, float Cap1R, VECTOR Cap2Pos1, VECTOR Cap2Pos2, float Cap2R ) ;											// カプセル同士の当たり判定( TRUE:当たっている  FALSE:当たっていない )
extern	int			HitCheck_Capsule_Triangle(         VECTOR CapPos1, VECTOR CapPos2, float CapR, VECTOR TrianglePos1, VECTOR TrianglePos2, VECTOR TrianglePos3 ) ;							// カプセルと三角形の当たり判定( TRUE:当たっている  FALSE:当たっていない )

// その他
extern	int			RectClipping( RECT *MotoRect, RECT *ClippuRect ) ;							// 矩形のクリッピング
extern	int			RectAdjust(   RECT *Rect ) ;												// 矩形の left が right より値が大きい場合などの誤りを補正する
extern	int			GetRectSize(  RECT *Rect, int *Width, int *Height ) ;						// 矩形の幅と高さを求める

// 表記簡略版
extern	MATRIX		MGetIdent(     void ) ;														// 単位行列を取得する
extern	MATRIX		MMult(         MATRIX In1, MATRIX In2 ) ;									// 行列の乗算を行う
extern	MATRIX		MScale(        MATRIX InM, float Scale ) ;									// 行列のスケーリングを行う
extern	MATRIX		MAdd(          MATRIX In1, MATRIX In2 ) ;									// 行列の足し算を行う
extern	MATRIX		MGetScale(     VECTOR Scale ) ;												// 拡大行列を取得する
extern	MATRIX		MGetRotX(      float XAxisRotate ) ;										// Ｘ軸回転行列を取得する
extern	MATRIX		MGetRotY(      float YAxisRotate ) ;										// Ｙ軸回転行列を取得する
extern	MATRIX		MGetRotZ(      float ZAxisRotate ) ;										// Ｚ軸回転行列を取得する
extern	MATRIX		MGetRotAxis(   VECTOR RotateAxis, float Rotate ) ;							// 指定軸で指定角度回転する行列を取得する
extern	MATRIX		MGetRotVec2(   VECTOR In1, VECTOR In2 ) ;									// In1 の向きから In2 の向きへ変換する回転行列を取得する( In2 と In1 が真逆のベクトルの場合は回転軸は不定 )
extern	MATRIX		MGetTranslate( VECTOR Trans ) ;												// 平行移動行列を取得する
extern	MATRIX		MGetAxis1(     VECTOR XAxis, VECTOR YAxis, VECTOR ZAxis, VECTOR Pos ) ;		// 指定の３軸ローカルのベクトルを基本軸上のベクトルに変換する行列を取得する( x' = XAxis.x * x + YAixs.x * y + ZAxis.z * z + Pos.x   y' = XAxis.y * x + YAixs.y * y + ZAxis.y * z + Pos.y      z' = XAxis.z * x + YAixs.z * y + ZAxis.z * z + Pos.z )
extern	MATRIX		MGetAxis2(     VECTOR XAxis, VECTOR YAxis, VECTOR ZAxis, VECTOR Pos ) ;		// 基本軸上のベクトルを指定の３軸上に投影したベクトルに変換する行列を取得する( x' = XAxis.x * ( x - Pos.x ) + XAxis.y * ( x - Pos.x ) + XAxis.z * ( x - Pos.x )    y' = YAxis.x * ( x - Pos.x ) + YAxis.y * ( x - Pos.x ) + YAxis.z * ( x - Pos.x )    z' = ZAxis.x * ( x - Pos.x ) + ZAxis.y * ( x - Pos.x ) + ZAxis.z * ( x - Pos.x ) )
extern	MATRIX		MTranspose(    MATRIX InM ) ;												// 転置行列を取得する
extern	MATRIX		MInverse(      MATRIX InM ) ;												// 逆行列を取得する
extern  VECTOR		MGetSize(      MATRIX InM ) ;												// 拡大行列のＸ軸、Ｙ軸、Ｚ軸の拡大率を取得する

// ベクトル値の生成
__inline VECTOR VGet( float x, float y, float z )
{
	VECTOR Result;
	Result.x = x ;
	Result.y = y ;
	Result.z = z ;
	return Result ;
}

// ４要素ベクトル値の生成
__inline FLOAT4 F4Get( float x, float y, float z, float w )
{
	FLOAT4 Result;
	Result.x = x ;
	Result.y = y ;
	Result.z = z ;
	Result.w = w ;
	return Result ;
}

// ベクトルの加算
__inline VECTOR		VAdd( const VECTOR &In1, const VECTOR &In2 )
{
	VECTOR Result ;
	Result.x = In1.x + In2.x ;
	Result.y = In1.y + In2.y ;
	Result.z = In1.z + In2.z ;
	return Result ;
}

// ベクトルの減算
__inline VECTOR		VSub( const VECTOR &In1, const VECTOR &In2 )
{
	VECTOR Result ;
	Result.x = In1.x - In2.x ;
	Result.y = In1.y - In2.y ;
	Result.z = In1.z - In2.z ;
	return Result ;
}

// ４要素ベクトルの加算
__inline FLOAT4		F4Add( const FLOAT4 &In1, const FLOAT4 &In2 )
{
	FLOAT4 Result ;
	Result.x = In1.x + In2.x ;
	Result.y = In1.y + In2.y ;
	Result.z = In1.z + In2.z ;
	Result.w = In1.w + In2.w ;
	return Result ;
}

// ４要素ベクトルの減算
__inline FLOAT4		F4Sub( const FLOAT4 &In1, const FLOAT4 &In2 )
{
	FLOAT4 Result ;
	Result.x = In1.x - In2.x ;
	Result.y = In1.y - In2.y ;
	Result.z = In1.z - In2.z ;
	Result.w = In1.w - In2.w ;
	return Result ;
}

// ベクトルの内積
__inline float		VDot( const VECTOR &In1, const VECTOR &In2 )
{
	return In1.x * In2.x + In1.y * In2.y + In1.z * In2.z ;
}

// ベクトルの外積
__inline VECTOR		VCross( const VECTOR &In1, const VECTOR &In2 )
{
	VECTOR Result ;
	Result.x = In1.y * In2.z - In1.z * In2.y ;
	Result.y = In1.z * In2.x - In1.x * In2.z ;
	Result.z = In1.x * In2.y - In1.y * In2.x ;
	return Result ;
}

// ベクトルのスケーリング
__inline VECTOR		VScale( const VECTOR &In, float Scale )
{
	VECTOR Result ;
	Result.x = In.x * Scale ;
	Result.y = In.y * Scale ;
	Result.z = In.z * Scale ;
	return Result ;
}

// ４要素ベクトルのスケーリング
__inline FLOAT4		F4Scale( const FLOAT4 &In, float Scale )
{
	FLOAT4 Result ;
	Result.x = In.x * Scale ;
	Result.y = In.y * Scale ;
	Result.z = In.z * Scale ;
	Result.w = In.w * Scale ;
	return Result ;
}

// ベクトルの正規化
extern VECTOR		VNorm( VECTOR In ) ;

// ベクトルのサイズ
extern float		VSize( VECTOR In ) ;

// ベクトルのサイズの２乗
__inline float		VSquareSize( const VECTOR &In )
{
	return In.x * In.x + In.y * In.y + In.z * In.z ;
}

// 行列を使った座標変換
__inline VECTOR		VTransform( const VECTOR &InV, const MATRIX &InM )
{
	VECTOR Result ;
	Result.x = InV.x * InM.m[0][0] + InV.y * InM.m[1][0] + InV.z * InM.m[2][0] + InM.m[3][0] ;
	Result.y = InV.x * InM.m[0][1] + InV.y * InM.m[1][1] + InV.z * InM.m[2][1] + InM.m[3][1] ;
	Result.z = InV.x * InM.m[0][2] + InV.y * InM.m[1][2] + InV.z * InM.m[2][2] + InM.m[3][2] ;
	return Result ;
}

// 行列を使った座標変換( スケーリング＋回転成分のみ )
__inline VECTOR		VTransformSR( const VECTOR &InV, const MATRIX &InM )
{
	VECTOR Result ;
	Result.x = InV.x * InM.m[0][0] + InV.y * InM.m[1][0] + InV.z * InM.m[2][0] ;
	Result.y = InV.x * InM.m[0][1] + InV.y * InM.m[1][1] + InV.z * InM.m[2][1] ;
	Result.z = InV.x * InM.m[0][2] + InV.y * InM.m[1][2] + InV.z * InM.m[2][2] ;
	return Result ;
}

// 二つのベクトルが成す角のコサイン値を得る
extern	float		VCos( VECTOR In1, VECTOR In2 ) ;

// 二つのベクトルが成す角の角度を得る( 単位：ラジアン )
extern	float		VRad( VECTOR In1, VECTOR In2 ) ;








// DxBaseImage.cpp 関数プロトタイプ宣言

// 基本イメージデータのロード＋ＤＩＢ関係
extern	int			CreateGraphImageOrDIBGraph(    const TCHAR *FileName, void *DataImage, int DataImageSize, int DataImageType /* LOADIMAGE_TYPE_FILE 等 */ , int BmpFlag, int ReverseFlag, BASEIMAGE *Image, BITMAPINFO **BmpInfo, void **GraphData ) ;				// 画像ファイル若しくはメモリ上に展開された画像ファイルイメージを読み込み、基本イメージデータ若しくはＢＭＰデータを構築する
extern	int			CreateGraphImageType2(         STREAMDATA *Src, BASEIMAGE *Dest ) ;																																													// 画像データから構築したストリーム読み込み用データを使用して基本イメージデータを構築する
extern	int			CreateBmpInfo(                 BITMAPINFO *BmpInfo, int Width, int Height, int Pitch, void *SrcGrData, void **DestGrData ) ;																														// 24bitカラー形式のビットマップデータからＢＭＰデータを構築する
extern	DWORD		GetGraphImageFullColorCode(    BASEIMAGE *GraphImage, int x, int y ) ;																																												// 基本イメージデータの指定座標のフルカラーコードを取得する
extern	int			CreateGraphImage_plus_Alpha(   const TCHAR *FileName, void *RgbImage, int RgbImageSize, int RgbImageType, void *AlphaImage, int AlphaImageSize, int AlphaImageType, BASEIMAGE *RgbGraphImage, BASEIMAGE *AlphaGraphImage, int ReverseFlag ) ;		// 画像ファイル若しくはメモリ上に展開された画像ファイルイメージを読み込み、基本イメージデータを構築する
extern	int			ReverseGraphImage(             BASEIMAGE *GraphImage ) ;																																															// 基本イメージデータを左右反転する
#ifdef __WINDOWS__
extern	HBITMAP		CreateDIBGraph(                const TCHAR *FileName,                                                                                                                            int ReverseFlag,          COLORDATA *SrcColor) ;					// 画像ファイルからＤＩＢデータを作成する
extern	HBITMAP		CreateDIBGraphToMem(           BITMAPINFO *BmpInfo, void *GraphData,                                                                                                             int ReverseFlag,          COLORDATA *SrcColor ) ;					// ＢＭＰデータからＤＩＢデータクを作成する
extern	int			CreateDIBGraph_plus_Alpha(     const TCHAR *FileName, HBITMAP *RGBBmp, HBITMAP *AlphaBmp,                                                                                        int ReverseFlag = FALSE , COLORDATA *SrcColor = NULL ) ;			// 画像ファイルからＤＩＢデータとマスク用ＤＩＢデータを作成する
extern	HBITMAP		CreateDIBGraphVer2(            const TCHAR *FileName, void *MemImage, int MemImageSize,                                       int ImageType,                                     int ReverseFlag,          COLORDATA *SrcColor ) ;					// 画像ファイル若しくはメモリ上に展開された画像ファイルイメージからＤＩＢデータを作成する
extern	int			CreateDIBGraphVer2_plus_Alpha( const TCHAR *FileName, void *MemImage, int MemImageSize, void *AlphaImage, int AlphaImageSize, int ImageType, HBITMAP *RGBBmp, HBITMAP *AlphaBmp, int ReverseFlag,          COLORDATA *SrcColor ) ;					// 画像ファイル若しくはメモリ上に展開された画像ファイルイメージからＤＩＢデータとマスク用ＤＩＢデータを作成する
extern	int			ConvBitmapToGraphImage(        BITMAPINFO *BmpInfo, void *GraphData, BASEIMAGE *GraphImage, int CopyFlag ) ;																																		// ＢＭＰデータから基本イメージデータを構築する( Ret 0:正常終了  1:コピーを行った  -1:エラー )
extern	int			ConvGraphImageToBitmap(        BASEIMAGE *GraphImage, BITMAPINFO *BmpInfo, void **GraphData, int CopyFlag, int FullColorConv = TRUE ) ;																												// 基本イメージデータをＢＭＰデータに変換するGraphImage を ＢＭＰ に変換する(アルファデータはあっても無視される)( 戻り値　0:正常終了  1:コピーを行った  -1:エラー )
#endif // __WINDOWS__

//extern int		AddUserGraphLoadFunction( int ( *UserLoadFunc )( FILE *fp, BITMAPINFO **BmpInfo, void **GraphData ) ) ;																					// ユーザー定義の画像データ読み込み関数を登録する
//extern int		AddUserGraphLoadFunction2( int ( *UserLoadFunc )( void *Image, int ImageSize, int ImageType, BITMAPINFO **BmpInfo, void **GraphData ) ) ;												// ユーザー定義の画像データ読み込み関数を登録する
//extern int		AddUserGraphLoadFunction3( int ( *UserLoadFunc )( void *DataImage, int DataImageSize, int DataImageType, int BmpFlag, BASEIMAGE *Image, BITMAPINFO **BmpInfo, void **GraphData ) ) ;	// ユーザー定義の画像データ読み込み関数Ver3を登録する
extern	int			AddUserGraphLoadFunction4( int (* UserLoadFunc )( STREAMDATA *Src, BASEIMAGE *Image ) ) ; 																								// ユーザー定義の画像データ読み込み関数Ver4を登録する
//extern int		SubUserGraphLoadFunction( int ( *UserLoadFunc )( FILE *fp, BITMAPINFO **BmpInfo, void **GraphData ) ) ;																					// ユーザー定義の画像データ読み込み関数を登録から抹消する
//extern int		SubUserGraphLoadFunction2( int ( *UserLoadFunc )( void *Image, int ImageSize, int ImageType, BITMAPINFO **BmpInfo, void **GraphData ) ) ;												// ユーザー定義の画像データ読み込み関数を登録から抹消する
//extern int		SubUserGraphLoadFunction3( int ( *UserLoadFunc )( void *DataImage, int DataImageSize, int DataImageType, int BmpFlag, BASEIMAGE *Image, BITMAPINFO **BmpInfo, void **GraphData ) ) ;	// ユーザー定義の画像データ読み込み関数Ver3を登録から抹消する
extern	int			SubUserGraphLoadFunction4( int (* UserLoadFunc )( STREAMDATA *Src, BASEIMAGE *Image ) ) ; 																								// ユーザー定義の画像データ読み込み関数Ver4を登録から抹消する

extern	int			SetUseFastLoadFlag(            int Flag ) ;														// 高速読み込みルーチンを使用するかどうかを設定する( TRUE:使用する( デフォルト )  FALSE:使用しない )
extern	int			SetGraphDataShavedMode(        int ShavedMode /* DX_SHAVEDMODE_NONE 等 */ ) ;					// 画像減色時の画像劣化緩和処理モードを設定する( デフォルトでは緩和処理無しの DX_SHAVEDMODE_NONE )
extern	int			GetGraphDataShavedMode(        void ) ;															// 画像減色時の画像劣化緩和処理モードを取得する

// 基本イメージデータ構造体関係
extern	int			CreateBaseImage(               const TCHAR *FileName, void *FileImage, int FileImageSize, int DataType /*=LOADIMAGE_TYPE_FILE*/ , BASEIMAGE *BaseImage,  int ReverseFlag ) ;			// 画像ファイル若しくはメモリ上に展開された画像ファイルイメージから基本イメージデータを構築する
extern	int			CreateGraphImage(              const TCHAR *FileName, void *DataImage, int DataImageSize, int DataImageType,                      BASEIMAGE *GraphImage, int ReverseFlag ) ;			// CreateBaseImage の旧名称
extern	int			CreateBaseImageToFile(         const TCHAR *FileName,                                                                             BASEIMAGE *BaseImage,  int ReverseFlag = FALSE ) ;	// 画像ファイルから基本イメージデータを構築する
extern	int			CreateBaseImageToMem(                                 void *FileImage, int FileImageSize,                                         BASEIMAGE *BaseImage,  int ReverseFlag = FALSE ) ;	// メモリ上に展開された画像ファイルイメージから基本イメージデータを構築する
extern	int			CreateARGB8ColorBaseImage(     int SizeX, int SizeY,                       BASEIMAGE *BaseImage ) ;																						// ＡＲＧＢ８カラーの基本イメージデータを作成する
extern	int			CreateXRGB8ColorBaseImage(     int SizeX, int SizeY,                       BASEIMAGE *BaseImage ) ;																						// ＸＲＧＢ８カラーの基本イメージデータを作成する
extern	int			CreateRGB8ColorBaseImage(      int SizeX, int SizeY,                       BASEIMAGE *BaseImage ) ;																						// ＲＧＢ８カラーの基本イメージデータを作成する
extern	int			CreateARGB4ColorBaseImage(     int SizeX, int SizeY,                       BASEIMAGE *BaseImage ) ;																						// ＡＲＧＢ４カラーの基本イメージデータを作成する
extern	int			CreatePAL8ColorBaseImage(      int SizeX, int SizeY,                       BASEIMAGE *BaseImage ) ;																						// パレット８ビットカラーの基本イメージデータを作成する
extern	int			CreateColorDataBaseImage(      int SizeX, int SizeY, COLORDATA *ColorData, BASEIMAGE *BaseImage ) ;																						// 指定のカラーフォーマットの基本イメージデータを作成する
extern	int			GetBaseImageGraphDataSize(     BASEIMAGE *BaseImage ) ;																																	// 基本イメージデータのイメージサイズを取得する( 単位：byte )

extern	int			ReleaseBaseImage(              BASEIMAGE *BaseImage ) ;																																	// 基本イメージデータの後始末を行う
extern	int			ReleaseGraphImage(             BASEIMAGE *GraphImage ) ;																																// ReleaseBaseImage の旧名称

extern	int			ConvertNormalFormatBaseImage(  BASEIMAGE *BaseImage ) ;																																	// DX_BASEIMAGE_FORMAT_NORMAL 以外の形式のイメージを DX_BASEIMAGE_FORMAT_NORMAL 形式のイメージに変換する

extern	int			GetDrawScreenBaseImage(        int x1, int y1, int x2, int y2, BASEIMAGE *BaseImage ) ;																									// 描画対象の画面から指定領域を基本イメージデータに転送する
#ifdef __WINDOWS__
extern	int			UpdateLayerdWindowForBaseImage(                   BASEIMAGE *BaseImage ) ;																												// 基本イメージデータを使用して UpdateLayerdWindow を行う
extern	int			UpdateLayerdWindowForPremultipliedAlphaBaseImage( BASEIMAGE *BaseImage ) ;																												// 乗算済みアルファの基本イメージデータを使用して UpdateLayerdWindow を行う
#endif // __WINDOWS__
extern	int			FillBaseImage(                 BASEIMAGE *BaseImage, int r, int g, int b, int a ) ;																										// 基本イメージデータを指定の色で塗りつぶす
extern	int			ClearRectBaseImage(            BASEIMAGE *BaseImage, int x, int y, int w, int h ) ;																										// 基本イメージデータの指定の領域を０クリアする
extern	int			GetPaletteBaseImage(           BASEIMAGE *BaseImage, int PaletteNo, int *r, int *g, int *b, int *a ) ;																					// 基本イメージデータのパレットを取得する
extern	int			SetPaletteBaseImage(           BASEIMAGE *BaseImage, int PaletteNo, int  r, int  g, int  b, int  a ) ;																					// 基本イメージデータのパレットをセットする
extern	int			SetPixelPalCodeBaseImage(      BASEIMAGE *BaseImage, int x, int y, int palNo ) ;																										// 基本イメージデータの指定の座標の色コードを変更する(パレット画像用)
extern	int			GetPixelPalCodeBaseImage(      BASEIMAGE *BaseImage, int x, int y ) ;																													// 基本イメージデータの指定の座標の色コードを取得する(パレット画像用)
extern	int			SetPixelBaseImage(             BASEIMAGE *BaseImage, int x, int y, int  r, int  g, int  b, int  a ) ;																					// 基本イメージデータの指定の座標の色を変更する(各色要素は０〜２５５)
extern	int			GetPixelBaseImage(             BASEIMAGE *BaseImage, int x, int y, int *r, int *g, int *b, int *a ) ;																					// 基本イメージデータの指定の座標の色を取得する(各色要素は０〜２５５)
extern	int			DrawLineBaseImage(             BASEIMAGE *BaseImage, int x1, int y1, int x2, int y2, int r, int g, int b, int a ) ;																		// 基本イメージデータの指定の座標に線を描画する(各色要素は０〜２５５)
extern	int			BltBaseImage(                  int SrcX, int SrcY, int SrcSizeX, int SrcSizeY, int DestX, int DestY, BASEIMAGE *SrcBaseImage, BASEIMAGE *DestBaseImage ) ;								// 基本イメージデータを別の基本イメージデータに転送する
extern	int			BltBaseImage(                                                                  int DestX, int DestY, BASEIMAGE *SrcBaseImage, BASEIMAGE *DestBaseImage ) ;								// 基本イメージデータを別の基本イメージデータに転送する
extern	int			BltBaseImageWithTransColor(    int SrcX, int SrcY, int SrcSizeX, int SrcSizeY, int DestX, int DestY, BASEIMAGE *SrcBaseImage, BASEIMAGE *DestBaseImage, int Tr, int Tg, int Tb, int Ta ) ;	// 基本イメージデータを別の基本イメージデータに透過色処理付きで転送する
extern	int			BltBaseImageWithAlphaBlend(    int SrcX, int SrcY, int SrcSizeX, int SrcSizeY, int DestX, int DestY, BASEIMAGE *SrcBaseImage, BASEIMAGE *DestBaseImage, int Opacity = 255 ) ;			// 基本イメージデータを別の基本イメージデータにアルファ値のブレンドを考慮した上で転送する( Opacity は透明度 : 0( 完全透明 ) 〜 255( 完全不透明 ) )( 出力先が ARGB8 形式以外の場合はエラーになります )
extern	int			ReverseBaseImageH(             BASEIMAGE *BaseImage ) ;																																	// 基本イメージデータを左右反転する
extern	int			ReverseBaseImageV(             BASEIMAGE *BaseImage ) ;																																	// 基本イメージデータを上下反転する
extern	int			ReverseBaseImage(              BASEIMAGE *BaseImage ) ;																																	// 基本イメージデータを上下左右反転する
extern	int			CheckPixelAlphaBaseImage(      BASEIMAGE *BaseImage ) ;																																	// 基本イメージデータに含まれるピクセルのアルファ値をチェックする( 戻り値   -1:エラー  0:画像にアルファ成分が無い  1:画像にアルファ成分があり、すべて最大(255)値  2:画像にアルファ成分があり、存在するアルファ値は最小(0)と最大(255)もしくは最小(0)のみ　3:画像にアルファ成分があり、最小と最大以外の中間の値がある )  

#ifndef DX_NON_SAVEFUNCTION

extern	int			SaveBaseImageToBmp(            const TCHAR *FilePath, BASEIMAGE *BaseImage ) ;																											// 基本イメージデータをＢＭＰ画像として保存する
#ifndef DX_NON_PNGREAD
extern	int			SaveBaseImageToPng(            const TCHAR *FilePath, BASEIMAGE *BaseImage, int CompressionLevel ) ;																					// 基本イメージデータをＰＮＧ画像として保存する
#endif // DX_NON_PNGREAD
#ifndef DX_NON_JPEGREAD
extern	int			SaveBaseImageToJpeg(           const TCHAR *FilePath, BASEIMAGE *BaseImage, int Quality, int Sample2x1 ) ;																				// 基本イメージデータをＪＰＥＧ画像として保存する
#endif // DX_NON_JPEGREAD

#endif // DX_NON_SAVEFUNCTION

// 基本イメージ描画
extern	int			DrawBaseImage(					int x, int y, BASEIMAGE *BaseImage ) ;																													// 基本イメージデータを描画する

// カラーマッチングしながらイメージデータ間転送を行う Ver2
extern int			GraphColorMatchBltVer2( void *DestGraphData, int DestPitch,  COLORDATA *DestColorData,
											void *SrcGraphData,  int SrcPitch,   COLORDATA *SrcColorData,
											void *AlphaMask,     int AlphaPitch, COLORDATA *AlphaColorData,
											POINT DestPoint, RECT *SrcRect, int ReverseFlag,
											int TransColorAlphaTestFlag, unsigned int TransColor,
											int ImageShavedMode, int AlphaOnlyFlag = FALSE ,
											int RedIsAlphaFlag = FALSE , int TransColorNoMoveFlag = FALSE ,
											int Pal8ColorMatch = FALSE ) ;


// 色情報取得関係
extern	COLOR_F		GetColorF(              float Red, float Green, float Blue, float Alpha ) ;										// 浮動小数点型のカラー値を作成する
extern	COLOR_U8	GetColorU8(             int Red, int Green, int Blue, int Alpha ) ;												// 符号なし整数８ビットのカラー値を作成する
extern	DWORD		GetColor(               int Red, int Green, int Blue ) ;														// ３原色の値から現在の画面モードに対応したカラー値を得る
extern	int			GetColor2(              int Color, int *Red, int *Green, int *Blue ) ;											// 画面モードに対応したカラー値から個々の３原色の値を抜き出す
extern	int			GetColor3(              COLORDATA *ColorData, int Red, int Green, int Blue, int Alpha = 255 ) ;					// ３原色の値から指定のピクセルフォーマットに対応したカラー値を得る
extern	int			GetColor4(              COLORDATA *DestColorData, COLORDATA* SrcColorData, int SrcColor ) ;						// 指定のカラーフォーマットのカラー値を別のカラーフォーマットのカラー値に変換する
extern	int			GetColor5(              COLORDATA *ColorData, int Color, int *Red, int *Green, int *Blue, int *Alpha = NULL ) ;	// 指定のカラーフォーマットのカラー値を３原色の値に変換する
extern	int			CreatePaletteColorData( COLORDATA *ColorDataBuf ) ;																// パレットカラーのカラーフォーマットを構築する
extern	int			CreateXRGB8ColorData(   COLORDATA *ColorDataBuf ) ;																// ＸＲＧＢ８カラーのカラーフォーマットを構築する
extern	int			CreateARGB8ColorData(   COLORDATA *ColorDataBuf ) ;																// ＡＲＧＢ８カラーのカラーフォーマットを構築する
extern	int			CreateARGB4ColorData(   COLORDATA *ColorDataBuf ) ;																// ＡＲＧＢ４カラーのカラーフォーマットを構築する
extern	int			CreateFullColorData(    COLORDATA *ColorDataBuf ) ;																// ２４ビットカラーのカラーフォーマットを構築する
extern	int			CreateGrayColorData(    COLORDATA *ColorDataBuf ) ;																// グレースケールのカラーフォーマットを構築する
extern	int			CreatePal8ColorData(    COLORDATA *ColorDataBuf ) ;																// パレット２５６色のカラーフォーマットを構築する
extern	int			CreateColorData(        COLORDATA *ColorDataBuf, int ColorBitDepth,
									        DWORD RedMask, DWORD GreenMask, DWORD BlueMask, DWORD AlphaMask,
									        int ChannelNum = 0, int ChannelBitDepth = 0, int FloatTypeFlag = FALSE ) ;				// カラーフォーマットを作成する
extern	void		SetColorDataNoneMask(   COLORDATA *ColorData ) ;																// NoneMask 以外の要素を埋めた COLORDATA 構造体の情報を元に NoneMask をセットする
extern	int			CmpColorData(           COLORDATA *ColorData1, COLORDATA *ColorData2 ) ;										// 二つのカラーフォーマットが等しいかどうか調べる( 戻り値　TRUE:等しい  FALSE:等しくない )

#endif // DX_NOTUSE_DRAWFUNCTION













// DxSoftImage.cpp関数プロトタイプ宣言
#ifndef DX_NON_SOFTIMAGE
extern	int			InitSoftImage(                   void ) ;																			// ソフトウエアイメージハンドルを全て削除する
extern	int			LoadSoftImage(                   const TCHAR *FileName ) ;															// 画像ファイルを読み込みソフトウエアイメージハンドルを作成する( -1:エラー  -1以外:イメージハンドル )
extern	int			LoadSoftImageToMem(              void *FileImage, int FileImageSize ) ;												// メモリ上に展開された画像ファイルイメージからソフトウエアイメージハンドルを作成する( -1:エラー  -1以外:イメージハンドル )
extern	int			MakeSoftImage(                   int SizeX, int SizeY ) ;															// ソフトウエアイメージハンドルの作成( -1:エラー  -1以外:イメージハンドル )
extern	int			MakeARGB8ColorSoftImage(         int SizeX, int SizeY ) ;															// ソフトウエアイメージハンドルの作成( RGBA8 カラー )
extern	int			MakeXRGB8ColorSoftImage(         int SizeX, int SizeY ) ;															// ソフトウエアイメージハンドルの作成( XRGB8 カラー )
extern	int			MakeARGB4ColorSoftImage(         int SizeX, int SizeY ) ;															// ソフトウエアイメージハンドルの作成( ARGB4 カラー )
extern	int			MakeRGB8ColorSoftImage(          int SizeX, int SizeY ) ;															// ソフトウエアイメージハンドルの作成( RGB8 カラー )
extern	int			MakePAL8ColorSoftImage(          int SizeX, int SizeY ) ;															// ソフトウエアイメージハンドルの作成( パレット２５６色 カラー )

extern	int			DeleteSoftImage(                 int SIHandle ) ;																	// ソフトウエアイメージハンドルの削除する

extern	int			GetSoftImageSize(                int SIHandle, int *Width, int *Height ) ;											// ソフトウエアイメージハンドルのサイズを取得する
extern	int			CheckPaletteSoftImage(           int SIHandle ) ;																	// ソフトウエアイメージハンドルがパレット画像かどうかを取得する( TRUE:パレット画像  FALSE:パレット画像じゃない )
extern	int			CheckAlphaSoftImage(             int SIHandle ) ;																	// ソフトウエアイメージハンドルのフォーマットにα要素があるかどうかを取得する( TRUE:ある  FALSE:ない )
extern	int			CheckPixelAlphaSoftImage(        int SIHandle ) ;																	// ソフトウエアイメージハンドルに含まれるピクセルのα値をチェックする( 戻り値   -1:エラー  0:画像にα成分が無い  1:画像にα成分があり、すべて最大(255)値  2:画像にα成分があり、存在するα値は最小(0)と最大(255)もしくは最小(0)のみ　3:画像にα成分があり、最小と最大以外の中間の値がある )  

extern	int			GetDrawScreenSoftImage(          int x1, int y1, int x2, int y2, int SIHandle ) ;									// 描画対象の画面から指定領域をソフトウエアイメージハンドルに転送する
#ifdef __WINDOWS__
extern	int			UpdateLayerdWindowForSoftImage(                   int SIHandle ) ;													// ソフトウエアイメージハンドルを使用して UpdateLayerdWindow を行う( イメージはウインドウのクライアント領域と同じサイズである必要があります )
extern	int			UpdateLayerdWindowForPremultipliedAlphaSoftImage( int SIHandle ) ;													// 乗算済みアルファのソフトウエアイメージハンドルを使用して UpdateLayerdWindow を行う( イメージはウインドウのクライアント領域と同じサイズである必要があります )
#endif // __WINDOWS__
extern	int			FillSoftImage(                   int SIHandle, int r, int g, int b, int a ) ;										// ソフトウエアイメージハンドルを指定色で塗りつぶす(各色要素は０〜２５５)
extern	int			ClearRectSoftImage(              int SIHandle, int x, int y, int w, int h ) ;										// ソフトウエアイメージハンドルの指定の領域を０クリアする
extern	int			GetPaletteSoftImage(             int SIHandle, int PaletteNo, int *r, int *g, int *b, int *a ) ;					// ソフトウエアイメージハンドルのパレットを取得する(各色要素は０〜２５５)
extern	int			SetPaletteSoftImage(             int SIHandle, int PaletteNo, int  r, int  g, int  b, int  a ) ;					// ソフトウエアイメージハンドルのパレットを設定する(各色要素は０〜２５５)
extern	int			DrawPixelPalCodeSoftImage(       int SIHandle, int x, int y, int palNo ) ;											// ソフトウエアイメージハンドルの指定座標にドットを描画する(パレット画像用、有効値は０〜２５５)
extern	int			GetPixelPalCodeSoftImage(        int SIHandle, int x, int y ) ;														// ソフトウエアイメージハンドルの指定座標の色コードを取得する(パレット画像用、戻り値は０〜２５５)
extern	void		*GetImageAddressSoftImage(       int SIHandle ) ;																	// ソフトウエアイメージハンドルの画像が格納されているメモリ領域の先頭アドレスを取得する
extern	int			GetPitchSoftImage(               int SIHandle ) ;																	// ソフトウエアイメージハンドルのメモリに格納されている画像データの1ライン辺りのバイト数を取得する
extern	int			DrawPixelSoftImage(              int SIHandle, int x, int y, int  r, int  g, int  b, int  a ) ;						// ソフトウエアイメージハンドルの指定座標にドットを描画する(各色要素は０〜２５５)
extern	void		DrawPixelSoftImage_Unsafe_XRGB8( int SIHandle, int x, int y, int  r, int  g, int  b ) ;								// ソフトウエアイメージハンドルの指定座標にドットを描画する(各色要素は０〜２５５)、エラーチェックをしない代わりに高速ですが、範囲外の座標や ARGB8 以外のフォーマットのソフトハンドルを渡すと不正なメモリアクセスで強制終了します
extern	void		DrawPixelSoftImage_Unsafe_ARGB8( int SIHandle, int x, int y, int  r, int  g, int  b, int  a ) ;						// ソフトウエアイメージハンドルの指定座標にドットを描画する(各色要素は０〜２５５)、エラーチェックをしない代わりに高速ですが、範囲外の座標や XRGB8 以外のフォーマットのソフトハンドルを渡すと不正なメモリアクセスで強制終了します
extern	int			GetPixelSoftImage(               int SIHandle, int x, int y, int *r, int *g, int *b, int *a ) ;						// ソフトウエアイメージハンドルの指定座標の色を取得する(各色要素は０〜２５５)
extern	void		GetPixelSoftImage_Unsafe_XRGB8(  int SIHandle, int x, int y, int *r, int *g, int *b ) ;								// ソフトウエアイメージハンドルの指定座標の色を取得する(各色要素は０〜２５５)、エラーチェックをしない代わりに高速ですが、範囲外の座標や XRGB8 以外のフォーマットのソフトハンドルを渡すと不正なメモリアクセスで強制終了します
extern	void		GetPixelSoftImage_Unsafe_ARGB8(  int SIHandle, int x, int y, int *r, int *g, int *b, int *a ) ;						// ソフトウエアイメージハンドルの指定座標の色を取得する(各色要素は０〜２５５)、エラーチェックをしない代わりに高速ですが、範囲外の座標や ARGB8 以外のフォーマットのソフトハンドルを渡すと不正なメモリアクセスで強制終了します
extern	int			DrawLineSoftImage(               int SIHandle, int x1, int y1, int x2, int y2, int r, int g, int b, int a ) ;		// ソフトウエアイメージハンドルの指定座標に線を描画する(各色要素は０〜２５５)
extern	int			BltSoftImage(                    int SrcX, int SrcY, int SrcSizeX, int SrcSizeY, int SrcSIHandle, int DestX, int DestY, int DestSIHandle ) ;									// ソフトウエアイメージハンドルを別のソフトウエアイメージハンドルに転送する
extern	int			BltSoftImageWithTransColor(      int SrcX, int SrcY, int SrcSizeX, int SrcSizeY, int SrcSIHandle, int DestX, int DestY, int DestSIHandle, int Tr, int Tg, int Tb, int Ta ) ;	// ソフトウエアイメージハンドルを別のソフトウエアイメージハンドルに透過色処理付きで転送する
extern	int			BltSoftImageWithAlphaBlend(      int SrcX, int SrcY, int SrcSizeX, int SrcSizeY, int SrcSIHandle, int DestX, int DestY, int DestSIHandle, int Opacity = 255 ) ;					// ソフトウエアイメージハンドルを別のソフトウエアイメージハンドルにアルファ値のブレンドを考慮した上で転送する( Opacity は透明度 : 0( 完全透明 ) 〜 255( 完全不透明 ) )( 出力先が ARGB8 形式以外の場合はエラーになります )
extern	int			ReverseSoftImageH(               int SIHandle ) ;																	// ソフトウエアイメージハンドルを左右反転する
extern	int			ReverseSoftImageV(               int SIHandle ) ;																	// ソフトウエアイメージハンドルを上下反転する
extern	int			ReverseSoftImage(                int SIHandle ) ;																	// ソフトウエアイメージハンドルを上下左右反転する

#ifndef DX_NON_FONT
extern	int			BltStringSoftImage(              int x, int y, const TCHAR *StrData, int DestSIHandle, int DestEdgeSIHandle = -1 ,                                        int VerticalFlag = FALSE ) ;		// ソフトウエアイメージハンドルに文字列を描画する( デフォルトフォントハンドルを使用する )
extern	int			BltStringSoftImageToHandle(      int x, int y, const TCHAR *StrData, int DestSIHandle, int DestEdgeSIHandle /* 縁が必要ない場合は -1 */ , int FontHandle, int VerticalFlag = FALSE ) ;		// ソフトウエアイメージハンドルに文字列を描画する( フォントハンドル使用版 )
#endif // DX_NON_FONT

extern	int			DrawSoftImage(                   int x, int y, int SIHandle ) ;														// ソフトウエアイメージハンドルを画面に描画する

#ifndef DX_NON_SAVEFUNCTION

extern	int			SaveSoftImageToBmp(              const TCHAR *FilePath, int SIHandle ) ;											// ソフトウエアイメージハンドルをＢＭＰ画像ファイルとして保存する
#ifndef DX_NON_PNGREAD
extern	int			SaveSoftImageToPng(              const TCHAR *FilePath, int SIHandle, int CompressionLevel ) ;						// ソフトウエアイメージハンドルをＰＮＧ画像ファイルとして保存する CompressionLevel = 圧縮率、値が大きいほど高圧縮率高負荷、０は無圧縮,0〜9
#endif // DX_NON_PNGREAD
#ifndef DX_NON_JPEGREAD
extern	int			SaveSoftImageToJpeg(             const TCHAR *FilePath, int SIHandle, int Quality, int Sample2x1 ) ;				// ソフトウエアイメージハンドルをＪＰＥＧ画像ファイルとして保存する Quality = 画質、値が大きいほど低圧縮高画質,0〜100 
#endif // DX_NON_JPEGREAD

#endif // DX_NON_SAVEFUNCTION

#endif // DX_NON_SOFTIMAGE


















#ifndef DX_NON_SOUND

// DxSound.cpp関数プロトタイプ宣言

// サウンドデータ管理系関数
extern	int			InitSoundMem(                        int LogOutFlag = FALSE ) ;																	// 全てのサウンドハンドルを削除する

extern	int			AddSoundData(                        int Handle = -1 ) ;																										// サウンドハンドルを作成する
extern	int			AddStreamSoundMem(                   STREAMDATA *Stream, int LoopNum,  int SoundHandle, int StreamDataType, int *CanStreamCloseFlag, int UnionHandle = -1 ) ;	// ストリーム再生タイプのサウンドハンドルにストリームデータを再生対象に追加する
extern	int			AddStreamSoundMemToMem(              void *FileImage, int FileImageSize, int LoopNum,  int SoundHandle, int StreamDataType, int UnionHandle = -1 ) ;			// ストリーム再生タイプのサウンドハンドルにメモリ上に展開したサウンドファイルイメージを再生対象に追加する
extern	int			AddStreamSoundMemToFile(             const TCHAR *WaveFile, int LoopNum,  int SoundHandle, int StreamDataType, int UnionHandle = -1 ) ;							// ストリーム再生タイプのサウンドハンドルにサウンドファイルを再生対象に追加する
extern	int			SetupStreamSoundMem(                 int SoundHandle ) ;																		// ストリーム再生タイプのサウンドハンドルの再生準備をする
extern	int			PlayStreamSoundMem(                  int SoundHandle, int PlayType = DX_PLAYTYPE_LOOP , int TopPositionFlag = TRUE ) ;			// ストリーム再生タイプのサウンドハンドルの再生を開始する
extern	int			CheckStreamSoundMem(                 int SoundHandle ) ;																		// ストリーム再生タイプのサウンドハンドルの再生状態を取得する
extern	int			StopStreamSoundMem(                  int SoundHandle ) ;																		// ストリーム再生タイプのサウンドハンドルの再生を停止する
extern	int			SetStreamSoundCurrentPosition(       int Byte, int SoundHandle ) ;																// サウンドハンドルの再生位置をバイト単位で変更する(再生が止まっている時のみ有効)
extern	int			GetStreamSoundCurrentPosition(       int SoundHandle ) ;																		// サウンドハンドルの再生位置をバイト単位で取得する
extern	int			SetStreamSoundCurrentTime(           int Time, int SoundHandle ) ;																// サウンドハンドルの再生位置をミリ秒単位で設定する(圧縮形式の場合は正しく設定されない場合がある)
extern	int			GetStreamSoundCurrentTime(           int SoundHandle ) ;																		// サウンドハンドルの再生位置をミリ秒単位で取得する(圧縮形式の場合は正しい値が返ってこない場合がある)
extern	int			ProcessStreamSoundMem(               int SoundHandle ) ;																		// ストリーム再生タイプのサウンドハンドルの周期的な処理を行う関数( 内部で自動的に呼ばれます )
extern	int			ProcessStreamSoundMemAll(            void ) ;																					// 有効なストリーム再生タイプのサウンドハンドルに対して ProcessStreamSoundMem を実行する( 内部で自動的に呼ばれます )


extern	int			LoadSoundMem2(                       const TCHAR *FileName1, const TCHAR *FileName2 ) ;											// 前奏部とループ部に分かれたサウンドファイルを読み込みサウンドハンドルを作成する
extern	int			LoadBGM(                             const TCHAR *FileName ) ;																	// 主にＢＧＭを読み込みサウンドハンドルを作成するのに適した関数

extern	int			LoadSoundMemBase(                    const TCHAR *FileName, int BufferNum,      int UnionHandle = -1 ) ;						// サウンドファイルからサウンドハンドルを作成する
extern	int			LoadSoundMem(                        const TCHAR *FileName, int BufferNum = 3 , int UnionHandle = -1 ) ;						// LoadSoundMemBase の別名関数
extern	int			LoadSoundMemToBufNumSitei(           const TCHAR *FileName, int BufferNum ) ;													// LoadSoundMem を使用して下さい
extern	int			LoadSoundMemByResource(              const TCHAR *ResourceName, const TCHAR *ResourceType, int BufferNum = 1 ) ;				// サウンドリソースからサウンドハンドルを作成する
extern	int			DuplicateSoundMem(                   int SrcSoundHandle, int BufferNum = 3 ) ;													// 同じサウンドデータを使用するサウンドハンドルを作成する( DX_SOUNDDATATYPE_MEMNOPRESS タイプのサウンドハンドルのみ可能 )

extern	int			LoadSoundMemByMemImageBase(          void *FileImage, int FileImageSize, int BufferNum, int UnionHandle = -1 ) ;				// メモリ上に展開されたサウンドファイルイメージからサウンドハンドルを作成する
extern	int			LoadSoundMemByMemImage(              void *FileImage, int FileImageSize,                int UnionHandle = -1 ) ;				// メモリ上に展開されたサウンドファイルイメージからサウンドハンドルを作成する( バッファ数指定無し )
extern	int			LoadSoundMemByMemImage2(             void *WaveImage, int WaveImageSize, WAVEFORMATEX *WaveFormat, int WaveHeaderSize ) ;		// メモリ上に展開されたＰＣＭデータからサウンドハンドルを作成する
extern	int			LoadSoundMemByMemImageToBufNumSitei( void *FileImage, int FileImageSize, int BufferNum ) ;										// LoadSoundMemByMemImageBase を使用して下さい
extern	int			LoadSoundMem2ByMemImage(             void *FileImage1, int FileImageSize1, void *FileImage2, int FileImageSize2 ) ;				// 前奏部とループ部に分かれた二つのメモリ上に展開されたサウンドファイルイメージからサウンドハンドルを作成する
extern	int			LoadSoundMemFromSoftSound(           int SoftSoundHandle, int BufferNum = 3 ) ;													// ソフトウエアサウンドハンドルが持つサウンドデータからサウンドハンドルを作成する

extern	int			DeleteSoundMem(                      int SoundHandle, int LogOutFlag = FALSE ) ;												// サウンドハンドルを削除する

extern	int			PlaySoundMem(                        int SoundHandle, int PlayType, int TopPositionFlag = TRUE ) ;								// サウンドハンドルを再生する
extern	int			StopSoundMem(                                                                        int SoundHandle ) ;						// サウンドハンドルの再生を停止する
extern	int			CheckSoundMem(                                                                       int SoundHandle ) ;						// サウンドハンドルが再生中かどうかを取得する
extern	int			SetPanSoundMem(                      int PanPal,                                     int SoundHandle ) ;						// サウンドハンドルのパンを設定する
extern	int			GetPanSoundMem(                                                                      int SoundHandle ) ;						// サウンドハンドルのパンを取得する
extern	int			SetVolumeSoundMem(                   int VolumePal,                                  int SoundHandle ) ;						// サウンドハンドルのボリュームを設定する( 100分の1デシベル単位 )
extern	int			ChangeVolumeSoundMem(                int VolumePal,                                  int SoundHandle ) ;						// サウンドハンドルのボリュームを設定する( パーセント指定 )
extern	int			GetVolumeSoundMem(                                                                   int SoundHandle ) ;						// サウンドハンドルのボリュームを取得する
extern	int			SetFrequencySoundMem(                int FrequencyPal,                               int SoundHandle ) ;						// サウンドハンドルの再生周波数を設定する
extern	int			GetFrequencySoundMem(                                                                int SoundHandle ) ;						// サウンドハンドルの再生周波数を取得する
extern	int			ResetFrequencySoundMem(                                                              int SoundHandle ) ;						// サウンドハンドルの再生周波数を読み込み直後の状態に戻す

extern	int			SetNextPlayPanSoundMem(              int PanPal,                                     int SoundHandle ) ;						// サウンドハンドルの次の再生にのみ使用するパンを設定する
extern	int			SetNextPlayVolumeSoundMem(           int VolumePal,                                  int SoundHandle ) ;						// サウンドハンドルの次の再生にのみ使用するボリュームを設定する( 100分の1デシベル単位 )
extern	int			ChangeNextPlayVolumeSoundMem(        int VolumePal,                                  int SoundHandle ) ;						// サウンドハンドルの次の再生にのみ使用するボリュームを設定する( パーセント指定 )
extern	int			SetNextPlayFrequencySoundMem(        int FrequencyPal,                               int SoundHandle ) ;						// サウンドハンドルの次の再生にのみ使用する再生周波数を設定する

extern	int			SetCurrentPositionSoundMem(          int SamplePosition,                             int SoundHandle ) ;						// サウンドハンドルの再生位置をサンプル単位で設定する(再生が止まっている時のみ有効)
extern	int			GetCurrentPositionSoundMem(                                                          int SoundHandle ) ;						// サウンドハンドルの再生位置をサンプル単位で取得する
extern	int			SetSoundCurrentPosition(             int Byte,                                       int SoundHandle ) ;						// サウンドハンドルの再生位置をバイト単位で設定する(再生が止まっている時のみ有効)
extern	int			GetSoundCurrentPosition(                                                             int SoundHandle ) ;						// サウンドハンドルの再生位置をバイト単位で取得する
extern	int			SetSoundCurrentTime(                 int Time,                                       int SoundHandle ) ;						// サウンドハンドルの再生位置をミリ秒単位で設定する(圧縮形式の場合は正しく設定されない場合がある)
extern	int			GetSoundCurrentTime(                                                                 int SoundHandle ) ;						// サウンドハンドルの再生位置をミリ秒単位で取得する(圧縮形式の場合は正しい値が返ってこない場合がある)
extern	int			GetSoundTotalSample(                                                                 int SoundHandle ) ;						// サウンドハンドルの音の総時間をサンプル単位で取得する
extern	int			GetSoundTotalTime(                                                                   int SoundHandle ) ;						// サウンドハンドルの音の総時間をミリ秒単位で取得する

extern	int			SetLoopPosSoundMem(                  int LoopTime,                                   int SoundHandle ) ;						// SetLoopTimePosSoundMem の別名関数
extern	int			SetLoopTimePosSoundMem(              int LoopTime,                                   int SoundHandle ) ;						// サウンドハンドルにループ位置を設定する(ミリ秒単位)
extern	int			SetLoopSamplePosSoundMem(            int LoopSamplePosition,                         int SoundHandle ) ;						// サウンドハンドルにループ位置を設定する(サンプル単位)

extern	int			SetLoopStartTimePosSoundMem(         int LoopStartTime,                              int SoundHandle ) ;						// サウンドハンドルにループ開始位置を設定する(ミリ秒単位)
extern	int			SetLoopStartSamplePosSoundMem(       int LoopStartSamplePosition,                    int SoundHandle ) ;						// サウンドハンドルにループ開始位置を設定する(サンプル単位)

extern	int			Set3DPositionSoundMem(               VECTOR Position,                                int SoundHandle ) ;						// サウンドハンドルの３Ｄサウンド用の再生位置を設定する
extern	int			Set3DRadiusSoundMem(                 float Radius,                                   int SoundHandle ) ;						// サウンドハンドルの３Ｄサウンド用の音が聞こえる距離を設定する
extern	int			Set3DVelocitySoundMem(               VECTOR Velocity,                                int SoundHandle ) ;						// サウンドハンドルの３Ｄサウンド用の移動速度を設定する

// 設定関係関数
extern	int			SetCreateSoundDataType(              int SoundDataType ) ;																		// 作成するサウンドハンドルの再生タイプを設定する( DX_SOUNDDATATYPE_MEMNOPRESS 等 )
extern	int			GetCreateSoundDataType(              void ) ;																					// 作成するサウンドハンドルの再生タイプを取得する( DX_SOUNDDATATYPE_MEMNOPRESS 等 )
extern	int			SetDisableReadSoundFunctionMask(     int Mask ) ;																				// 使用しないサウンドデータ読み込み処理のマスクを設定する( DX_READSOUNDFUNCTION_PCM 等 )
extern	int			GetDisableReadSoundFunctionMask(     void ) ;																					// 使用しないサウンドデータ読み込み処理のマスクを取得する( DX_READSOUNDFUNCTION_PCM 等 )
extern	int			SetEnableSoundCaptureFlag(           int Flag ) ;																				// サウンドキャプチャを前提とした動作をするかどうかを設定する
extern	int			SetUseSoftwareMixingSoundFlag(       int Flag ) ;																				// サウンドの処理をソフトウエアで行うかどうかを設定する( TRUE:ソフトウエア  FALSE:ハードウエア( デフォルト ) )
extern	int			SetEnableXAudioFlag(                 int Flag ) ;																				// サウンドの再生にXAudioを使用するかどうかを設定する( TRUE:使用する( デフォルト )  FALSE:使用しない )
extern	int			SetUseOldVolumeCalcFlag(             int Flag ) ;																				// ChangeVolumeSoundMem, ChangeNextPlayVolumeSoundMem, ChangeMovieVolumeToGraph の音量計算式を Ver3.10c以前のものを使用するかどうかを設定する( TRUE:Ver3.10c以前の計算式を使用  FALSE:3.10d以降の計算式を使用( デフォルト ) )

extern	int			SetCreate3DSoundFlag(                    int Flag ) ;																			// 次に作成するサウンドハンドルを３Ｄサウンド用にするかどうかを設定する( TRUE:３Ｄサウンド用にする  FALSE:３Ｄサウンド用にしない( デフォルト ) )
extern	int			Set3DSoundOneMetre(                      float Distance ) ;																		// ３Ｄ空間の１メートルに相当する距離を設定する、DxLib_Init を呼び出す前でのみ呼び出し可能( デフォルト:1.0f )
extern	int			Set3DSoundListenerPosAndFrontPos_UpVecY( VECTOR Position, VECTOR FrontPosition ) ;												// ３Ｄサウンドのリスナーの位置とリスナーの前方位置を設定する( リスナーの上方向はＹ軸固定 )
extern	int			Set3DSoundListenerPosAndFrontPos(        VECTOR Position, VECTOR FrontPosition, VECTOR UpVector ) ;								// ３Ｄサウンドのリスナーの位置とリスナーの前方位置とリスナーの上方向を設定する
extern	int			Set3DSoundListenerVelocity(              VECTOR Velocity ) ;																	// ３Ｄサウンドのリスナーの移動速度を設定する
extern	int			Set3DSoundListenerConeAngle(             float InnerAngle, float OuterAngle ) ;													// ３Ｄサウンドのリスナーの可聴角度範囲を設定する
extern	int			Set3DSoundListenerConeVolume(            float InnerAngleVolume, float OuterAngleVolume ) ;										// ３Ｄサウンドのリスナーの可聴角度範囲の音量倍率を設定する

// 情報取得系関数
extern	void*		GetDSoundObj(                        void ) ;	/* 戻り値を IDirectSound * にキャストして下さい */								// ＤＸライブラリが使用している DirectSound オブジェクトを取得する

#ifndef DX_NON_BEEP
// BEEP音再生用命令
extern	int			SetBeepFrequency(					int Freq ) ;																				// ビープ音周波数設定関数
extern	int			PlayBeep(							void ) ;																					// ビープ音を再生する
extern	int			StopBeep(							void ) ;																					// ビープ音を止める
#endif // DX_NON_BEEP

// ラッパー関数
extern	int			PlaySoundFile(						const TCHAR *FileName, int PlayType ) ;														// サウンドファイルを再生する
extern	int			PlaySound(							const TCHAR *FileName, int PlayType ) ;														// PlaySoundFile の旧名称
extern	int			CheckSoundFile(						void ) ;																					// サウンドファイルの再生中かどうかを取得する
extern	int			CheckSound(							void ) ;																					// CheckSoundFile の旧名称
extern	int			StopSoundFile(						void ) ;																					// サウンドファイルの再生を停止する
extern	int			StopSound(							void ) ;																					// StopSoundFile の旧名称
extern	int			SetVolumeSoundFile(					int VolumePal ) ;																			// サウンドファイルの音量を設定する
extern	int			SetVolumeSound(						int VolumePal ) ;																			// SetVolumeSound の旧名称

// ソフトウエア制御サウンド系関数
extern	int			InitSoftSound(						void ) ;																					// ソフトウエアで扱う波形データハンドルをすべて削除する
extern	int			LoadSoftSound(						const TCHAR *FileName ) ;																	// ソフトウエアで扱う波形データハンドルをサウンドファイルから作成する
extern	int			LoadSoftSoundFromMemImage(			const void *FileImage, int FileImageSize ) ;												// ソフトウエアで扱う波形データハンドルをメモリ上に展開されたサウンドファイルイメージから作成する
extern	int			MakeSoftSound(						int UseFormat_SoftSoundHandle, int SampleNum ) ;											// ソフトウエアで扱う空の波形データハンドルを作成する( フォーマットは引数のソフトウエアサウンドハンドルと同じものにする )
extern	int			MakeSoftSound2Ch16Bit44KHz(			int SampleNum ) ;																			// ソフトウエアで扱う空の波形データハンドルを作成する( チャンネル数:2 量子化ビット数:16bit サンプリング周波数:44KHz )
extern	int			MakeSoftSound2Ch16Bit22KHz(			int SampleNum ) ;																			// ソフトウエアで扱う空の波形データハンドルを作成する( チャンネル数:2 量子化ビット数:16bit サンプリング周波数:22KHz )
extern	int			MakeSoftSound2Ch8Bit44KHz(			int SampleNum ) ;																			// ソフトウエアで扱う空の波形データハンドルを作成する( チャンネル数:2 量子化ビット数: 8bit サンプリング周波数:44KHz )
extern	int			MakeSoftSound2Ch8Bit22KHz(			int SampleNum ) ;																			// ソフトウエアで扱う空の波形データハンドルを作成する( チャンネル数:2 量子化ビット数: 8bit サンプリング周波数:22KHz )
extern	int			MakeSoftSound1Ch16Bit44KHz(			int SampleNum ) ;																			// ソフトウエアで扱う空の波形データハンドルを作成する( チャンネル数:1 量子化ビット数:16bit サンプリング周波数:44KHz )
extern	int			MakeSoftSound1Ch16Bit22KHz(			int SampleNum ) ;																			// ソフトウエアで扱う空の波形データハンドルを作成する( チャンネル数:1 量子化ビット数:16bit サンプリング周波数:22KHz )
extern	int			MakeSoftSound1Ch8Bit44KHz(			int SampleNum ) ;																			// ソフトウエアで扱う空の波形データハンドルを作成する( チャンネル数:1 量子化ビット数: 8bit サンプリング周波数:44KHz )
extern	int			MakeSoftSound1Ch8Bit22KHz(			int SampleNum ) ;																			// ソフトウエアで扱う空の波形データハンドルを作成する( チャンネル数:1 量子化ビット数: 8bit サンプリング周波数:22KHz )
extern	int			MakeSoftSoundCustom(				int ChannelNum, int BitsPerSample, int SamplesPerSec, int SampleNum );						// ソフトウエアで扱う空の波形データハンドルを作成する
extern	int			DeleteSoftSound(					int SoftSoundHandle ) ;																		// ソフトウエアで扱う波形データハンドルを削除する
#ifndef DX_NON_SAVEFUNCTION
extern	int			SaveSoftSound(						int SoftSoundHandle, const TCHAR *FileName ) ;												// ソフトウエアで扱う波形データハンドルをWAVEファイル(PCM)形式で保存する
#endif // DX_NON_SAVEFUNCTION
extern	int			GetSoftSoundSampleNum(				int SoftSoundHandle ) ;																		// ソフトウエアで扱う波形データハンドルのサンプル数を取得する
extern	int			GetSoftSoundFormat(					int SoftSoundHandle, int *Channels, int *BitsPerSample, int *SamplesPerSec ) ;				// ソフトウエアで扱う波形データハンドルのフォーマットを取得する
extern	int			ReadSoftSoundData(					int SoftSoundHandle, int SamplePosition, int *Channel1, int *Channel2 ) ;					// ソフトウエアで扱う波形データハンドルのサンプルを読み取る
extern	int			WriteSoftSoundData(					int SoftSoundHandle, int SamplePosition, int Channel1, int Channel2 ) ;						// ソフトウエアで扱う波形データハンドルのサンプルを書き込む
extern	void		*GetSoftSoundDataImage(				int SoftSoundHandle ) ;																		// ソフトウエアで扱う波形データハンドルの波形イメージが格納されているメモリアドレスを取得する

extern	int			InitSoftSoundPlayer(				void ) ;																					// ソフトウエアで扱う波形データのプレイヤーハンドルをすべて解放する
extern	int			MakeSoftSoundPlayer(				int UseFormat_SoftSoundHandle ) ;															// ソフトウエアで扱う波形データのプレイヤーハンドルを作成する( フォーマットは引数のソフトウエアサウンドハンドルと同じものにする )
extern	int			MakeSoftSoundPlayer2Ch16Bit44KHz(	void ) ;																					// ソフトウエアで扱う波形データのプレイヤーハンドルを作成する( チャンネル数:2 量子化ビット数:16bit サンプリング周波数:44KHz )
extern	int			MakeSoftSoundPlayer2Ch16Bit22KHz(	void ) ;																					// ソフトウエアで扱う波形データのプレイヤーハンドルを作成する( チャンネル数:2 量子化ビット数:16bit サンプリング周波数:22KHz )
extern	int			MakeSoftSoundPlayer2Ch8Bit44KHz(	void ) ;																					// ソフトウエアで扱う波形データのプレイヤーハンドルを作成する( チャンネル数:2 量子化ビット数: 8bit サンプリング周波数:44KHz )
extern	int			MakeSoftSoundPlayer2Ch8Bit22KHz(	void ) ;																					// ソフトウエアで扱う波形データのプレイヤーハンドルを作成する( チャンネル数:2 量子化ビット数: 8bit サンプリング周波数:22KHz )
extern	int			MakeSoftSoundPlayer1Ch16Bit44KHz(	void ) ;																					// ソフトウエアで扱う波形データのプレイヤーハンドルを作成する( チャンネル数:1 量子化ビット数:16bit サンプリング周波数:44KHz )
extern	int			MakeSoftSoundPlayer1Ch16Bit22KHz(	void ) ;																					// ソフトウエアで扱う波形データのプレイヤーハンドルを作成する( チャンネル数:1 量子化ビット数:16bit サンプリング周波数:22KHz )
extern	int			MakeSoftSoundPlayer1Ch8Bit44KHz(	void ) ;																					// ソフトウエアで扱う波形データのプレイヤーハンドルを作成する( チャンネル数:1 量子化ビット数: 8bit サンプリング周波数:44KHz )
extern	int			MakeSoftSoundPlayer1Ch8Bit22KHz(	void ) ;																					// ソフトウエアで扱う波形データのプレイヤーハンドルを作成する( チャンネル数:1 量子化ビット数: 8bit サンプリング周波数:22KHz )
extern	int			MakeSoftSoundPlayerCustom(			int ChannelNum, int BitsPerSample, int SamplesPerSec ) ;									// ソフトウエアで扱う波形データのプレイヤーハンドルを作成する
extern	int			DeleteSoftSoundPlayer(				int SSoundPlayerHandle ) ;																	// ソフトウエアで扱う波形データのプレイヤーハンドルを削除する
extern	int			AddDataSoftSoundPlayer(				int SSoundPlayerHandle, int SoftSoundHandle, int AddSamplePosition, int AddSampleNum ) ;	// ソフトウエアで扱う波形データのプレイヤーハンドルに波形データを追加する( フォーマットが同じではない場合はエラー )
extern	int			AddDirectDataSoftSoundPlayer(		int SSoundPlayerHandle, void *SoundData, int AddSampleNum ) ;								// ソフトウエアで扱う波形データのプレイヤーハンドルにプレイヤーが対応したフォーマットの生波形データを追加する
extern	int			AddOneDataSoftSoundPlayer(			int SSoundPlayerHandle, int Channel1, int Channel2 ) ;										// ソフトウエアで扱う波形データのプレイヤーハンドルに波形データを一つ追加する
extern	int			GetSoftSoundPlayerFormat(			int SSoundPlayerHandle, int *Channels, int *BitsPerSample, int *SamplesPerSec ) ;			// ソフトウエアで扱う波形データのプレイヤーハンドルが扱うデータフォーマットを取得する
extern	int			StartSoftSoundPlayer(				int SSoundPlayerHandle ) ;																	// ソフトウエアで扱う波形データのプレイヤーハンドルの再生処理を開始する
extern	int			CheckStartSoftSoundPlayer(			int SSoundPlayerHandle ) ;																	// ソフトウエアで扱う波形データのプレイヤーハンドルの再生処理が開始されているか取得する( TRUE:開始している  FALSE:停止している )
extern	int			StopSoftSoundPlayer(				int SSoundPlayerHandle ) ;																	// ソフトウエアで扱う波形データのプレイヤーハンドルの再生処理を停止する
extern	int			ResetSoftSoundPlayer(				int SSoundPlayerHandle ) ;																	// ソフトウエアで扱う波形データのプレイヤーハンドルの状態を初期状態に戻す( 追加された波形データは削除され、再生状態だった場合は停止する )
extern	int			GetStockDataLengthSoftSoundPlayer(	int SSoundPlayerHandle ) ;																	// ソフトウエアで扱う波形データのプレイヤーハンドルに追加した波形データでまだ再生用サウンドバッファに転送されていない波形データのサンプル数を取得する
extern	int			CheckSoftSoundPlayerNoneData(		int SSoundPlayerHandle ) ;																	// ソフトウエアで扱う波形データのプレイヤーハンドルに再生用サウンドバッファに転送していない波形データが無く、再生用サウンドバッファにも無音データ以外無いかどうかを取得する( TRUE:無音データ以外無い  FALSE:有効データがある )




// ＭＩＤＩ制御関数
extern	int			DeleteMusicMem(						int MusicHandle ) ;																			// ＭＩＤＩハンドルを削除する
extern	int			LoadMusicMem(						const TCHAR *FileName ) ;																	// ＭＩＤＩファイルを読み込みＭＩＤＩハンドルを作成する
extern	int			LoadMusicMemByMemImage(				void *FileImage, int FileImageSize ) ;														// メモリ上に展開されたＭＩＤＩファイルイメージからＭＩＤＩハンドルを作成する
extern	int			LoadMusicMemByResource(				const TCHAR *ResourceName, const TCHAR *ResourceType ) ;									// リソース上のＭＩＤＩファイルからＭＩＤＩハンドルを作成する
extern	int			PlayMusicMem(						int MusicHandle, int PlayType ) ;															// ＭＩＤＩハンドルの演奏を開始する
extern	int			StopMusicMem(						int MusicHandle ) ;																			// ＭＩＤＩハンドルの演奏を停止する
extern	int			CheckMusicMem(						int MusicHandle ) ;																			// ＭＩＤＩハンドルが演奏中かどうかを取得する( TRUE:演奏中  FALSE:停止中 )
extern	int			SetVolumeMusicMem(					int Volume, int MusicHandle ) ;																// ＭＩＤＩハンドルの再生音量をセットする
extern	int			GetMusicMemPosition(				int MusicHandle ) ;																			// ＭＩＤＩハンドルの現在の再生位置を取得する
extern	int			InitMusicMem(						void ) ;																					// ＭＩＤＩハンドルをすべて削除する
extern	int			ProcessMusicMem(					void ) ;																					// ＭＩＤＩハンドルの周期的処理( 内部で呼ばれます )

extern	int			PlayMusic(							const TCHAR *FileName, int PlayType ) ;														// ＭＩＤＩファイルを演奏する
extern	int			PlayMusicByMemImage(				void *FileImage, int FileImageSize, int PlayType ) ;										// メモリ上に展開されているＭＩＤＩファイルを演奏する
extern	int			PlayMusicByResource(				const TCHAR *ResourceName, const TCHAR *ResourceType, int PlayType ) ;						// リソースからＭＩＤＩファイルを読み込んで演奏する
extern	int			SetVolumeMusic(						int Volume ) ;																				// ＭＩＤＩの再生音量をセットする
extern	int			StopMusic(							void ) ;																					// ＭＩＤＩファイルの演奏停止
extern	int			CheckMusic(							void ) ;																					// ＭＩＤＩファイルが演奏中か否か情報を取得する
extern	int			GetMusicPosition(					void ) ;																					// ＭＩＤＩの現在の再生位置を取得する

extern	int			SelectMidiMode(						int Mode ) ;																				// ＭＩＤＩの再生形式を設定する

#endif // DX_NON_SOUND










// DxArchive_.cpp 関数 プロトタイプ宣言
extern	int			SetUseDXArchiveFlag(	int Flag ) ;													// ＤＸアーカイブファイルの読み込み機能を使うかどうかを設定する( FALSE:使用しない  TRUE:使用する )
extern	int			SetDXArchivePriority(	int Priority = 0 ) ;											// 同名のＤＸアーカイブファイルとフォルダが存在した場合、どちらを優先させるかを設定する( 1:フォルダを優先　 0:ＤＸアーカイブファイルを優先( デフォルト ) )
extern	int			SetDXArchiveExtension(	const TCHAR *Extension = NULL ) ;								// 検索するＤＸアーカイブファイルの拡張子を設定する( Extension:拡張子名文字列 )
extern	int			SetDXArchiveKeyString(	const TCHAR *KeyString = NULL ) ;								// ＤＸアーカイブファイルの鍵文字列を設定する( KeyString:鍵文字列 )

extern	int			DXArchivePreLoad(		const TCHAR *FilePath , int ASync = FALSE ) ;					// 指定のＤＸＡファイルを丸ごとメモリに読み込む( 戻り値  -1:エラー  0:成功 )
extern	int			DXArchiveCheckIdle(		const TCHAR *FilePath ) ;										// 指定のＤＸＡファイルの事前読み込みが完了したかどうかを取得する( 戻り値  TRUE:完了した FALSE:まだ )
extern	int			DXArchiveRelease(		const TCHAR *FilePath ) ;										// 指定のＤＸＡファイルをメモリから解放する
extern	int			DXArchiveCheckFile(		const TCHAR *FilePath, const TCHAR *TargetFilePath ) ;			// ＤＸＡファイルの中に指定のファイルが存在するかどうかを調べる、TargetFilePath はＤＸＡファイルをカレントフォルダとした場合のパス( 戻り値:  -1=エラー  0:無い  1:ある )





















// DxModel.cpp 関数 プロトタイプ宣言

#ifndef DX_NON_MODEL

// モデルの読み込み・複製関係
extern	int			MV1LoadModel(						const TCHAR *FileName ) ;											// モデルの読み込み( -1:エラー  0以上:モデルハンドル )
extern	int			MV1LoadModelFromMem(				void *FileImage, int FileSize, int (* FileReadFunc )( const TCHAR *FilePath, void **FileImageAddr, int *FileSize, void *FileReadFuncData ), int (* FileReleaseFunc )( void *MemoryAddr, void *FileReadFuncData ), void *FileReadFuncData = NULL ) ;	// メモリ上のモデルファイルイメージと独自の読み込みルーチンを使用してモデルを読み込む
extern	int			MV1DuplicateModel(					int SrcMHandle ) ;													// 指定のモデルと同じモデル基本データを使用してモデルを作成する( -1:エラー  0以上:モデルハンドル )
extern	int			MV1CreateCloneModel(				int SrcMHandle ) ;													// 指定のモデルをモデル基本データも含め複製する( MV1DuplicateModel はモデル基本データは共有しますが、こちらは複製元のモデルとは一切共有データの無いモデルハンドルを作成します )( -1:エラー  0以上:モデルハンドル )

extern	int			MV1DeleteModel(						int MHandle ) ;														// モデルを削除する
extern	int			MV1InitModel(						void ) ;															// すべてのモデルを削除する

extern	int			MV1SetLoadModelReMakeNormal(		int Flag ) ;														// モデルを読み込む際に法線の再計算を行うかどうかを設定する( TRUE:行う  FALSE:行わない )
extern	int			MV1SetLoadModelReMakeNormalSmoothingAngle( float SmoothingAngle = 1.562069f ) ;							// モデルを読み込む際に行う法泉の再計算で使用するスムージング角度を設定する( 単位はラジアン )
extern	int			MV1SetLoadModelPositionOptimize(	int Flag ) ;														// モデルを読み込む際に座標データの最適化を行うかどうかを設定する( TRUE:行う  FALSE:行わない )
extern	int			MV1SetLoadModelUsePhysicsMode(		int PhysicsMode /* DX_LOADMODEL_PHYSICS_LOADCALC 等 */ ) ;			// 読み込むモデルの物理演算モードを設定する
extern	int			MV1SetLoadModelPhysicsWorldGravity( float Gravity ) ;													// 読み込むモデルの物理演算に適用する重力パラメータを設定する
extern	int			MV1SetLoadCalcPhysicsWorldGravity(	int GravityNo, VECTOR Gravity ) ;									// 読み込むモデルの物理演算モードが事前計算( DX_LOADMODEL_PHYSICS_LOADCALC )だった場合に適用される重力の設定をする
extern	int			MV1SetLoadModelAnimFilePath(		const TCHAR *FileName ) ;											// 読み込むモデルに適用するアニメーションファイルのパスを設定する、NULLを渡すと設定リセット( 現在は PMD,PMX のみに効果あり )

// モデル保存関係
extern	int			MV1SaveModelToMV1File( int MHandle, const TCHAR *FileName, int SaveType = MV1_SAVETYPE_NORMAL , int AnimMHandle = -1 , int AnimNameCheck = TRUE , int Normal8BitFlag = 1 , int Position16BitFlag = 1 , int Weight8BitFlag = 0 , int Anim16BitFlag = 1 ) ;		// 指定のパスにモデルを保存する( 戻り値  0:成功  -1:メモリ不足  -2:使われていないアニメーションがあった )
#ifndef DX_NON_SAVEFUNCTION
extern	int			MV1SaveModelToXFile(   int MHandle, const TCHAR *FileName, int SaveType = MV1_SAVETYPE_NORMAL , int AnimMHandle = -1 , int AnimNameCheck = TRUE ) ;	// 指定のパスにモデルをＸファイル形式で保存する( 戻り値  0:成功  -1:メモリ不足  -2:使われていないアニメーションがあった )
#endif // DX_NON_SAVEFUNCTION

// モデル描画関係
extern	int			MV1DrawModel(						int MHandle ) ;														// モデルを描画する
extern	int			MV1DrawFrame(						int MHandle, int FrameIndex ) ;										// モデルの指定のフレームを描画する
extern	int			MV1DrawMesh(						int MHandle, int MeshIndex ) ;										// モデルの指定のメッシュを描画する
extern	int			MV1DrawTriangleList(				int MHandle, int TriangleListIndex ) ;								// モデルの指定のトライアングルリストを描画する
extern	int			MV1DrawModelDebug(					int MHandle, int Color, int IsNormalLine, float NormalLineLength, int IsPolyLine, int IsCollisionBox ) ;	// モデルのデバッグ描画

// 描画設定関係
extern	int			MV1SetUseOrigShader(				int UseFlag ) ;														// モデルの描画に SetUseVertexShader, SetUsePixelShader で指定したシェーダーを使用するかどうかを設定する( TRUE:使用する  FALSE:使用しない( デフォルト ) )

// モデル基本制御関係
extern	MATRIX		MV1GetLocalWorldMatrix(				int MHandle ) ;														// モデルのローカル座標からワールド座標に変換する行列を得る
extern	int			MV1SetPosition(						int MHandle, VECTOR Position ) ;									// モデルの座標をセット
extern	VECTOR		MV1GetPosition(						int MHandle ) ;														// モデルの座標を取得
extern	int			MV1SetScale(						int MHandle, VECTOR Scale ) ;										// モデルの拡大値をセット
extern	VECTOR		MV1GetScale(						int MHandle ) ;														// モデルの拡大値を取得
extern	int			MV1SetRotationXYZ(					int MHandle, VECTOR Rotate ) ;										// モデルの回転値をセット( X軸回転→Y軸回転→Z軸回転方式 )
extern	VECTOR		MV1GetRotationXYZ(					int MHandle ) ;														// モデルの回転値を取得( X軸回転→Y軸回転→Z軸回転方式 )
extern	int			MV1SetRotationZYAxis(				int MHandle, VECTOR ZAxisDirection, VECTOR YAxisDirection, float ZAxisTwistRotate ) ;	// モデルのＺ軸とＹ軸の向きをセットする
extern	int			MV1SetRotationMatrix(				int MHandle, MATRIX Matrix ) ;										// モデルの回転用行列をセットする
extern	MATRIX		MV1GetRotationMatrix(				int MHandle ) ;														// モデルの回転用行列を取得する
extern	int			MV1SetMatrix(						int MHandle, MATRIX Matrix ) ;										// モデルの変形用行列をセットする
extern	MATRIX		MV1GetMatrix(						int MHandle ) ;														// モデルの変形用行列を取得する
extern	int			MV1SetVisible(						int MHandle, int VisibleFlag ) ;									// モデルの表示、非表示状態を変更する( TRUE:表示  FALSE:非表示 )
extern	int			MV1GetVisible(						int MHandle ) ;														// モデルの表示、非表示状態を取得する( TRUE:表示  FALSE:非表示 )
extern	int			MV1SetMeshCategoryVisible(			int MHandle, int MeshCategory, int VisibleFlag ) ;					// モデルのメッシュの種類( DX_MV1_MESHCATEGORY_NORMAL など )毎の表示、非表示を設定する( TRUE:表示  FALSE:非表示 )
extern	int			MV1GetMeshCategoryVisible(			int MHandle, int MeshCategory ) ;									// モデルのメッシュの種類( DX_MV1_MESHCATEGORY_NORMAL など )毎の表示、非表示を取得する( TRUE:表示  FALSE:非表示 )
extern	int			MV1SetDifColorScale(				int MHandle, COLOR_F Scale ) ;										// モデルのディフューズカラーのスケール値を設定する( デフォルト値は 1.0f )
extern	COLOR_F		MV1GetDifColorScale(				int MHandle ) ;														// モデルのディフューズカラーのスケール値を取得する( デフォルト値は 1.0f )
extern	int			MV1SetSpcColorScale(				int MHandle, COLOR_F Scale ) ;										// モデルのスペキュラカラーのスケール値を設定する( デフォルト値は 1.0f )
extern	COLOR_F		MV1GetSpcColorScale(				int MHandle ) ;														// モデルのスペキュラカラーのスケール値を取得する( デフォルト値は 1.0f )
extern	int			MV1SetEmiColorScale(				int MHandle, COLOR_F Scale ) ;										// モデルのエミッシブカラーのスケール値を設定する( デフォルト値は 1.0f )
extern	COLOR_F		MV1GetEmiColorScale(				int MHandle ) ;														// モデルのエミッシブカラーのスケール値を取得する( デフォルト値は 1.0f )
extern	int			MV1SetAmbColorScale(				int MHandle, COLOR_F Scale ) ;										// モデルのアンビエントカラーのスケール値を設定する( デフォルト値は 1.0f )
extern	COLOR_F		MV1GetAmbColorScale(				int MHandle ) ;														// モデルのアンビエントカラーのスケール値を取得する( デフォルト値は 1.0f )
extern	int			MV1GetSemiTransState(				int MHandle ) ;														// モデルに半透明要素があるかどうかを取得する( 戻り値 TRUE:ある  FALSE:ない )
extern	int			MV1SetOpacityRate(					int MHandle, float Rate ) ;											// モデルの不透明度を設定する( 不透明 1.0f 〜 透明 0.0f )
extern	float		MV1GetOpacityRate(					int MHandle ) ;														// モデルの不透明度を取得する( 不透明 1.0f 〜 透明 0.0f )
extern	int			MV1SetUseZBuffer(					int MHandle, int Flag ) ;											// モデルを描画する際にＺバッファを使用するかどうかを設定する
extern	int			MV1SetWriteZBuffer(					int MHandle, int Flag ) ;											// モデルを描画する際にＺバッファに書き込みを行うかどうかを設定する
extern	int			MV1SetZBufferCmpType(				int MHandle, int CmpType /* DX_CMP_NEVER 等 */ ) ;					// モデルの描画時のＺ値の比較モードを設定する
extern	int			MV1SetZBias(						int MHandle, int Bias ) ;											// モデルの描画時の書き込むＺ値のバイアスを設定する
extern	int			MV1SetUseVertDifColor(				int MHandle, int UseFlag ) ;										// モデルの含まれるメッシュの頂点ディフューズカラーをマテリアルのディフューズカラーの代わりに使用するかどうかを設定する( TRUE:マテリアルカラーの代わりに使用する  FALSE:マテリアルカラーを使用する )
extern	int			MV1SetUseVertSpcColor(				int MHandle, int UseFlag ) ;										// モデルに含まれるメッシュの頂点スペキュラカラーをマテリアルのスペキュラカラーの代わりに使用するかどうかを設定する( TRUE:マテリアルカラーの代わりに使用する  FALSE:マテリアルカラーを使用する )
extern	int			MV1SetSampleFilterMode(				int MHandle, int FilterMode ) ;										// モデルのテクスチャのサンプルフィルターモードを変更する( FilterMode は DX_DRAWMODE_NEAREST 等 )
extern	int			MV1SetMaxAnisotropy(				int MHandle, int MaxAnisotropy ) ;									// モデルの異方性フィルタリングの最大次数を設定する
extern	int			MV1SetWireFrameDrawFlag(			int MHandle, int Flag ) ;											// モデルをワイヤーフレームで描画するかどうかを設定する
extern	int			MV1RefreshVertColorFromMaterial(	int MHandle ) ;														// モデルの頂点カラーを現在設定されているマテリアルのカラーにする
extern	int			MV1SetPhysicsWorldGravity(			int MHandle, VECTOR Gravity ) ;										// モデルの物理演算の重力を設定する
extern	int			MV1PhysicsCalculation(				int MHandle, float MillisecondTime ) ;								// モデルの物理演算を指定時間分経過したと仮定して計算する( MillisecondTime で指定する時間の単位はミリ秒 )
extern	int			MV1PhysicsResetState(				int MHandle ) ;														// モデルの物理演算の状態をリセットする( 位置がワープしたとき用 )
extern	int			MV1SetUseShapeFlag(					int MHandle, int UseFlag ) ;										// モデルのシェイプ機能を使用するかどうかを設定する( UseFlag  TRUE:使用する( デフォルト )  FALSE:使用しない )
extern	int			MV1GetMaterialNumberOrderFlag(		int MHandle ) ;														// モデルのマテリアル番号順にメッシュを描画するかどうかのフラグを取得する( TRUE:マテリアル番号順に描画  FALSE:不透明メッシュの後半透明メッシュ )

// アニメーション関係
extern	int			MV1AttachAnim(						int MHandle, int AnimIndex, int AnimSrcMHandle = -1 , int NameCheck = TRUE ) ;		// アニメーションをアタッチする( 戻り値  -1:エラー  0以上:アタッチインデックス )
extern	int			MV1DetachAnim(						int MHandle, int AttachIndex ) ;													// アニメーションをデタッチする
extern	int			MV1SetAttachAnimTime(				int MHandle, int AttachIndex, float Time ) ;										// アタッチしているアニメーションの再生時間を設定する
extern	float		MV1GetAttachAnimTime(				int MHandle, int AttachIndex ) ;													// アタッチしているアニメーションの再生時間を取得する
extern	float		MV1GetAttachAnimTotalTime(			int MHandle, int AttachIndex ) ;													// アタッチしているアニメーションの総時間を得る
extern	int			MV1SetAttachAnimBlendRate(			int MHandle, int AttachIndex, float Rate = 1.0f ) ;									// アタッチしているアニメーションのブレンド率を設定する
extern	float		MV1GetAttachAnimBlendRate(			int MHandle, int AttachIndex ) ;													// アタッチしているアニメーションのブレンド率を取得する
extern	int			MV1SetAttachAnimBlendRateToFrame(	int MHandle, int AttachIndex, int FrameIndex, float Rate, int SetChild = TRUE ) ;	// アタッチしているアニメーションのブレンド率を設定する( フレーム単位 )
extern	float		MV1GetAttachAnimBlendRateToFrame(	int MHandle, int AttachIndex, int FrameIndex ) ;									// アタッチしているアニメーションのブレンド率を設定する( フレーム単位 )
extern	int			MV1GetAttachAnim(					int MHandle, int AttachIndex ) ;													// アタッチしているアニメーションのアニメーションインデックスを取得する
extern	int			MV1SetAttachAnimUseShapeFlag(		int MHandle, int AttachIndex, int UseFlag ) ;										// アタッチしているアニメーションのシェイプを使用するかどうかを設定する( UseFlag  TRUE:使用する( デフォルト )  FALSE:使用しない )
extern	int			MV1GetAttachAnimUseShapeFlag(		int MHandle, int AttachIndex ) ;													// アタッチしているアニメーションのシェイプを使用するかどうかを取得する
extern	VECTOR		MV1GetAttachAnimFrameLocalPosition(	int MHandle, int AttachIndex, int FrameIndex ) ;									// アタッチしているアニメーションの指定のフレームの現在のローカル座標を取得する
extern	MATRIX		MV1GetAttachAnimFrameLocalMatrix(	int MHandle, int AttachIndex, int FrameIndex ) ;									// アタッチしているアニメーションの指定のフレームの現在のローカル変換行列を取得する

extern	int			MV1GetAnimNum(						int MHandle ) ;																		// アニメーションの数を取得する
extern	const TCHAR *MV1GetAnimName(					int MHandle, int AnimIndex ) ;														// 指定番号のアニメーション名を取得する( NULL:エラー )
extern	int			MV1SetAnimName(						int MHandle, int AnimIndex, const TCHAR *AnimName ) ;								// 指定番号のアニメーション名を変更する
extern	int			MV1GetAnimIndex(					int MHandle, const TCHAR *AnimName ) ;												// 指定名のアニメーション番号を取得する( -1:エラー )
extern	float		MV1GetAnimTotalTime(				int MHandle, int AnimIndex ) ;														// 指定番号のアニメーションの総時間を得る
extern	int			MV1GetAnimTargetFrameNum(			int MHandle, int AnimIndex ) ;														// 指定のアニメーションがターゲットとするフレームの数を取得する
extern	const TCHAR *MV1GetAnimTargetFrameName(			int MHandle, int AnimIndex, int AnimFrameIndex ) ;									// 指定のアニメーションがターゲットとするフレームの名前を取得する
extern	int			MV1GetAnimTargetFrame(				int MHandle, int AnimIndex, int AnimFrameIndex ) ;									// 指定のアニメーションがターゲットとするフレームの番号を取得する
extern	int			MV1GetAnimTargetFrameKeySetNum(		int MHandle, int AnimIndex, int AnimFrameIndex ) ;									// 指定のアニメーションがターゲットとするフレーム用のアニメーションキーセットの数を取得する
extern	int			MV1GetAnimTargetFrameKeySet(		int MHandle, int AnimIndex, int AnimFrameIndex, int Index ) ;						// 指定のアニメーションがターゲットとするフレーム用のアニメーションキーセットキーセットインデックスを取得する

extern	int			MV1GetAnimKeySetNum(				int MHandle ) ;																		// モデルに含まれるアニメーションキーセットの総数を得る
extern	int			MV1GetAnimKeySetType(				int MHandle, int AnimKeySetIndex ) ;												// 指定のアニメーションキーセットのタイプを取得する( MV1_ANIMKEY_TYPE_QUATERNION 等 )
extern	int			MV1GetAnimKeySetDataType(			int MHandle, int AnimKeySetIndex ) ;												// 指定のアニメーションキーセットのデータタイプを取得する( MV1_ANIMKEY_DATATYPE_ROTATE 等 )
extern	int			MV1GetAnimKeySetTimeType(			int MHandle, int AnimKeySetIndex ) ;												// 指定のアニメーションキーセットのキーの時間データタイプを取得する( MV1_ANIMKEY_TIME_TYPE_ONE 等 )
extern	int			MV1GetAnimKeySetDataNum(			int MHandle, int AnimKeySetIndex ) ;												// 指定のアニメーションキーセットのキーの数を取得する
extern	float		MV1GetAnimKeyDataTime(				int MHandle, int AnimKeySetIndex, int Index ) ;										// 指定のアニメーションキーセットのキーの時間を取得する
extern	FLOAT4		MV1GetAnimKeyDataToQuaternion(		int MHandle, int AnimKeySetIndex, int Index ) ;										// 指定のアニメーションキーセットのキーを取得する、キータイプが MV1_ANIMKEY_TYPE_QUATERNION では無かった場合は失敗する
extern	FLOAT4		MV1GetAnimKeyDataToQuaternionFromTime( int MHandle, int AnimKeySetIndex, float Time ) ;									// 指定のアニメーションキーセットのキーを取得する、キータイプが MV1_ANIMKEY_TYPE_QUATERNION では無かった場合は失敗する( 時間指定版 )
extern	VECTOR		MV1GetAnimKeyDataToVector(			int MHandle, int AnimKeySetIndex, int Index ) ;										// 指定のアニメーションキーセットのキーを取得する、キータイプが MV1_ANIMKEY_TYPE_VECTOR では無かった場合は失敗する
extern	VECTOR		MV1GetAnimKeyDataToVectorFromTime(	int MHandle, int AnimKeySetIndex, float Time ) ;									// 指定のアニメーションキーセットのキーを取得する、キータイプが MV1_ANIMKEY_TYPE_VECTOR では無かった場合は失敗する( 時間指定版 )
extern	MATRIX		MV1GetAnimKeyDataToMatrix(			int MHandle, int AnimKeySetIndex, int Index ) ;										// 指定のアニメーションキーセットのキーを取得する、キータイプが MV1_ANIMKEY_TYPE_MATRIX4X4C か MV1_ANIMKEY_TYPE_MATRIX3X3 では無かった場合は失敗する
extern	MATRIX		MV1GetAnimKeyDataToMatrixFromTime(	int MHandle, int AnimKeySetIndex, float Time ) ;									// 指定のアニメーションキーセットのキーを取得する、キータイプが MV1_ANIMKEY_TYPE_MATRIX4X4C か MV1_ANIMKEY_TYPE_MATRIX3X3 では無かった場合は失敗する( 時間指定版 )
extern	float		MV1GetAnimKeyDataToFlat(			int MHandle, int AnimKeySetIndex, int Index ) ;										// 指定のアニメーションキーセットのキーを取得する、キータイプが MV1_ANIMKEY_TYPE_FLAT では無かった場合は失敗する
extern	float		MV1GetAnimKeyDataToFlatFromTime(	int MHandle, int AnimKeySetIndex, float Time ) ;									// 指定のアニメーションキーセットのキーを取得する、キータイプが MV1_ANIMKEY_TYPE_FLAT では無かった場合は失敗する( 時間指定版 )
extern	float		MV1GetAnimKeyDataToLinear(			int MHandle, int AnimKeySetIndex, int Index ) ;										// 指定のアニメーションキーセットのキーを取得する、キータイプが MV1_ANIMKEY_TYPE_LINEAR では無かった場合は失敗する
extern	float		MV1GetAnimKeyDataToLinearFromTime(	int MHandle, int AnimKeySetIndex, float Time ) ;									// 指定のアニメーションキーセットのキーを取得する、キータイプが MV1_ANIMKEY_TYPE_LINEAR では無かった場合は失敗する( 時間指定版 )

// マテリアル関係
extern	int			MV1GetMaterialNum(					int MHandle ) ;															// モデルで使用しているマテリアルの数を取得する
extern	const TCHAR *MV1GetMaterialName(				int MHandle, int MaterialIndex ) ;										// 指定のマテリアルの名前を取得する
extern	int			MV1SetMaterialType(					int MHandle, int MaterialIndex, int Type ) ;							// 指定のマテリアルのタイプを変更する( Type : DX_MATERIAL_TYPE_NORMAL など )
extern	int			MV1GetMaterialType(					int MHandle, int MaterialIndex ) ;										// 指定のマテリアルのタイプを取得する( 戻り値 : DX_MATERIAL_TYPE_NORMAL など )
extern	int			MV1SetMaterialDifColor(				int MHandle, int MaterialIndex, COLOR_F Color ) ;						// 指定のマテリアルのディフューズカラーを設定する
extern	COLOR_F		MV1GetMaterialDifColor( 			int MHandle, int MaterialIndex ) ;										// 指定のマテリアルのディフューズカラーを取得する
extern	int			MV1SetMaterialSpcColor( 			int MHandle, int MaterialIndex, COLOR_F Color ) ;						// 指定のマテリアルのスペキュラカラーを設定する
extern	COLOR_F		MV1GetMaterialSpcColor( 			int MHandle, int MaterialIndex ) ;										// 指定のマテリアルのスペキュラカラーを取得する
extern	int			MV1SetMaterialEmiColor( 			int MHandle, int MaterialIndex, COLOR_F Color ) ;						// 指定のマテリアルのエミッシブカラーを設定する
extern	COLOR_F		MV1GetMaterialEmiColor( 			int MHandle, int MaterialIndex ) ;										// 指定のマテリアルのエミッシブカラーを取得する
extern	int			MV1SetMaterialAmbColor( 			int MHandle, int MaterialIndex, COLOR_F Color ) ;						// 指定のマテリアルのアンビエントカラーを設定する
extern	COLOR_F		MV1GetMaterialAmbColor( 			int MHandle, int MaterialIndex ) ;										// 指定のマテリアルのアンビエントカラーを取得する
extern	int			MV1SetMaterialSpcPower( 			int MHandle, int MaterialIndex, float Power ) ;							// 指定のマテリアルのスペキュラの強さを設定する
extern	float		MV1GetMaterialSpcPower( 			int MHandle, int MaterialIndex ) ;										// 指定のマテリアルのスペキュラの強さを取得する
extern	int			MV1SetMaterialDifMapTexture(		int MHandle, int MaterialIndex, int TexIndex ) ;						// 指定のマテリアルでディフューズマップとして使用するテクスチャを指定する
extern	int			MV1GetMaterialDifMapTexture(		int MHandle, int MaterialIndex ) ;										// 指定のマテリアルでディフューズマップとして使用されているテクスチャのインデックスを取得する
extern	int			MV1SetMaterialSpcMapTexture(		int MHandle, int MaterialIndex, int TexIndex ) ;						// 指定のマテリアルでスペキュラマップとして使用するテクスチャを指定する
extern	int			MV1GetMaterialSpcMapTexture(		int MHandle, int MaterialIndex ) ;										// 指定のマテリアルでスペキュラマップとして使用されているテクスチャのインデックスを取得する
extern	int			MV1GetMaterialNormalMapTexture(		int MHandle, int MaterialIndex ) ;										// 指定のマテリアルで法線マップとして使用されているテクスチャのインデックスを取得する
extern	int			MV1SetMaterialDifGradTexture(		int MHandle, int MaterialIndex, int TexIndex ) ;						// 指定のマテリアルでトゥーンレンダリングのディフューズグラデーションマップとして使用するテクスチャを設定する
extern	int			MV1GetMaterialDifGradTexture(		int MHandle, int MaterialIndex ) ;										// 指定のマテリアルでトゥーンレンダリングのディフューズグラデーションマップとして使用するテクスチャを取得する
extern	int			MV1SetMaterialSpcGradTexture(		int MHandle, int MaterialIndex, int TexIndex ) ;						// 指定のマテリアルでトゥーンレンダリングのスペキュラグラデーションマップとして使用するテクスチャを設定する
extern	int			MV1GetMaterialSpcGradTexture(		int MHandle, int MaterialIndex ) ;										// 指定のマテリアルでトゥーンレンダリングのスペキュラグラデーションマップとして使用するテクスチャを取得する
extern	int			MV1SetMaterialSphereMapTexture(		int MHandle, int MaterialIndex, int TexIndex ) ;						// 指定のマテリアルでトゥーンレンダリングのスフィアマップとして使用するテクスチャを設定する
extern	int			MV1GetMaterialSphereMapTexture(		int MHandle, int MaterialIndex ) ;										// 指定のマテリアルでトゥーンレンダリングのスフィアマップとして使用するテクスチャを取得する
extern	int			MV1SetMaterialDifGradBlendType(		int MHandle, int MaterialIndex, int BlendType ) ;						// 指定のマテリアルのトゥーンレンダリングで使用するディフューズグラデーションマップとディフューズカラーの合成方法を設定する( DX_MATERIAL_BLENDTYPE_ADDITIVE など )
extern	int			MV1GetMaterialDifGradBlendType(		int MHandle, int MaterialIndex ) ;										// 指定のマテリアルのトゥーンレンダリングで使用するディフューズグラデーションマップとディフューズカラーの合成方法を取得する( DX_MATERIAL_BLENDTYPE_ADDITIVE など )
extern	int			MV1SetMaterialSpcGradBlendType(		int MHandle, int MaterialIndex, int BlendType ) ;						// 指定のマテリアルのトゥーンレンダリングで使用するスペキュラグラデーションマップとスペキュラカラーの合成方法を設定する( DX_MATERIAL_BLENDTYPE_ADDITIVE など )
extern	int			MV1GetMaterialSpcGradBlendType(		int MHandle, int MaterialIndex ) ;										// 指定のマテリアルのトゥーンレンダリングで使用するスペキュラグラデーションマップとスペキュラカラーの合成方法を取得する( DX_MATERIAL_BLENDTYPE_ADDITIVE など )
extern	int			MV1SetMaterialSphereMapBlendType(	int MHandle, int MaterialIndex, int BlendType ) ;						// 指定のマテリアルのトゥーンレンダリングで使用するスフィアマップの合成方法を設定する( DX_MATERIAL_BLENDTYPE_ADDITIVE など )
extern	int			MV1GetMaterialSphereMapBlendType(	int MHandle, int MaterialIndex ) ;										// 指定のマテリアルのトゥーンレンダリングで使用するスフィアマップの合成方法を取得する( DX_MATERIAL_BLENDTYPE_ADDITIVE など )
extern	int			MV1SetMaterialOutLineWidth(			int MHandle, int MaterialIndex, float Width ) ;							// 指定のマテリアルのトゥーンレンダリングで使用する輪郭線の太さを設定する
extern	float		MV1GetMaterialOutLineWidth(			int MHandle, int MaterialIndex ) ;										// 指定のマテリアルのトゥーンレンダリングで使用する輪郭線の太さを取得する
extern	int			MV1SetMaterialOutLineDotWidth(		int MHandle, int MaterialIndex, float Width ) ;							// 指定のマテリアルのトゥーンレンダリングで使用する輪郭線のドット単位の太さを設定する
extern	float		MV1GetMaterialOutLineDotWidth(		int MHandle, int MaterialIndex ) ;										// 指定のマテリアルのトゥーンレンダリングで使用する輪郭線のドット単位の太さを取得する
extern	int			MV1SetMaterialOutLineColor(			int MHandle, int MaterialIndex, COLOR_F Color ) ;						// 指定のマテリアルのトゥーンレンダリングで使用する輪郭線の色を設定する
extern	COLOR_F		MV1GetMaterialOutLineColor(			int MHandle, int MaterialIndex ) ;										// 指定のマテリアルのトゥーンレンダリングで使用する輪郭線の色を取得する
extern	int			MV1SetMaterialDrawBlendMode(		int MHandle, int MaterialIndex, int BlendMode ) ;						// 指定のマテリアルの描画ブレンドモードを設定する( DX_BLENDMODE_ALPHA 等 )
extern	int			MV1GetMaterialDrawBlendMode(		int MHandle, int MaterialIndex ) ;										// 指定のマテリアルの描画ブレンドモードを取得する( DX_BLENDMODE_ALPHA 等 )
extern	int			MV1SetMaterialDrawBlendParam(		int MHandle, int MaterialIndex, int BlendParam ) ;						// 指定のマテリアルの描画ブレンドパラメータを設定する
extern	int			MV1GetMaterialDrawBlendParam(		int MHandle, int MaterialIndex ) ;										// 指定のマテリアルの描画ブレンドパラメータを設定する
extern	int			MV1SetMaterialDrawAlphaTest(		int MHandle, int MaterialIndex,	int Enable, int Mode, int Param ) ;		// 指定のマテリアルの描画時のアルファテストの設定を行う( Enable:αテストを行うかどうか( TRUE:行う  FALSE:行わない( デフォルト )  Mode:テストモード( DX_CMP_GREATER等 )  Param:描画アルファ値との比較に使用する値( 0〜255 ) )
extern	int			MV1GetMaterialDrawAlphaTestEnable(	int MHandle, int MaterialIndex ) ;										// 指定のマテリアルの描画時のアルファテストを行うかどうかを取得する( 戻り値  TRUE:アルファテストを行う  FALSE:アルファテストを行わない )
extern	int			MV1GetMaterialDrawAlphaTestMode(	int MHandle, int MaterialIndex ) ;										// 指定のマテリアルの描画時のアルファテストのテストモードを取得する( 戻り値  テストモード( DX_CMP_GREATER等 ) )
extern	int			MV1GetMaterialDrawAlphaTestParam(	int MHandle, int MaterialIndex ) ;										// 指定のマテリアルの描画時のアルファテストの描画アルファ地との比較に使用する値( 0〜255 )を取得する

// テクスチャ関係
extern	int			MV1GetTextureNum(					int MHandle ) ;													// テクスチャの数を取得
extern	const TCHAR *MV1GetTextureName(					int MHandle, int TexIndex ) ;									// テクスチャの名前を取得
extern	int			MV1SetTextureColorFilePath(			int MHandle, int TexIndex, const TCHAR *FilePath ) ;			// カラーテクスチャのファイルパスを変更する
extern	const TCHAR *MV1GetTextureColorFilePath(		int MHandle, int TexIndex ) ;									// カラーテクスチャのファイルパスを取得
extern	int			MV1SetTextureAlphaFilePath(			int MHandle, int TexIndex, const TCHAR *FilePath ) ;			// アルファテクスチャのファイルパスを変更する
extern	const TCHAR *MV1GetTextureAlphaFilePath(		int MHandle, int TexIndex ) ;									// アルファテクスチャのファイルパスを取得
extern	int			MV1SetTextureGraphHandle(			int MHandle, int TexIndex, int GrHandle, int SemiTransFlag ) ;	// テクスチャで使用するグラフィックハンドルを変更する( GrHandle を -1 にすると解除 )
extern	int			MV1GetTextureGraphHandle(			int MHandle, int TexIndex ) ;									// テクスチャのグラフィックハンドルを取得する
extern	int			MV1SetTextureAddressMode(			int MHandle, int TexIndex, int AddrUMode, int AddrVMode ) ;		// テクスチャのアドレスモードを設定する( AddUMode の値は DX_TEXADDRESS_WRAP 等 )
extern	int			MV1GetTextureAddressModeU(			int MHandle, int TexIndex ) ;									// テクスチャのＵ値のアドレスモードを取得する( 戻り値:DX_TEXADDRESS_WRAP 等 )
extern	int			MV1GetTextureAddressModeV(			int MHandle, int TexIndex ) ;									// テクスチャのＶ値のアドレスモードを取得する( 戻り値:DX_TEXADDRESS_WRAP 等 )
extern	int			MV1GetTextureWidth(					int MHandle, int TexIndex ) ;									// テクスチャの幅を取得する
extern	int			MV1GetTextureHeight(				int MHandle, int TexIndex ) ;									// テクスチャの高さを取得する
extern	int			MV1GetTextureSemiTransState(		int MHandle, int TexIndex ) ;									// テクスチャに半透明要素があるかどうかを取得する( 戻り値  TRUE:ある  FALSE:ない )
extern	int			MV1SetTextureBumpImageFlag(			int MHandle, int TexIndex, int Flag ) ;							// テクスチャで使用している画像がバンプマップかどうかを設定する
extern	int			MV1GetTextureBumpImageFlag(			int MHandle, int TexIndex ) ;									// テクスチャがバンプマップかどうかを取得する( 戻り値  TRUE:バンプマップ  FALSE:違う )
extern	int			MV1SetTextureBumpImageNextPixelLength( int MHandle, int TexIndex, float Length ) ;					// バンプマップ画像の場合の隣のピクセルとの距離を設定する
extern	float		MV1GetTextureBumpImageNextPixelLength( int MHandle, int TexIndex ) ;								// バンプマップ画像の場合の隣のピクセルとの距離を取得する
extern	int			MV1SetTextureSampleFilterMode(		int MHandle, int TexIndex, int FilterMode ) ;					// テクスチャのフィルタリングモードを設定する
extern	int			MV1GetTextureSampleFilterMode(		int MHandle, int TexIndex ) ;									// テクスチャのフィルタリングモードを取得する( 戻り値  DX_DRAWMODE_BILINEAR等 )
extern	int			MV1LoadTexture(						const TCHAR *FilePath ) ;										// ３Ｄモデルに貼り付けるのに向いた画像の読み込み方式で画像を読み込む( 戻り値  -1:エラー  0以上:グラフィックハンドル )

// フレーム関係
extern	int			MV1GetFrameNum(						int MHandle ) ;															// フレームの数を取得する
extern	int			MV1SearchFrame(						int MHandle, const TCHAR *FrameName ) ;									// フレームの名前からモデル中のフレームのフレームインデックスを取得する( 無かった場合は戻り値が-1 )
extern	int			MV1SearchFrameChild(				int MHandle, int FrameIndex = -1 , const TCHAR *ChildName = NULL ) ;	// フレームの名前から指定のフレームの子フレームのフレームインデックスを取得する( 名前指定版 )( FrameIndex を -1 にすると親を持たないフレームを ChildIndex で指定する )( 無かった場合は戻り値が-1 )
extern	const TCHAR *MV1GetFrameName(					int MHandle, int FrameIndex ) ;											// 指定のフレームの名前を取得する( エラーの場合は戻り値が NULL )
extern	int			MV1GetFrameParent(					int MHandle, int FrameIndex ) ;											// 指定のフレームの親フレームのインデックスを得る( 親がいない場合は -2 が返る )
extern	int			MV1GetFrameChildNum(				int MHandle, int FrameIndex = -1 ) ;									// 指定のフレームの子フレームの数を取得する( FrameIndex を -1 にすると親を持たないフレームの数が返ってくる )
extern	int			MV1GetFrameChild(					int MHandle, int FrameIndex = -1 , int ChildIndex = 0 ) ;				// 指定のフレームの子フレームのフレームインデックスを取得する( 番号指定版 )( FrameIndex を -1 にすると親を持たないフレームを ChildIndex で指定する )( エラーの場合は戻り値が-1 )
extern	VECTOR		MV1GetFramePosition(				int MHandle, int FrameIndex ) ;											// 指定のフレームの座標を取得する
extern	MATRIX		MV1GetFrameBaseLocalMatrix(			int MHandle, int FrameIndex ) ;											// 指定のフレームの初期状態での座標変換行列を取得する
extern	MATRIX		MV1GetFrameLocalMatrix(				int MHandle, int FrameIndex ) ;											// 指定のフレームの座標変換行列を取得する
extern	MATRIX		MV1GetFrameLocalWorldMatrix(		int MHandle, int FrameIndex ) ;											// 指定のフレームのローカル座標からワールド座標に変換する行列を得る
extern	int			MV1SetFrameUserLocalMatrix(			int MHandle, int FrameIndex, MATRIX Matrix ) ;							// 指定のフレームの座標変換行列を設定する
extern	int			MV1ResetFrameUserLocalMatrix(		int MHandle, int FrameIndex ) ;											// 指定のフレームの座標変換行列をデフォルトに戻す
extern	VECTOR		MV1GetFrameMaxVertexLocalPosition(	int MHandle, int FrameIndex ) ;											// 指定のフレームが持つメッシュ頂点のローカル座標での最大値を得る
extern	VECTOR		MV1GetFrameMinVertexLocalPosition(	int MHandle, int FrameIndex ) ;											// 指定のフレームが持つメッシュ頂点のローカル座標での最小値を得る
extern	VECTOR		MV1GetFrameAvgVertexLocalPosition(	int MHandle, int FrameIndex ) ;											// 指定のフレームが持つメッシュ頂点のローカル座標での平均値を得る
extern	int			MV1GetFrameTriangleNum(				int MHandle, int FrameIndex ) ;											// 指定のフレームに含まれるポリゴンの数を取得する
extern	int			MV1GetFrameMeshNum(					int MHandle, int FrameIndex ) ;											// 指定のフレームが持つメッシュの数を取得する
extern	int			MV1GetFrameMesh(					int MHandle, int FrameIndex, int Index ) ;								// 指定のフレームが持つメッシュのメッシュインデックスを取得する
extern	int			MV1SetFrameVisible(					int MHandle, int FrameIndex, int VisibleFlag ) ;						// 指定のフレームの表示、非表示状態を変更する( TRUE:表示  FALSE:非表示 )
extern	int			MV1GetFrameVisible(					int MHandle, int FrameIndex ) ;											// 指定のフレームの表示、非表示状態を取得する( TRUE:表示  FALSE:非表示 )
extern	int			MV1SetFrameDifColorScale(			int MHandle, int FrameIndex, COLOR_F Scale ) ;							// 指定のフレームのディフューズカラーのスケール値を設定する( デフォルト値は 1.0f )
extern	int			MV1SetFrameSpcColorScale(			int MHandle, int FrameIndex, COLOR_F Scale ) ;							// 指定のフレームのスペキュラカラーのスケール値を設定する( デフォルト値は 1.0f )
extern	int			MV1SetFrameEmiColorScale(			int MHandle, int FrameIndex, COLOR_F Scale ) ;							// 指定のフレームのエミッシブカラーのスケール値を設定する( デフォルト値は 1.0f )
extern	int			MV1SetFrameAmbColorScale(			int MHandle, int FrameIndex, COLOR_F Scale ) ;							// 指定のフレームのアンビエントカラーのスケール値を設定する( デフォルト値は 1.0f )
extern	COLOR_F		MV1GetFrameDifColorScale(			int MHandle, int FrameIndex ) ;											// 指定のフレームのディフューズカラーのスケール値を取得する( デフォルト値は 1.0f )
extern	COLOR_F		MV1GetFrameSpcColorScale(			int MHandle, int FrameIndex ) ;											// 指定のフレームのスペキュラカラーのスケール値を取得する( デフォルト値は 1.0f )
extern	COLOR_F		MV1GetFrameEmiColorScale(			int MHandle, int FrameIndex ) ;											// 指定のフレームのエミッシブカラーのスケール値を取得する( デフォルト値は 1.0f )
extern	COLOR_F		MV1GetFrameAmbColorScale(			int MHandle, int FrameIndex ) ;											// 指定のフレームのアンビエントカラーのスケール値を取得する( デフォルト値は 1.0f )
extern	int			MV1GetFrameSemiTransState(			int MHandle, int FrameIndex ) ;											// 指定のフレームに半透明要素があるかどうかを取得する( 戻り値 TRUE:ある  FALSE:ない )
extern	int			MV1SetFrameOpacityRate(				int MHandle, int FrameIndex, float Rate ) ;								// 指定のフレームの不透明度を設定する( 不透明 1.0f 〜 透明 0.0f )
extern	float		MV1GetFrameOpacityRate(				int MHandle, int FrameIndex ) ;											// 指定のフレームの不透明度を取得する( 不透明 1.0f 〜 透明 0.0f )
extern	int			MV1SetFrameBaseVisible(				int MHandle, int FrameIndex, int VisibleFlag ) ;						// 指定のフレームの初期表示状態を設定する( TRUE:表示  FALSE:非表示 )
extern	int			MV1GetFrameBaseVisible(				int MHandle, int FrameIndex ) ;											// 指定のフレームの初期表示状態を取得する( TRUE:表示  FALSE:非表示 )
extern	int			MV1SetFrameTextureAddressTransform( int MHandle, int FrameIndex, float TransU, float TransV, float ScaleU, float ScaleV, float RotCenterU, float RotCenterV, float Rotate ) ;	// 指定のフレームのテクスチャ座標変換パラメータを設定する
extern	int			MV1SetFrameTextureAddressTransformMatrix( int MHandle, int FrameIndex, MATRIX Matrix ) ;					// 指定のフレームのテクスチャ座標変換行列をセットする
extern	int			MV1ResetFrameTextureAddressTransform( int MHandle, int FrameIndex ) ;										// 指定のフレームのテクスチャ座標変換パラメータをリセットする

// メッシュ関係
extern	int			MV1GetMeshNum(						int MHandle ) ;															// モデルに含まれるメッシュの数を取得する
extern	int			MV1GetMeshMaterial(					int MHandle, int MeshIndex ) ;											// 指定メッシュが使用しているマテリアルのインデックスを取得する
extern	int			MV1GetMeshTriangleNum(				int MHandle, int MeshIndex ) ;											// 指定メッシュに含まれる三角形ポリゴンの数を取得する
extern	int			MV1SetMeshVisible(					int MHandle, int MeshIndex, int VisibleFlag ) ;							// 指定メッシュの表示、非表示状態を変更する( TRUE:表示  FALSE:非表示 )
extern	int			MV1GetMeshVisible(					int MHandle, int MeshIndex ) ;											// 指定メッシュの表示、非表示状態を取得する( TRUE:表示  FALSE:非表示 )
extern	int			MV1SetMeshDifColorScale(			int MHandle, int MeshIndex, COLOR_F Scale ) ;							// 指定のメッシュのディフューズカラーのスケール値を設定する( デフォルト値は 1.0f )
extern	int			MV1SetMeshSpcColorScale( 			int MHandle, int MeshIndex, COLOR_F Scale ) ;							// 指定のメッシュのスペキュラカラーのスケール値を設定する( デフォルト値は 1.0f )
extern	int			MV1SetMeshEmiColorScale( 			int MHandle, int MeshIndex, COLOR_F Scale ) ;							// 指定のメッシュのエミッシブカラーのスケール値を設定する( デフォルト値は 1.0f )
extern	int			MV1SetMeshAmbColorScale( 			int MHandle, int MeshIndex, COLOR_F Scale ) ;							// 指定のメッシュのアンビエントカラーのスケール値を設定する( デフォルト値は 1.0f )
extern	COLOR_F		MV1GetMeshDifColorScale( 			int MHandle, int MeshIndex ) ;											// 指定のメッシュのディフューズカラーのスケール値を取得する( デフォルト値は 1.0f )
extern	COLOR_F		MV1GetMeshSpcColorScale( 			int MHandle, int MeshIndex ) ;											// 指定のメッシュのスペキュラカラーのスケール値を取得する( デフォルト値は 1.0f )
extern	COLOR_F		MV1GetMeshEmiColorScale( 			int MHandle, int MeshIndex ) ;											// 指定のメッシュのエミッシブカラーのスケール値を取得する( デフォルト値は 1.0f )
extern	COLOR_F		MV1GetMeshAmbColorScale( 			int MHandle, int MeshIndex ) ;											// 指定のメッシュのアンビエントカラーのスケール値を取得する( デフォルト値は 1.0f )
extern	int			MV1SetMeshOpacityRate( 				int MHandle, int MeshIndex, float Rate ) ;								// 指定のメッシュの不透明度を設定する( 不透明 1.0f 〜 透明 0.0f )
extern	float		MV1GetMeshOpacityRate( 				int MHandle, int MeshIndex ) ;											// 指定のメッシュの不透明度を取得する( 不透明 1.0f 〜 透明 0.0f )
extern	int			MV1SetMeshDrawBlendMode( 			int MHandle, int MeshIndex, int BlendMode ) ;							// 指定のメッシュの描画ブレンドモードを設定する( DX_BLENDMODE_ALPHA 等 )
extern	int			MV1SetMeshDrawBlendParam( 			int MHandle, int MeshIndex, int BlendParam ) ;							// 指定のメッシュの描画ブレンドパラメータを設定する
extern	int			MV1GetMeshDrawBlendMode( 			int MHandle, int MeshIndex ) ;											// 指定のメッシュの描画ブレンドモードを取得する( DX_BLENDMODE_ALPHA 等 )
extern	int			MV1GetMeshDrawBlendParam( 			int MHandle, int MeshIndex ) ;											// 指定のメッシュの描画ブレンドパラメータを設定する
extern	int			MV1SetMeshBaseVisible( 				int MHandle, int MeshIndex, int VisibleFlag ) ;							// 指定のメッシュの初期表示状態を設定する( TRUE:表示  FALSE:非表示 )
extern	int			MV1GetMeshBaseVisible( 				int MHandle, int MeshIndex ) ;											// 指定のメッシュの初期表示状態を取得する( TRUE:表示  FALSE:非表示 )
extern	int			MV1SetMeshBackCulling( 				int MHandle, int MeshIndex, int CullingFlag ) ;							// 指定のメッシュのバックカリングを行うかどうかを設定する( DX_CULLING_LEFT 等 )
extern	int			MV1GetMeshBackCulling( 				int MHandle, int MeshIndex ) ;											// 指定のメッシュのバックカリングを行うかどうかを取得する( DX_CULLING_LEFT 等 )
extern	VECTOR		MV1GetMeshMaxPosition( 				int MHandle, int MeshIndex ) ;											// 指定のメッシュに含まれるポリゴンの最大ローカル座標を取得する
extern	VECTOR		MV1GetMeshMinPosition( 				int MHandle, int MeshIndex ) ;											// 指定のメッシュに含まれるポリゴンの最小ローカル座標を取得する
extern	int			MV1GetMeshTListNum( 				int MHandle, int MeshIndex ) ;											// 指定のメッシュに含まれるトライアングルリストの数を取得する
extern	int			MV1GetMeshTList( 					int MHandle, int MeshIndex, int Index ) ;								// 指定のメッシュに含まれるトライアングルリストのインデックスを取得する
extern	int			MV1GetMeshSemiTransState( 			int MHandle, int MeshIndex ) ;											// 指定のメッシュに半透明要素があるかどうかを取得する( 戻り値 TRUE:ある  FALSE:ない )
extern	int			MV1SetMeshUseVertDifColor( 			int MHandle, int MeshIndex, int UseFlag ) ;								// 指定のメッシュの頂点ディフューズカラーをマテリアルのディフューズカラーの代わりに使用するかどうかを設定する( TRUE:マテリアルカラーの代わりに使用する  FALSE:マテリアルカラーを使用する )
extern	int			MV1SetMeshUseVertSpcColor( 			int MHandle, int MeshIndex, int UseFlag ) ;								// 指定のメッシュの頂点スペキュラカラーをマテリアルのスペキュラカラーの代わりに使用するかどうかを設定する( TRUE:マテリアルカラーの代わりに使用する  FALSE:マテリアルカラーを使用する )
extern	int			MV1GetMeshUseVertDifColor( 			int MHandle, int MeshIndex ) ;											// 指定のメッシュの頂点ディフューズカラーをマテリアルのディフューズカラーの代わりに使用するかどうかの設定を取得する( 戻り値  TRUE:マテリアルカラーの代わりに使用する  FALSE:マテリアルカラーを使用する )
extern	int			MV1GetMeshUseVertSpcColor( 			int MHandle, int MeshIndex ) ;											// 指定のメッシュの頂点スペキュラカラーをマテリアルのスペキュラカラーの代わりに使用するかどうかの設定を取得する( 戻り値  TRUE:マテリアルカラーの代わりに使用する  FALSE:マテリアルカラーを使用する )

// トライアングルリスト関係
extern	int			MV1GetTriangleListNum(				int MHandle ) ;															// モデルに含まれるトライアングルリストの数を取得する
extern	int			MV1GetTriangleListVertexType(		int MHandle, int TListIndex ) ;											// 指定のトライアングルリストの頂点データタイプを取得する( DX_MV1_VERTEX_TYPE_1FRAME 等 )
extern	int			MV1GetTriangleListPolygonNum(		int MHandle, int TListIndex ) ;											// 指定のトライアングルリストに含まれるポリゴンの数を取得する
extern	int			MV1GetTriangleListVertexNum(		int MHandle, int TListIndex ) ;											// 指定のトライアングルリストに含まれる頂点データの数を取得する

// コリジョン関係
extern	int							MV1SetupCollInfo(				int MHandle, int FrameIndex = -1 , int XDivNum = 32 , int YDivNum = 8 , int ZDivNum = 32 ) ;	// コリジョン情報を構築する
extern	int							MV1TerminateCollInfo(			int MHandle, int FrameIndex = -1 ) ;															// コリジョン情報の後始末
extern	int							MV1RefreshCollInfo(				int MHandle, int FrameIndex = -1 ) ;															// コリジョン情報を更新する
extern	MV1_COLL_RESULT_POLY		MV1CollCheck_Line(				int MHandle, int FrameIndex, VECTOR PosStart, VECTOR PosEnd ) ;									// 線とモデルの当たり判定
extern	MV1_COLL_RESULT_POLY_DIM	MV1CollCheck_LineDim(			int MHandle, int FrameIndex, VECTOR PosStart, VECTOR PosEnd ) ;									// 線とモデルの当たり判定( 戻り値が MV1_COLL_RESULT_POLY_DIM )
extern	MV1_COLL_RESULT_POLY_DIM	MV1CollCheck_Sphere(			int MHandle, int FrameIndex, VECTOR CenterPos, float r ) ;										// 球とモデルの当たり判定
extern	MV1_COLL_RESULT_POLY_DIM	MV1CollCheck_Capsule(			int MHandle, int FrameIndex, VECTOR Pos1, VECTOR Pos2, float r ) ;								// カプセルとモデルの当たり判定
extern	MV1_COLL_RESULT_POLY		MV1CollCheck_GetResultPoly(		MV1_COLL_RESULT_POLY_DIM ResultPolyDim, int PolyNo ) ;											// コリジョン結果ポリゴン配列から指定番号のポリゴン情報を取得する
extern	int							MV1CollResultPolyDimTerminate(	MV1_COLL_RESULT_POLY_DIM ResultPolyDim ) ;														// コリジョン結果ポリゴン配列の後始末をする

// 参照用メッシュ関係
extern	int					MV1SetupReferenceMesh(		int MHandle, int FrameIndex, int IsTransform ) ;						// 参照用メッシュのセットアップ
extern	int					MV1TerminateReferenceMesh(	int MHandle, int FrameIndex, int IsTransform ) ;						// 参照用メッシュの後始末
extern	int					MV1RefreshReferenceMesh(	int MHandle, int FrameIndex, int IsTransform ) ;						// 参照用メッシュの更新
extern	MV1_REF_POLYGONLIST	MV1GetReferenceMesh(		int MHandle, int FrameIndex, int IsTransform ) ;						// 参照用メッシュを取得する

#endif // DX_NON_MODEL

#define DX_FUNCTION_END

}

// ネームスペース DxLib を使用する ------------------------------------------------------
using namespace DxLib ;

// ＤＸライブラリ内部でのみ使用するヘッダファイルのインクルード -------------------------

#ifdef __DX_MAKE
//	#include "DxStatic.h"
#endif

#endif


