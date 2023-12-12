/* Copyright 2015-2023 Jack Humbert
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

enum planck_layers { _QWERTY, _COLEMAK, _LOWER, _RAISE, _ADJUST, _NUMPAD, _LAYER2 };

// enum layers {
//   QWERTY = SAFE_RANGE,
//   BACKLIT,
//   EXT_PLV
// };

// Tap Dance enum
enum {
  TD_LSFT_CAPS,
};

enum custom_keycodes {
  MS_SAFE = SAFE_RANGE,
  QWERTY,
  COLEMAK,
  MS_SPCEQL,

  WN_LEFT_TOP,
  WN_TOP,
  WN_RIGHT_TOP,

  WN_LEFT_HALF,
  WN_CENTER,
  WN_RIGHT_HALF,

  WN_LEFT_BOTTOM,
  WN_BOTTOM,
  WN_RIGHT_BOTTOM,

  MS_TMUX_SESSION,
  MS_TMUX_DETTACH,
  MS_TMUX_SV,
  MS_TMUX_SH,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define NUMPAD MO(_NUMPAD)
#define LAYER2 LT(_LAYER2, KC_LEFT)
#define LSFT_CAPS TD(TD_LSFT_CAPS)

/* clang-format off */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,         KC_Q,    KC_W,   KC_E,    KC_R,  KC_T,   /**/ KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,            KC_BSPC,
    LCTL_T(KC_ESC), KC_A,    KC_S,   KC_D,    KC_F,  KC_G,   /**/ KC_H,   KC_J,   KC_K,    KC_L,    RSFT_T(KC_QUOT), KC_ENT,
    LSFT_CAPS,      KC_Z,    KC_X,   KC_C,    KC_V,  KC_B,   /**/ KC_N,   KC_M,   KC_COMM, KC_DOT,  RCTL_T(KC_SLSH), RSFT_T(KC_SCLN),
    KC_LCTL,        KC_LALT, NUMPAD, KC_LGUI, LOWER, KC_SPC, /**/ KC_SPC, RAISE,  LAYER2,  KC_DOWN, KC_UP,           KC_RGHT
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |   /  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,   /**/ KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,   /**/ KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_ENT ,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,   /**/ KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT,
    NUMPAD,  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC, /**/ KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 *
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_NO,   KC_NO,   /**/ KC_NO,   KC_NO,   KC_LPRN, KC_RPRN, KC_EQL,  KC_BSPC,
    KC_F11,  KC_CIRC, KC_PERC, KC_DLR,  KC_MINS, KC_PPLS, /**/ KC_NO,   KC_RCBR, KC_LCBR, KC_NO,   KC_DQUO, KC_PIPE,
    KC_TRNS, KC_AMPR, KC_ASTR, KC_NO,   KC_NO,   KC_NO,   /**/ KC_NO,   KC_NO,   KC_NO,   KC_HOME, KC_END,  KC_TRNS,
    _______, _______, _______, _______, _______, _______, /**/ _______, _______, KC_MPLY, KC_VOLD, KC_VOLU, KC_MNXT
),

/* Raise
 *
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,  KC_1,      KC_2,    KC_3,    KC_4,    KC_5,    /**/ KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_DEL,  MS_SPCEQL, KC_QUES, KC_DQUO, KC_NO,   KC_NO,   /**/ KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_DQUO, _______,
    KC_TRNS, KC_MPLY,   KC_VOLD, KC_VOLU, KC_MNXT, KC_NO,   /**/ KC_COLN, KC_UNDS, KC_LBRC, KC_RBRC, KC_QUES, KC_BSLS,
    _______, _______,   _______, _______, _______, _______, /**/ _______, _______, KC_MPLY, KC_VOLD, KC_VOLU, KC_MNXT
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, QK_BOOT, DB_TOGG, RGB_TOG, RGB_MOD, RGB_HUI, /**/ RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL ,
    _______, EE_CLR,  MU_NEXT, AU_ON,   AU_OFF,  AG_NORM, /**/ AG_SWAP, QWERTY,  COLEMAK, _______, _______, _______,
    _______, AU_PREV, AU_NEXT, MU_ON,   MU_OFF,  MI_ON,   /**/ MI_OFF,  _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, /**/ _______, _______, _______, _______, _______, _______
),

