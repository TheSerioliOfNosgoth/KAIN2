#ifndef MENU_H
#define MENU_H

struct Extents2d 
{
	int xmin; // size=0, offset=0
	int xmax; // size=0, offset=4
	int ymin; // size=0, offset=8
	int ymax; // size=0, offset=12
};

struct menu_format_t // hashcode: 0xD91CEBF0 (dec: -652416016)
{
	int xpos; // size=0, offset=0
	int ypos; // size=0, offset=4
	int lineskip; // size=0, offset=8
	int itemskip; // size=0, offset=12
	int width; // size=0, offset=16
	int center; // size=0, offset=20
	int border; // size=0, offset=24
};

struct menu_stack_t // hashcode: 0x04101191 (dec: 68161937)
{
	int (*fn)(void*, int); // size=0, offset=0
	int index; // size=0, offset=4
	struct menu_format_t format; // size=28, offset=8
};

typedef enum menu_ctrl_t // Hashcode: 0xE0BD1E93 (dec: -524476781)
{
	menu_ctrl_none = 0,
	menu_ctrl_up = 1,
	menu_ctrl_down = 2,
	menu_ctrl_left = 3,
	menu_ctrl_right = 4,
	menu_ctrl_engage = 5,
	menu_ctrl_cancel = 6,
	menu_ctrl_start = 7,
	menu_ctrl_num_items = 8,
}menu_ctrl_t;

struct menu_item_t // hashcode: 0xF260D8A8 (dec: -228534104)
{
	char* text; // size=0, offset=0
	int (*fn)(void*, intptr_t, enum menu_ctrl_t); // size=0, offset=4
	intptr_t parameter; // size=0, offset=8
	long flags; // size=0, offset=12
};

typedef enum menu_sound_t // Hashcode: 0x0248C7C9 (dec: 38324169)
{
	menu_sound_none = 0,
	menu_sound_default = 1,
	menu_sound_select = 2,
	menu_sound_adjust = 3,
	menu_sound_engage = 4,
	menu_sound_pop = 5,
}menu_sound_t;

struct menu_t // hashcode: 0x8AB0D2F2 (dec: -1968123150)
{
	int nmenus; // size=0, offset=0
	int nitems; // size=0, offset=4
	int nbytes; // size=0, offset=8
	struct menu_stack_t stack[5]; // size=180, offset=12
	struct menu_item_t items[12]; // size=192, offset=192
	char bytes[512]; // size=512, offset=384
	void (*drawfn)(void*); // size=0, offset=896
	void* opaque; // size=0, offset=900
};

struct menu_sound_entry_t // hashcode: 0xFFB1DFB2 (dec: -5120078)
{
	enum menu_sound_t sound; // size=4, offset=0
	int sfx; // size=0, offset=4
};

typedef struct menu_sound_entry_t menu_sound_entry_t;

extern int menu_data_size(); // 0x800B7A40
extern void menu_initialize(struct menu_t *menu, void *opaque); // 0x800B7A48
extern void menu_format(struct menu_t *menu, int center, int xpos, int ypos, int width, int lineskip, int itemskip, int border); // 0x800B7A8C
extern void menu_set(struct menu_t *menu, int fn(void*, int)); // 0x800B7ADC
extern void menu_push(struct menu_t *menu, int fn(void*, int)); // 0x800B7B00
extern void menu_pop(struct menu_t *menu); // 0x800B7B70
extern void menu_item_flags(struct menu_t* menu, int (*fn)(void*, intptr_t, enum menu_ctrl_t), intptr_t parameter, long flags, char* format, ...); // 0x800B7B84
extern void menu_item(struct menu_t *menu, int (*fn)(void*, intptr_t, enum menu_ctrl_t), intptr_t parameter, char *format, ...); // 0x800B7C14
extern void menu_build(struct menu_t *menu); // 0x800B7CB8
extern void DisplayHintBox(int len, int y); // 0x800B7D10
extern void DisplayMenuBox(int x0, int x1, int y0, int y1); // 0x800B7E3C
extern int menu_draw_item(struct menu_t *menu, int ypos, int xadj, int yadj, char *text, int color, long flags, struct Extents2d *e); // 0x800B8074
extern void menu_draw(struct menu_t *menu); // 0x800B8478
extern void menu_run(struct menu_t *menu); // 0x800B85D8
extern void menu_process(struct menu_t *menu); // 0x800B87C8


#endif
