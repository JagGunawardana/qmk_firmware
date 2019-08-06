/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _NUMBER,
  _SYMBOL,
  _FUNC,
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE
};

#define SPC_SHF MT(MOD_LSFT, KC_SPC)
#define SPC_NUM LT(_NUMBER, KC_SPC)

#define ESC_HYP MT(MOD_HYPR, KC_ESC)
#define TAB_ALT MT(MOD_RALT, KC_TAB)
#define BSP_NUM LT(_NUMBER, KC_BSPC)
#define DEL_WRP MT(MOD_LCTL | MOD_LALT | MOD_LGUI, KC_DEL)
#define ESC_SYM LT(_SYMBOL, KC_ESC)
#define SPC_SYM LT(_SYMBOL, KC_SPC)
#define SPC_FUN LT(_FUNC, KC_SPC)

#define QUO_NUM LT(_NUMBER, KC_AT)
#define SQUO_SYM LT(_SYMBOL, KC_QUOT)

#define SYMLOCK TG(_SYMBOL)
#define NUMLOCK TG(_NUMBER)

#define ONE_CTL OSM(MOD_LCTL)
#define ONE_ALT OSM(MOD_LALT)
#define ONE_GUI OSM(MOD_LGUI)
#define ONE_HYP OSM(MOD_HYPR)
#define ONE_MEH OSM(MOD_MEH)
#define ONE_WRP OSM(MOD_LCTL | MOD_LALT | MOD_LGUI)
#define ONE_WOA OSM(MOD_LCTL | MOD_LGUI | MOD_LSFT)
#define ONE_DER OSM(MOD_LALT | MOD_LGUI | MOD_LSFT)

#define A_CTRL  MT(MOD_LCTL, KC_A)
#define S_ALT   MT(MOD_LALT, KC_S)
#define D_GUI   MT(MOD_LGUI, KC_D)
#define F_SHFT  MT(MOD_LSFT, KC_F)
#define J_SHFT  MT(MOD_RSFT, KC_J)
#define K_GUI   MT(MOD_RGUI, KC_K)
#define L_ALT   MT(MOD_RALT, KC_L)
#define S_META  MT(MOD_LALT, KC_S)
#define L_META  MT(MOD_LALT, KC_L)
#define MINSCTL MT(MOD_RCTL, KC_SCLN)
#define HSH_CTL MT(MOD_RCTL, KC_BSLS)
#define QUO_MET MT(MOD_LALT, KC_QUOT)

#define ENT_CTL MT(MOD_LCTL, KC_ENT)
#define LT_ALT  MT(MOD_LALT, KC_LEFT)
#define DN_GUI  MT(MOD_LGUI, KC_DOWN)
#define RT_SHFT MT(MOD_LSFT, KC_RGHT)
#define N4_SHFT MT(MOD_RSFT, KC_4)
#define N5_GUI  MT(MOD_RGUI, KC_5)
#define N6_ALT  MT(MOD_RALT, KC_6)

#define BWORD LALT(KC_LEFT)
#define FWORD LALT(KC_RIGHT)

#define NWIN LGUI(KC_GRV)
#define PWIN LGUI(LSFT(KC_GRV))
#define NTAB LGUI(LSFT(KC_RBRC))
#define PTAB LGUI(LSFT(KC_LBRC))
#define NAVBACK LGUI(KC_LBRC)
#define NAVFWD  LGUI(KC_RBRC)

