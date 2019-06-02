/*****************************************************************************/
/*!
\file			InputKeyDef.cpp
\brief			WIN32 API Input System
*/
/*****************************************************************************/
#include "stdafx.h"
#include "inputkeydef.h"

ZG_API const char* LIST_KEYBOARD_NAME_[NUMBER_OF_KEYBOARD_KEY]{
	"MOUSE_LEFT"
	, "MOUSE_RIGHT"
	, "MOUSE_MIDDLE"
	, "KEY_BACK"
	, "KEY_TAB"
	, "KEY_RETURN"
	, "KEY_LSHIFT"
	, "KEY_RSHIFT"
	, "KEY_LCTRL"
	, "KEY_RCTRL"
	, "KEY_LALT"
	, "KEY_RALT"
	, "KEY_PRINTSCREEN"
	, "KEY_SCROLLLOCK"
	, "KEY_PAUSE"
	, "KEY_CAPSLOCK"
	, "KEY_ESCAPE"
	, "KEY_SPACE"
	, "KEY_PAGEUP"
	, "KEY_PAGEDOWN"
	, "KEY_END"
	, "KEY_HOME"
	, "KEY_LEFT"
	, "KEY_UP"
	, "KEY_RIGHT"
	, "KEY_DOWN"
	, "KEY_INSERT"
	, "KEY_DELETE"
	, "KEY_0"
	, "KEY_1"
	, "KEY_2"
	, "KEY_3"
	, "KEY_4"
	, "KEY_5"
	, "KEY_6"
	, "KEY_7"
	, "KEY_8"
	, "KEY_9"
	, "KEY_A"
	, "KEY_B"
	, "KEY_C"
	, "KEY_D"
	, "KEY_E"
	, "KEY_F"
	, "KEY_G"
	, "KEY_H"
	, "KEY_I"
	, "KEY_J"
	, "KEY_K"
	, "KEY_L"
	, "KEY_M"
	, "KEY_N"
	, "KEY_O"
	, "KEY_P"
	, "KEY_Q"
	, "KEY_R"
	, "KEY_S"
	, "KEY_T"
	, "KEY_U"
	, "KEY_V"
	, "KEY_W"
	, "KEY_X"
	, "KEY_Y"
	, "KEY_Z"
	, "KEY_NUMPAD0"
	, "KEY_NUMPAD1"
	, "KEY_NUMPAD2"
	, "KEY_NUMPAD3"
	, "KEY_NUMPAD4"
	, "KEY_NUMPAD5"
	, "KEY_NUMPAD6"
	, "KEY_NUMPAD7"
	, "KEY_NUMPAD8"
	, "KEY_NUMPAD9"
	, "KEY_NUM_MULTIPLY"
	, "KEY_NUM_PLUS"
	, "KEY_NUM_MINUS"
	, "KEY_NUM_PERIOD"
	, "KEY_NUM_DIVIDE"
	, "KEY_NUMLOCK"
	, "KEY_F1"
	, "KEY_F2"
	, "KEY_F3"
	, "KEY_F4"
	, "KEY_F5"
	, "KEY_F6"
	, "KEY_F7"
	, "KEY_F8"
	, "KEY_F9"
	, "KEY_F10"
	, "KEY_F11"
	, "KEY_F12"
	, "KEY_SEMICOLON"
	, "KEY_SLASH"
	, "KEY_BACKQUOTE"
	, "KEY_LBRACKET"
	, "KEY_BACKSLASH"
	, "KEY_RBRACKET"
	, "KEY_QUOTE"
	, "KEY_EQUAL"
	, "KEY_MINUS"
	, "KEY_PERIOD"
	, "KEY_COMMA"
};

