//stamp:19d09730e8d050e8
/*<------------------------------------------------------------------------------------------------->*/
/*该文件由uiresbuilder生成，请不要手动修改*/
/*<------------------------------------------------------------------------------------------------->*/
#ifndef _UIRES_H_
#define _UIRES_H_
	struct _UIRES{
		struct _UIDEF{
			const TCHAR * XML_INIT;
			}UIDEF;
		struct _LAYOUT{
			const TCHAR * XML_MAINWND;
			const TCHAR * WIN_TOPNAVBAR;
			const TCHAR * WIN_FOOTNAVBAR;
			const TCHAR * MAIN_PAGE_HOME;
			const TCHAR * MAIN_PAGE_BUTTON;
			const TCHAR * MAIN_PAGE_LIST;
			const TCHAR * LIST_PAGE_LISTCTRL;
			const TCHAR * LIST_PAGE_MCLISTVIEW;
			const TCHAR * XML_INPUTWND;
			const TCHAR * XML_MESSAGEWND;
			}LAYOUT;
		struct _values{
			const TCHAR * string;
			const TCHAR * color;
			const TCHAR * skin;
			}values;
		struct _IMG{
			const TCHAR * shadow_png;
			const TCHAR * scroll_bar_png;
			const TCHAR * checkbox_png;
			const TCHAR * close_png;
			const TCHAR * max_png;
			const TCHAR * restore_png;
			const TCHAR * min_png;
			const TCHAR * msgicon;
			const TCHAR * menuicon;
			const TCHAR * home_png;
			const TCHAR * query_png;
			const TCHAR * png_lcex_header;
			const TCHAR * png_lcex_header_arrow;
			}IMG;
		struct _ICON{
			const TCHAR * ICON_LOGO;
			}ICON;
		struct _SMENU{
			const TCHAR * menu_tray;
			}SMENU;
	};
#endif//_UIRES_H_
#ifdef INIT_R_DATA
struct _UIRES UIRES={
		{
			_T("UIDEF:XML_INIT"),
		},
		{
			_T("LAYOUT:XML_MAINWND"),
			_T("LAYOUT:WIN_TOPNAVBAR"),
			_T("LAYOUT:WIN_FOOTNAVBAR"),
			_T("LAYOUT:MAIN_PAGE_HOME"),
			_T("LAYOUT:MAIN_PAGE_BUTTON"),
			_T("LAYOUT:MAIN_PAGE_LIST"),
			_T("LAYOUT:LIST_PAGE_LISTCTRL"),
			_T("LAYOUT:LIST_PAGE_MCLISTVIEW"),
			_T("LAYOUT:XML_INPUTWND"),
			_T("LAYOUT:XML_MESSAGEWND"),
		},
		{
			_T("values:string"),
			_T("values:color"),
			_T("values:skin"),
		},
		{
			_T("IMG:shadow_png"),
			_T("IMG:scroll_bar_png"),
			_T("IMG:checkbox_png"),
			_T("IMG:close_png"),
			_T("IMG:max_png"),
			_T("IMG:restore_png"),
			_T("IMG:min_png"),
			_T("IMG:msgicon"),
			_T("IMG:menuicon"),
			_T("IMG:home_png"),
			_T("IMG:query_png"),
			_T("IMG:png_lcex_header"),
			_T("IMG:png_lcex_header_arrow"),
		},
		{
			_T("ICON:ICON_LOGO"),
		},
		{
			_T("SMENU:menu_tray"),
		},
	};
#else
extern struct _UIRES UIRES;
#endif//INIT_R_DATA