#define XMSNCTL HYPR(KC_F14)
#define XDSKTOP HYPR(KC_F15)
#define XNXTSPC HYPR(KC_F16)
#define XPRVSPC HYPR(KC_F17)
#define XNOTIFY HYPR(KC_F18)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Querty
  | Esc  |   q  |   w  |   e  |   r  |   t  |   y  |   u  |   i  |   o  |   p  | BSPC |
  | SYM  |      |      |      |      |      |      |      |      |      |      | NUM  |
  |------|------|------|------|------|------|------|------|------|------|------|------|
  | TAB  |   a  |   s  |   d  |   f  |   g  |   h  |   j  |   k  |   l  |   ;  | ENT  |
  |      | CTRL | META |      |      |      |      |      |      |  META| CTRL |      |
  |------|------|------|------|------|------|------|------|------|------|------|------|
  |   (  |   z  |   x  |   c  |   v  |   b  |   n  |   m  |   ,  |   .  |   /  |   )  |
  | SHIFT|      |      |      |      |      |      |      |      |      |      | SHIFT|
  |------|------|------|------|------|------|------|------|------|------|------|------|
  | TMUX |  "   |      | LGUI | n/a  | DEL  | TAB  | SPC  | SPC  |      |  '   |      |
  |      | NUM  |      |      |      | SYM  | ALT  | NUM  | FUNC |      | SYM  | FUNC |
 */
 [_QWERTY] = LAYOUT_planck_grid(
    ESC_SYM, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    BSP_NUM,
    KC_TAB,  A_CTRL,  S_META,  KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    L_META,  MINSCTL, KC_ENT, 
    KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,
LCTL(KC_GRV),QUO_NUM, _______, KC_LGUI, _______, SPC_SYM, TAB_ALT, SPC_NUM, SPC_FUN, _______, SQUO_SYM,MO(_FUNC)
 ),
/* Symbol
  | n/a  |   !  |   "  |   £  |   $  |   %  |   ^  |   &  |   *  |   @  |   _  |   `  |
  |      | CTRL | META |   +  |   -  |   =  |   {  |   }  |   "  |   '  |   #  |   ~  |
  |  (   |      |      |      |      |      |   [  |   ]  |   |  |   \  |   /  |   )  |
  |      |      |      | LGUI | n/a  | n/a  |      |      |      |      |      |      |
 */
 [_SYMBOL] = LAYOUT_planck_grid(
     _______, KC_EXLM, KC_AT,   _______, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_DQUO, KC_UNDS, ALGR(KC_GRV), 
     _______, KC_LCTL, KC_LALT, KC_PLUS, KC_MINUS,KC_EQL,  KC_LCBR, KC_RCBR, KC_AT,   QUO_MET, HSH_CTL, KC_PIPE,
     KC_LSPO, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_TILD, KC_GRV,  KC_SLSH, KC_RSPC,
     _______, _______, _______, KC_LGUI, _______, _______, _______, _______, _______, _______, _______, _______
 ),
/* Number
  |      |   1  |   2  |   3  |   4  |  5   |   6  |   7  |   8  |   9  |   0  |   -  |
  |      |      | left |  up  | right|      |   0  |   4  |   5  |   6  |   *  |   +  |
  |      |      |      | down |      |      |      |   1  |   2  |   3  |   =  |   %  |
  |      |      |      |      |      |      |      |      |      |   :  |   $  |      |
 */
[_NUMBER] = LAYOUT_planck_grid(
    XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINUS,
    _______, _______, KC_LEFT, KC_UP,   KC_RIGHT,_______, KC_0,    N4_SHFT, N5_GUI,  N6_ALT,  KC_ASTR, KC_PLUS,
    _______, _______, _______, KC_DOWN, _______, _______, _______, KC_1,    KC_2,    KC_3,    KC_EQL,  KC_PERC,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_COLN, KC_DLR,  _______
),
/* Function
 * |      |      |      |  up  |      | PgUp |      |  F7  |  F8  |  F9  | F10  | F13  |
 * |      |      | left | down | right| PgDn |      |  F4  |  F5  |  F6  | F11  | F14  |
 * |      |      | Home |      | End  | Del  |      |  F1  |  F2  |  F3  | F12  | F15  |
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 */
[_FUNC] = LAYOUT_planck_grid(
    XXXXXXX, XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, KC_PGUP, XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F13,
    XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT,KC_PGDN, XXXXXXX, KC_F4,   KC_F5,   KC_F6,   KC_F11,  KC_F14,
    XXXXXXX, XXXXXXX, KC_HOME, XXXXXXX, KC_END,  KC_DEL,  XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F12,  KC_F15,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)
};

#ifdef AUDIO_ENABLE
#endif

uint32_t layer_state_set_user(uint32_t state) {
  state = update_tri_layer_state(state, _SYMBOL, _NUMBER, _FUNC);
  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
  }
  return true;
}


