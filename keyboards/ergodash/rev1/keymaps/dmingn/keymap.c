#include QMK_KEYBOARD_H
#include "keymap_jp.h"
#include "jtu_custom_keycodes.h"

#define _QWERTY_WIN 0
#define _QWERTY_MAC 1
#define _LOWER 2
#define _RAISE 3
#define _ADJUST 16

enum custom_keycodes {
  QWE_WIN = JTU_SAFE_RANGE,
  QWE_MAC,
  LOWER,
  RAISE,
  ADJUST,
};

#define EISU LALT(KC_GRV)
#define LOMH LT(_LOWER, KC_MHEN)
#define RAHE LT(_RAISE, KC_HENK)
#define UNDS S(KC_RO)
#define RSFT_US RSFT_T(UNDS)
#define LOEN LT(_LOWER, KC_HAEN)
#define RAJA LT(_RAISE, KC_HANJ)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty (Win)
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | ESC  |   1  |   2  |   3  |   4  |   5  |   ~  |                    |   =  |   6  |   7  |   8  |   9  |   0  |  -   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |   [  |                    |   ]  |   Y  |   U  |   I  |   O  |   P  |  \   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |      |                    |   _  |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |      |                    |      |   N  |   M  |   ,  |   .  |   /  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Caps |  GUI |  ALt | Ctrl |||||||| LoMh | Space|  Del |||||||| Bksp | Enter| RaHe |||||||| Left |  Up  | Down | Right|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY_WIN] = LAYOUT( \
    KC_ESC,  KC_1,    JU_2,    KC_3,    KC_4,    KC_5,    JU_GRV,                    JU_EQL,  JU_6,    JU_7,    JU_8,    JU_9,    JU_0,    JU_MINS, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    JU_LBRC,                   JU_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    JU_BSLS, \
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_PGUP,                   KC_PGDN, KC_H,    KC_J,    KC_K,    KC_L,    JU_SCLN, JU_QUOT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_DEL,                    KC_BSPC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_US, \
    JU_CAPS, KC_LGUI, KC_LALT, KC_LCTL,          LOMH,    KC_SPC,  KC_SPC,  KC_SPC,  KC_ENT,  RAHE,             KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT  \
  ),

  /* Qwerty (Mac)
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | ____ | ____ | ____ | ____ | ____ | ____ | ____ |                    | ____ | ____ | ____ | ____ | ____ | ____ | ____ |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | ____ | ____ | ____ | ____ | ____ | ____ | ____ |                    | ____ | ____ | ____ | ____ | ____ | ____ | ____ |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | ____ | ____ | ____ | ____ | ____ | ____ | ____ |                    | ____ | ____ | ____ | ____ | ____ | ____ | ____ |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | ____ | ____ | ____ | ____ | ____ | ____ | ____ |                    | ____ | ____ | ____ | ____ | ____ | ____ | ____ |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | ____ | ____ | ____ |  Cmd |||||||| LoEn | ____ | ____ |||||||| ____ | ____ | RaJa |||||||| ____ | ____ | ____ | ____ |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY_MAC] = LAYOUT( \
    _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, KC_LGUI,          LOEN,    _______, _______, _______, _______, RAJA,             _______, _______, _______, _______  \
  ),

  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | ____ |  F1  |  F2  |  F3  |  F4  |  F5  |  F11 |                    |  F12 |  F6  |  F7  |  F8  |  F9  |  F10 | Pscr |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | ____ |   1  |   2  |   3  |   4  |   5  |   [  |                    |   ]  |   6  |   7  |   8  |   9  |   0  | ____ |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | ____ |   !  |   @  |   #  |   $  |   %  |   {  |                    |   }  |   ^  |   &  |   *  |   (  |   )  | ____ |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | ____ |   \  |   |  |   `  |   '  |   "  | ____ |                    | ____ |   -  |   _  |   =  |   ~  |   +  | ____ |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | ____ | ____ | ____ | ____ |||||||| Lower| ____ | ____ |||||||| ____ | ____ | Raise|||||||| Home |PageUp|PageDn|  End |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_LOWER] = LAYOUT(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,                    KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_PSCR, \
    _______, KC_1,    JU_2,    KC_3,    KC_4,    KC_5,    JU_LBRC,                   JU_RBRC, JU_6,    JU_7,    JU_8,    JU_9,    JU_0,    _______, \
    _______, KC_EXLM, JP_AT,   KC_HASH, KC_DLR,  KC_PERC, JP_LCBR,                   JP_RCBR, JP_CIRC, JP_AMPR, JP_ASTR, JP_LPRN, JP_RPRN, _______, \
    _______, JU_BSLS, JP_PIPE, JU_GRV,  JU_QUOT, JP_DQUO, _______,                   _______, KC_MINS, JP_UNDS, JU_EQL,  JP_TILD, JP_PLUS, _______, \
    _______, _______, _______, _______,          LOWER,   _______, _______, _______, _______, RAISE,            KC_HOME, KC_PGUP, KC_PGDN, KC_END   \
  ),

  /* Raise
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | ____ |      |      |      |      |      |      |                    |      | Nlck |   7  |   8  |   9  |   /  | ____ |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | ____ |      |      |      |      |      |      |                    |      |      |   4  |   5  |   6  |   *  | ____ |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | ____ |      |      |      |      |      |      |                    |      |   =  |   1  |   2  |   3  |   -  | ____ |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | ____ |      |      |      |      |      | ____ |                    | ____ | Enter|   0  |      |   .  |   +  | ____ |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | ____ | ____ | ____ | ____ |||||||| Lower| ____ | ____ |||||||| ____ | ____ | Raise|||||||| Home |PageUp|PageDn|  End |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_RAISE] = LAYOUT(
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_NLCK, KC_P7,   KC_P8,   KC_P9,   KC_PSLS, _______, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, KC_P4,   KC_P5,   KC_P6,   KC_PAST, _______, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_PEQL, KC_P1,   KC_P2,   KC_P3,   KC_PMNS, _______, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,                   _______, KC_PENT, KC_P0,   XXXXXXX, KC_PDOT, KC_PPLS, _______, \
    _______, _______, _______, _______,          LOWER,   _______, _______, _______, _______, RAISE,            KC_HOME, KC_PGUP, KC_PGDN, KC_END   \
  ),

  /* Adjust
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | Reset|      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |RGB ON|  MODE|  HUE-|  HUE+|      |                    |      |  SAT-|  SAT+|  VAL-|  VAL+|      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      | BL ON|  BRTG|  INC |   DEC|  Win |                    |  Mac |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_ADJUST] = LAYOUT(
    RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI, XXXXXXX,                   XXXXXXX, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, BL_TOGG, BL_BRTG, BL_INC , BL_DEC , QWE_WIN,                   QWE_MAC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
  )
};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  bool continue_process = process_record_user_jtu(keycode, record);
  if (continue_process == false) {
    return false;
  }
  switch (keycode) {
    case QWE_WIN:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY_WIN);
        rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
        rgblight_sethsv(187, 191, 191);
      }
      return false;
      break;
    case QWE_MAC:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY_MAC);
        rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
        rgblight_sethsv(135, 191, 191);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}

const rgblight_segment_t PROGMEM rgblight_layer_lower[] = RGBLIGHT_LAYER_SEGMENTS(
    {10, 2, 0, 0, 191}
);

const rgblight_segment_t PROGMEM rgblight_layer_raise[] = RGBLIGHT_LAYER_SEGMENTS(
    {12, 2, 0, 0, 191}
);

const rgblight_segment_t PROGMEM rgblight_layer_capslock[] = RGBLIGHT_LAYER_SEGMENTS(
    {4, 1, 0, 0, 191}
);

const rgblight_segment_t* const PROGMEM my_rgblight_layers[] = RGBLIGHT_LAYERS_LIST(
    rgblight_layer_lower,
    rgblight_layer_raise,
    rgblight_layer_capslock
);

void keyboard_post_init_user(void) {rgblight_layers = my_rgblight_layers;}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _LOWER));
    rgblight_set_layer_state(1, layer_state_cmp(state, _RAISE));
    return state;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(2, led_state.caps_lock);
    return true;
}