/* Numpad
 *
 */
[_NUMPAD] = LAYOUT_planck_grid(
    KC_TRNS, MS_TMUX_SV,     MS_TMUX_SH,      KC_NO,           KC_NO, KC_NO,   /**/ KC_NO,   KC_P7, KC_P8,   KC_P9, KC_PPLS, KC_TRNS,
    KC_TRNS, KC_NO,          MS_TMUX_SESSION, MS_TMUX_DETTACH, KC_NO, KC_NO,   /**/ KC_PAST, KC_P4, KC_P5,   KC_P6, KC_PMNS, KC_TRNS,
    KC_TRNS, WN_LEFT_BOTTOM, WN_BOTTOM,       WN_RIGHT_BOTTOM, KC_NO, KC_NO,   /**/ KC_PSLS, KC_P1, KC_P2,   KC_P3, KC_NO,   KC_NO,
    KC_TRNS, KC_NO,          KC_NO,           KC_NO,           KC_NO, _______, /**/ _______, KC_P0, KC_PDOT, KC_NO, KC_NO,   KC_NO
),

/* Layer 2
 *
 */
[_LAYER2] = LAYOUT_planck_grid(
    KC_TRNS, KC_NO, KC_NO, KC_NO,  KC_NO,   KC_NO,   /**/ KC_NO,   KC_NO,   WN_LEFT_TOP,    WN_TOP,    WN_RIGHT_TOP,    KC_TRNS,
    KC_TRNS, KC_NO, KC_NO, KC_NO,  KC_NO,   KC_NO,   /**/ KC_NO,   KC_NO,   WN_LEFT_HALF,   WN_CENTER, WN_RIGHT_HALF,   KC_TRNS,
    KC_NO,   KC_NO, KC_NO, KC_CLR, KC_CLAG, KC_NO,   /**/ KC_WBAK, KC_WFWD, WN_LEFT_BOTTOM, WN_BOTTOM, WN_RIGHT_BOTTOM, KC_NO,
    KC_NO,   KC_NO, KC_NO, KC_NO,  KC_NO,   _______, /**/ _______, KC_NO,   KC_NO,          KC_NO,     KC_NO,           KC_NO
)

};
/* clang-format on */