#ifndef _R_H_
#define _R_H_
struct _R{
	struct _name{
		 const wchar_t * btnSwitch;
		 const wchar_t * btn_close;
		 const wchar_t * btn_max;
		 const wchar_t * btn_min;
		 const wchar_t * btn_restore;
		 const wchar_t * btn_set;
		 const wchar_t * button1st;
		 const wchar_t * button2nd;
		 const wchar_t * button3rd;
		 const wchar_t * col1;
		 const wchar_t * col2;
		 const wchar_t * col_text1;
		 const wchar_t * col_text2;
		 const wchar_t * devstatus1;
		 const wchar_t * devstatus12;
		 const wchar_t * devstatus2;
		 const wchar_t * devstatus3;
		 const wchar_t * devstatus4;
		 const wchar_t * footnavbar;
		 const wchar_t * leng;
		 const wchar_t * lsct1;
		 const wchar_t * mclv1;
		 const wchar_t * mclv1_header;
		 const wchar_t * menu;
		 const wchar_t * msgicon;
		 const wchar_t * msgtext;
		 const wchar_t * msgtitle;
		 const wchar_t * tab_list;
		 const wchar_t * tab_main;
		 const wchar_t * title;
		 const wchar_t * versions;
		 const wchar_t * wnd_alert;
		 const wchar_t * wnd_normal;
		 const wchar_t * wnd_tips;
		 const wchar_t * wnd_user;
	}name;
	struct _id{
		int btnSwitch;
		int btn_close;
		int btn_max;
		int btn_min;
		int btn_restore;
		int btn_set;
		int button1st;
		int button2nd;
		int button3rd;
		int col1;
		int col2;
		int col_text1;
		int col_text2;
		int devstatus1;
		int devstatus12;
		int devstatus2;
		int devstatus3;
		int devstatus4;
		int footnavbar;
		int leng;
		int lsct1;
		int mclv1;
		int mclv1_header;
		int menu;
		int msgicon;
		int msgtext;
		int msgtitle;
		int tab_list;
		int tab_main;
		int title;
		int versions;
		int wnd_alert;
		int wnd_normal;
		int wnd_tips;
		int wnd_user;
	}id;
	struct _color{
		int background_color_base;
		int border_color_base;
		int border_color_extra_light;
		int border_color_light;
		int border_color_lighter;
		int color_black;
		int color_danger;
		int color_info;
		int color_primary;
		int color_success;
		int color_text_placeholder;
		int color_text_primary;
		int color_text_regular;
		int color_text_secondary;
		int color_trans;
		int color_warning;
		int color_white;
	}color;
	struct _string{
		int title;
		int ver;
	}string;

};
#endif//_R_H_
#ifdef INIT_R_DATA
struct _R R={
	{
		L"btnSwitch",
		L"btn_close",
		L"btn_max",
		L"btn_min",
		L"btn_restore",
		L"btn_set",
		L"button1st",
		L"button2nd",
		L"button3rd",
		L"col1",
		L"col2",
		L"col_text1",
		L"col_text2",
		L"devstatus1",
		L"devstatus12",
		L"devstatus2",
		L"devstatus3",
		L"devstatus4",
		L"footnavbar",
		L"leng",
		L"lsct1",
		L"mclv1",
		L"mclv1_header",
		L"menu",
		L"msgicon",
		L"msgtext",
		L"msgtitle",
		L"tab_list",
		L"tab_main",
		L"title",
		L"versions",
		L"wnd_alert",
		L"wnd_normal",
		L"wnd_tips",
		L"wnd_user"
	}
	,
	{
		65564,
		65542,
		65540,
		65539,
		65541,
		65559,
		65565,
		65566,
		65567,
		65554,
		65556,
		65555,
		65557,
		65544,
		65545,
		65546,
		65547,
		65548,
		65543,
		65558,
		65551,
		65552,
		65553,
		65537,
		65562,
		65563,
		65561,
		65550,
		65536,
		65538,
		65549,
		65568,
		65560,
		65570,
		65569
	}
	,
	{
		0,
		1,
		2,
		3,
		4,
		5,
		6,
		7,
		8,
		9,
		10,
		11,
		12,
		13,
		14,
		15,
		16
	}
	,
	{
		0,
		1
	}
	
};
#else
extern struct _R R;
#endif//INIT_R_DATA
