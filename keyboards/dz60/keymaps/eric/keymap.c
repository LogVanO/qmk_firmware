#include "dz60.h"

#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Layer 0
* ,-----------------------------------------------------------------------------------------.
* | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |  \  |  ~  |
* |-----------------------------------------------------------------------------------------+
* | Tab   |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  | Bkspc   |
* |-----------------------------------------------------------------------------------------+
* | Caps    |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
* |-----------------------------------------------------------------------------------------+
* | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |   /   |  Shift   | Fn |
* |-----------------------------------------------------------------------------------------+
* | Ctrl  |  GUI |  Alt |                    Space               |   Alt   |  GUI  |  Ctrl  |
* `-----------------------------------------------------------------------------------------'
*/

	KEYMAP_2_SHIFTS(
		KC_ESC,  KC_1,    KC_2,    KC_3,   KC_4,  KC_5,    KC_6,    KC_7,  KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,   KC_BSLS,   KC_GRV, 
		KC_TAB,           KC_Q,    KC_W,   KC_E,  KC_R,    KC_T,    KC_Y,  KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC, KC_BSPC, 
		KC_CAPS,          KC_A,    KC_S,   KC_D,  KC_F,    KC_G,    KC_H,  KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,  KC_ENT, 
		KC_LSFT, KC_TRNS, KC_Z,    KC_X,   KC_C,  KC_V,    KC_B,    KC_N,  KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,  KC_RSFT,   MO(1),
		KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_RALT, KC_RGUI, MO(2)),



 /* Layer 1
* ,-----------------------------------------------------------------------------------------.
* |     | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 | INS | Del |
* |-----------------------------------------------------------------------------------------+
* |      | PGUP | UP | PGDN | HOME | &  |     |     |     |     | Prnt | UP | Del |  Bkspc  |
* |-----------------------------------------------------------------------------------------+
* |        | LEFT | DWN | RGHT | END |  *  |    |    | PGUP | HOME | LEFT | RGHT |          |
* |-----------------------------------------------------------------------------------------+
* |           |  _  |  +  |  (  |  )  |  |  |  ~  |     | PGDN | END |  DWN  |        |     |
* |-----------------------------------------------------------------------------------------+
* |       |      |       |                                         |        |      |        |
* `-----------------------------------------------------------------------------------------'
*/ 


	KEYMAP_2_SHIFTS(
		KC_TRNS,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS,  KC_DEL, 
		KC_TRNS,  KC_PGUP,  KC_UP,  KC_PGDN,  KC_HOME,  KC_AMPR,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_PSCR,  KC_UP,    KC_DEL,  KC_BSPC, 
		KC_TRNS,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_END,  KC_ASTR,  KC_TRNS,  KC_TRNS,  KC_PGUP,  KC_HOME,  KC_LEFT,  KC_RGHT,  KC_TRNS, 
		KC_TRNS, KC_TRNS,  KC_UNDS,  KC_PLUS,  KC_LPRN,  KC_RPRN,  KC_PIPE,  KC_TILD,  KC_TRNS,  KC_PGDN,   KC_END,  KC_DOWN,  KC_TRNS,  KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
};

enum function_id {
    SHIFT_ESC,
};

const uint16_t PROGMEM fn_actions[] = {
  [0]  = ACTION_FUNCTION(SHIFT_ESC),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  static uint8_t shift_esc_shift_mask;
  switch (id) {
    case SHIFT_ESC:
      shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
      if (record->event.pressed) {
        if (shift_esc_shift_mask) {
          add_key(KC_GRV);
          send_keyboard_report();
        } else {
          add_key(KC_ESC);
          send_keyboard_report();
        }
      } else {
        if (shift_esc_shift_mask) {
          del_key(KC_GRV);
          send_keyboard_report();
        } else {
          del_key(KC_ESC);
          send_keyboard_report();
        }
      }
      break;
  }
}