layer_state_t layer_state_set_user(layer_state_t state) {
  // return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
  switch (get_highest_layer(state)) {
    case _RAISE:
      // rgblight_setrgb (0x00,  0x00, 0xFF);
      rgblight_setrgb (RGB_BLUE);
      break;
    case _LOWER:
      rgblight_setrgb (RGB_RED);
      break;
    case _ADJUST:
      print("here is an adjust");
      rgblight_setrgb (RGB_CYAN);
      break;
    case _NUMPAD:
      rgblight_setrgb (RGB_GREEN);
      break;
    case _LAYER2:
      rgblight_setrgb (RGB_YELLOW);
      break;
    default: //  for any other layers, or the default layer
      rgblight_setrgb (RGB_MAGENTA);
      break;
  }
  return update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
  // return state;
}

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Left Shift, twice for Caps Lock
    [TD_LSFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;

    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;

    case MS_SPCEQL:
      if (record->event.pressed) {
        SEND_STRING(" = ");
      }
      return false;
      break;

    case WN_LEFT_TOP:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LGUI) SS_TAP(X_LEFT) SS_UP(X_LCTL) SS_UP(X_LGUI));
      }
      return false;
      break;

    case WN_TOP:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LALT) SS_DOWN(X_LGUI) SS_TAP(X_UP) SS_UP(X_LALT) SS_UP(X_LGUI) SS_UP(X_UP));
      }
      return false;
      break;

    case WN_RIGHT_TOP:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LGUI) SS_TAP(X_RIGHT) SS_UP(X_LCTL) SS_UP(X_LGUI));
      }
      return false;
      break;

    case WN_LEFT_BOTTOM:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LGUI) SS_DOWN(X_LSFT) SS_TAP(X_LEFT) SS_UP(X_LCTL) SS_UP(X_LGUI) SS_UP(X_LSFT));
      }
      return false;
      break;

    case WN_BOTTOM:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LALT) SS_DOWN(X_LGUI) SS_TAP(X_DOWN) SS_UP(X_LALT) SS_UP(X_LGUI) SS_UP(X_DOWN));
      }
      return false;
      break;

    case WN_RIGHT_BOTTOM:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LGUI) SS_DOWN(X_LSFT) SS_TAP(X_RIGHT) SS_UP(X_LCTL) SS_UP(X_LGUI) SS_UP(X_LSFT));
      }
      return false;
      break;

    case WN_CENTER:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LGUI) SS_DOWN(X_LALT) SS_TAP(X_C) SS_UP(X_LGUI) SS_UP(X_LALT));
      }
      return false;
      break;

    case WN_LEFT_HALF:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LGUI) SS_DOWN(X_LALT) SS_TAP(X_LEFT) SS_UP(X_LGUI) SS_UP(X_LALT));
      }
      return false;
      break;

    case WN_RIGHT_HALF:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LGUI) SS_DOWN(X_LALT) SS_TAP(X_RIGHT) SS_UP(X_LGUI) SS_UP(X_LALT));
      }
      return false;
      break;

    case MS_TMUX_SESSION:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_B) SS_UP(X_LCTL) SS_TAP(X_S));
      }
      return false;
      break;

    case MS_TMUX_DETTACH:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_B) SS_UP(X_LCTL) SS_TAP(X_D));
      }
      return false;
      break;

    case MS_TMUX_SV:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_B) SS_UP(X_LCTL) SS_TAP(X_BACKSLASH));
      }
      return false;
      break;

    case MS_TMUX_SH:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_B) SS_UP(X_LCTL) SS_TAP(X_MINUS));
      }
      return false;
      break;
  }
  return true;
}

/* clang-format off */
float melody[8][2][2] = {
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
};
/* clang-format on */

#define JUST_MINOR_THIRD 1.2
#define JUST_MAJOR_THIRD 1.25
#define JUST_PERFECT_FOURTH 1.33333333
#define JUST_TRITONE 1.42222222
#define JUST_PERFECT_FIFTH 1.33333333

#define ET12_MINOR_SECOND 1.059463
#define ET12_MAJOR_SECOND 1.122462
#define ET12_MINOR_THIRD 1.189207
#define ET12_MAJOR_THIRD 1.259921
#define ET12_PERFECT_FOURTH 1.33484
#define ET12_TRITONE 1.414214
#define ET12_PERFECT_FIFTH 1.498307

deferred_token tokens[8];

uint32_t reset_note(uint32_t trigger_time, void *note) {
    *(float*)note = 440.0f;
    return 0;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    cancel_deferred_exec(tokens[index]);
    if (clockwise) {
        melody[index][1][0] = melody[index][1][0] * ET12_MINOR_SECOND;
        melody[index][0][0] = melody[index][1][0] / ET12_PERFECT_FIFTH;
        audio_play_melody(&melody[index], 2, false);
    } else {
        melody[index][1][0] = melody[index][1][0] / ET12_MINOR_SECOND;
        melody[index][0][0] = melody[index][1][0] * ET12_TRITONE;
        audio_play_melody(&melody[index], 2, false);
    }
    tokens[index] = defer_exec(1000, reset_note, &melody[index][1][0]);
    return false;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    return true;
}