ZG_API const int LIST_KEYBOARD_CODE_[NUMBER_OF_KEYBOARD_KEY]{
   VK_LBUTTON	   
 , VK_RBUTTON	   
 , VK_MBUTTON	   
 , VK_BACK       
 , VK_TAB      
 , VK_RETURN		
 , VK_LSHIFT		
 , VK_RSHIFT		
 , VK_LCONTROL	
 , VK_RCONTROL	
 , VK_LMENU		
 , VK_RMENU		
 , VK_SNAPSHOT
 , VK_SCROLL
 , VK_PAUSE		
 , VK_CAPITAL
 , VK_ESCAPE   
 , VK_SPACE		
 , VK_PRIOR		
 , VK_NEXT
 , VK_END		
 , VK_HOME		
 , VK_LEFT		
 , VK_UP			
 , VK_RIGHT		
 , VK_DOWN		
 , VK_INSERT		
 , VK_DELETE		
 , 0x30        
 , 0x31        
 , 0x32        
 , 0x33        
 , 0x34        
 , 0x35        
 , 0x36        
 , 0x37        
 , 0x38        
 , 0x39        
 , 0x41        
 , 0x42        
 , 0x43        
 , 0x44        
 , 0x45        
 , 0x46        
 , 0x47        
 , 0x48        
 , 0x49        
 , 0x4A        
 , 0x4B        
 , 0x4C        
 , 0x4D        
 , 0x4E        
 , 0x4F        
 , 0x50        
 , 0x51        
 , 0x52        
 , 0x53        
 , 0x54        
 , 0x55        
 , 0x56        
 , 0x57        
 , 0x58        
 , 0x59        
 , 0x5A        
 , VK_NUMPAD0	
 , VK_NUMPAD1	
 , VK_NUMPAD2	
 , VK_NUMPAD3	
 , VK_NUMPAD4	
 , VK_NUMPAD5	
 , VK_NUMPAD6	
 , VK_NUMPAD7	
 , VK_NUMPAD8	
 , VK_NUMPAD9	
 , VK_MULTIPLY
 , VK_ADD
 , VK_SUBTRACT
 , VK_DECIMAL
 , VK_DIVIDE
 , VK_NUMLOCK	
 , VK_F1		
 , VK_F2		
 , VK_F3		
 , VK_F4		
 , VK_F5		
 , VK_F6		
 , VK_F7		
 , VK_F8		
 , VK_F9		
 , VK_F10		
 , VK_F11		
 , VK_F12		
 , VK_OEM_1    
 , VK_OEM_2	
 , VK_OEM_3    
 , VK_OEM_4    
 , VK_OEM_5    
 , VK_OEM_6    
 , VK_OEM_7	
 , VK_OEM_PLUS 		
 , VK_OEM_MINUS		
 , VK_OEM_PERIOD		
 , VK_OEM_COMMA
};

//Controller
ZG_API const char* LIST_CONTROLLER_NAME_[NUMBER_OF_CONTROLLER_KEY]{
	"GAME_DPAD_UP"
	, "GAME_DPAD_DOWN"
	, "GAME_DPAD_LEFT"
	, "GAME_DPAD_RIGHT"
	, "GAME_START"
	, "GAME_BACK"
	, "GAME_A"
	, "GAME_B"
	, "GAME_X"
	, "GAME_Y"
	, "GAME_LEFT_BUMP"
	, "GAME_RIGHT_BUMP"
	, "GAME_LEFT_TRIGGER"
	, "GAME_RIGHT_TRIGGER"
	, "GAME_LSTICK_PRESS"
	, "GAME_RSTICK_PRESS"
	, "GAME_LSTICK_UP"
	, "GAME_LSTICK_DOWN"
	, "GAME_LSTICK_LEFT"
	, "GAME_LSTICK_RIGHT"
	, "GAME_RSTICK_UP"
	, "GAME_RSTICK_DOWN"
	, "GAME_RSTICK_LEFT"
	, "GAME_RSTICK_RIGHT"
	, "GAME_LSTICK"
	, "GAME_RSTICK"
};

ZG_API const int LIST_CONTROLLER_CODE_[NUMBER_OF_CONTROLLER_KEY]{
	GAME_DPAD_UP
	, GAME_DPAD_DOWN
	, GAME_DPAD_LEFT
	, GAME_DPAD_RIGHT
	, GAME_START
	, GAME_BACK
	, GAME_A
	, GAME_B
	, GAME_X
	, GAME_Y
	, GAME_LEFT_BUMP
	, GAME_RIGHT_BUMP
	, GAME_LEFT_TRIGGER
	, GAME_RIGHT_TRIGGER
	, GAME_LSTICK_PRESS
	, GAME_RSTICK_PRESS
	, GAME_LSTICK_UP
	, GAME_LSTICK_DOWN
	, GAME_LSTICK_LEFT
	, GAME_LSTICK_RIGHT
	, GAME_RSTICK_UP
	, GAME_RSTICK_DOWN
	, GAME_RSTICK_LEFT
	, GAME_RSTICK_RIGHT
	, GAME_LSTICK
	, GAME_RSTICK
};