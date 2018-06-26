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

#include "planck.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  COLEMAK_LAYER,
  QWERTY_LAYER,
  RAISE_LAYER,
  LOWER_LAYER,
  ADJUST_LAYER,
  GUI_LAYER,
  FUNC_LAYER
};

enum planck_keycodes {
  COLEMAK = SAFE_RANGE,
  QWERTY,
  LOWER,
  RAISE,
  GUI_KEY,
  FUNC_KEY
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak
 *                ,-----------------------------------------------------------------------------------.
 *                | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Func |
 *                |------+------+------+------+------+-------------+------+------+------+------+------|
 * Tap for Esc -- | Ctrl |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 *                |------+------+------+------+------+------|------+------+------+------+------+------|
 *   Tap for ( -- |LShift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |RShift|
 *                |------+------+------+------+------+------+------+------+------+------+------+------|
 *                |  Mod |      | Caps |  Alt |Lower | Bksp |  GUI |Raise |  Mod |      |      |Enter |
 *                `-----------------------------------------------------------------------------------'
 *                                                              ^
 *                                                              |
 * Tap for Space -----------------------------------------------'
 */

[COLEMAK_LAYER] = {
  {KC_TAB,         KC_Q,  KC_W,    KC_F,    KC_P,  KC_G,    KC_J,                  KC_L,  KC_U,    KC_Y,   KC_SCLN, FUNC_KEY},
  {CTL_T(KC_ESC),  KC_A,  KC_R,    KC_S,    KC_T,  KC_D,    KC_H,                  KC_N,  KC_E,    KC_I,   KC_O,    KC_QUOT },
  {KC_LSPO,        KC_Z,  KC_X,    KC_C,    KC_V,  KC_B,    KC_K,                  KC_M,  KC_COMM, KC_DOT, KC_SLSH, KC_RSPC },
  {KC_LGUI,        KC_NO, KC_CAPS, KC_LALT, LOWER, KC_BSPC, LT(GUI_LAYER, KC_SPC), RAISE, KC_LGUI, KC_NO,  KC_NO,   KC_ENT  }
},

/* Qwerty
 *                ,-----------------------------------------------------------------------------------.
 *                | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 *                |------+------+------+------+------+-------------+------+------+------+------+------|
 * Tap for Esc -- | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 *                |------+------+------+------+------+------|------+------+------+------+------+------|
 *   Tap for ( -- |LShift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |RShift|
 *                |------+------+------+------+------+------+------+------+------+------+------+------|
 *                |  Mod |      | Caps |  Alt |Lower |Shift |  GUI |Raise |  Mod |      |      |Enter |
 *                `-----------------------------------------------------------------------------------'
 *                                                              ^
 *                                                              |
 * Tap for Space -----------------------------------------------'
 */
[QWERTY_LAYER] = {
  {KC_TAB,        KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,  KC_Y,                  KC_U,  KC_I,    KC_O,   KC_P,    KC_BSPC},
  {CTL_T(KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,  KC_G,  KC_H,                  KC_J,  KC_K,    KC_L,   KC_SCLN, KC_QUOT},
  {KC_LSPO,       KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,  KC_N,                  KC_M,  KC_COMM, KC_DOT, KC_SLSH, KC_RSPC},
  {KC_LGUI,       KC_SLEP, KC_CAPS, KC_LALT, LOWER, KC_NO, LT(GUI_LAYER, KC_SPC), RAISE, KC_LGUI, KC_NO,  KC_NO,   KC_ENT }
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * | Sup-`|   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |   `  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   _  |   +  |   {  |   }  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[RAISE_LAYER] = {
  {LGUI(KC_GRV), KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______},
  {_______,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_GRV,  KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS},
  {_______,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______},
  {_______,      _______, _______, _______, _______, KC_DEL,  _______, _______, _______, _______, _______, _______}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |      |      | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  | Prev |Vol Dn|Vol Up| Next | Play |      |      |      |Pg Up |Pg Dwn|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |Sleep | Mute |      |      |      | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[LOWER_LAYER] = {
  {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, _______, _______, _______},
  {_______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, _______, _______, _______, KC_PGUP, KC_PGDN, KC_PIPE},
  {_______, _______, _______, _______, KC_OPER, KC_MUTE, _______, _______, _______, KC_HOME, KC_END,  _______},
  {_______, _______, _______, _______, _______, KC_DEL,  _______, _______, _______, _______, _______, _______}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      | Down |Right |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|      | Left |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|  Up  |Qwerty|Colemk|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[ADJUST_LAYER] = {
  {_______,       RESET,   DEBUG,   _______, _______, _______, KC_DOWN, KC_RIGHT, _______, _______, _______, KC_DEL },
  {CTL_T(KC_ESC), _______, MU_MOD,  AU_ON,   AU_OFF,  _______, KC_LEFT, _______,  _______, _______, _______, _______},
  {_______,       MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   KC_UP,   QWERTY,   COLEMAK, _______, _______, _______},
  {_______,       _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______}
},

/* GUI
 * ,-----------------------------------------------------------------------------------.
 * |      |      | MS_2 | MS_U | MS_1 |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      | MS_L | MS_D | MS_R |      | Left | Down |  Up  |Right |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      | MS_3 |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[GUI_LAYER] = {
  {KC_NO, KC_NO, KC_BTN2, KC_MS_U, KC_BTN1, KC_WH_U, KC_DOWN, KC_RGHT, KC_NO, KC_NO, KC_NO, KC_NO},
  {KC_NO, KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_LEFT, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO},
  {KC_NO, KC_NO, KC_NO,   KC_BTN3, KC_NO,   KC_NO,   KC_UP,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO},
  {KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   _______, _______, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO}
},

/* Function
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  F13 |  F14 |  F15 |  F16 |  F17 |  F18 |  F19 |  F20 |  F21 |  F22 |  F23 |  F24 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[FUNC_LAYER] = {
  {KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  _______},
  {KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12 },
  {KC_F13, KC_F14, KC_F15, KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, KC_F21, KC_F22, KC_F23, KC_F24 },
  {KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO  }
}

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(QWERTY_LAYER);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(LOWER_LAYER);
        update_tri_layer(LOWER_LAYER, RAISE_LAYER, ADJUST_LAYER);
      } else {
        layer_off(LOWER_LAYER);
        update_tri_layer(LOWER_LAYER, RAISE_LAYER, ADJUST_LAYER);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(RAISE_LAYER);
        update_tri_layer(LOWER_LAYER, RAISE_LAYER, ADJUST_LAYER);
      } else {
        layer_off(RAISE_LAYER);
        update_tri_layer(LOWER_LAYER, RAISE_LAYER, ADJUST_LAYER);
      }
      return false;
      break;
    case GUI_KEY:
      if (record->event.pressed) {
        layer_on(GUI_LAYER);
      } else {
        layer_off(GUI_LAYER);
      }
      return false;
      break;
    case FUNC_KEY:
      if (record->event.pressed) {
        layer_on(FUNC_LAYER);
      } else {
        layer_off(FUNC_LAYER);
      }
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(COLEMAK_LAYER);
      }
      return false;
      break;
  }
  return true;
}
