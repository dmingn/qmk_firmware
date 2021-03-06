#include QMK_KEYBOARD_H
#include "keymap_jp.h"
#include "jtu_custom_keycodes.h"


#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
  _BASE = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes {
  RGBRST = JTU_SAFE_RANGE,
  LOWER,
  RAISE,
};

// enum tapdances{
//   TD_CODO = 0,
//   TD_SLRO,
// };

// Base layer mod tap
#define JP_A_SF  LSFT_T(JP_A)
#define JP_Z_CT  LCTL_T(JP_Z)
#define JP_X_GU  LGUI_T(JP_X)
#define JP_C_AL  LALT_T(JP_C)
#define JP_SSCT  RCTL_T(JP_SLSH)
#define KC_BSSF  RSFT_T(KC_BSPC)

// Lower layer mod tap
#define KC_F6SF  LSFT_T(KC_F6)
#define KC_DLSF  RSFT_T(KC_DEL)
#define KC_11CT  LCTL_T(KC_F11)
#define KC_12GU  LGUI_T(KC_F12)
#define KC_ESAL  LALT_T(KC_ESC)

// Layer tap
#define KC_SPLO  LT(_LOWER, KC_SPC)
#define KC_ENRA  LT(_RAISE, KC_ENT)

// Tap dance
// #define KC_CODO  TD(TD_CODO)
// #define KC_SLRO  TD(TD_SLRO)

// qk_tap_dance_action_t tap_dance_actions[] = {
//   [TD_CODO] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_DOT),
//   [TD_SLRO] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_RO),
// };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
  //,---------------------------------------------------------------------------------------------------.
          JP_Q,     JP_W,     JP_E,     JP_R,     JP_T,     JP_Y,     JP_U,     JP_I,     JP_O,     JP_P,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       JP_A_SF,     JP_S,     JP_D,     JP_F,     JP_G,     JP_H,     JP_J,     JP_K,     JP_L,  KC_BSSF,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       JP_Z_CT,  JP_X_GU,  JP_C_AL,     JP_V,     JP_B,     JP_N,     JP_M,  JP_COMM,   JP_DOT,  JP_SSCT,
  //`---------+---------+---------+---------+---------+---------+---------+---------+---------+---------'
                                               KC_SPLO,  KC_ENRA
  //                                        `---------|---------'
  ),

  [_LOWER] = LAYOUT(
  //,---------------------------------------------------------------------------------------------------.
       KC_EXLM,  JP_DQUO,  KC_HASH,   KC_DLR,  KC_PERC,  JP_AMPR,  JU_QUOT,  JP_LPRN,  JP_RPRN,  KC_MINS,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
        JU_GRV,    JP_AT,  JP_CIRC,   JU_EQL,  XXXXXXX,  JU_SCLN,  KC_COLN,  JU_LBRC,  JU_RBRC,  KC_DLSF,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       JP_PIPE,  JP_TILD,  JP_PLUS,  JP_ASTR,  JP_MHEN,  XXXXXXX,  JU_BSLS,  JP_LCBR,  JP_RCBR,  JP_UNDS,
  //`---------+---------+---------+---------+---------+---------+---------+---------+---------+---------'
                                                 LOWER,    RAISE
  //                                        `---------|---------'
  ),

  [_RAISE] = LAYOUT(
  //,---------------------------------------------------------------------------------------------------.
          KC_1,     JU_2,     KC_3,     KC_4,     KC_5,     JU_6,     JU_7,     JU_8,     JU_9,     JU_0,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       KC_LSFT,  KC_HOME,  KC_PGDN,  KC_PGUP,   KC_END,  KC_LEFT,  KC_DOWN,    KC_UP,  KC_RGHT,  KC_DLSF,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       KC_LCTL,  KC_LGUI,  KC_ESAL,   KC_TAB,  XXXXXXX,  JP_HENK,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_RCTL,
  //`---------+---------+---------+---------+---------+---------+---------+---------+---------+---------'
                                                 LOWER,    RAISE
  //                                        `---------|---------'
  ),

  [_ADJUST] = LAYOUT(
  //,---------------------------------------------------------------------------------------------------.
         KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,   KC_F10,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
         RESET,  RGB_TOG,  RGB_HUI,  RGB_SAI,  RGB_VAI,  XXXXXXX,  XXXXXXX,  XXXXXXX,   KC_F11,   KC_F12,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
        RGBRST,  RGB_MOD,  RGB_HUD,  RGB_SAD,  RGB_VAD,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_PSCR,
  //`---------+---------+---------+---------+---------+---------+---------+---------+---------+---------'
                                                 LOWER,    RAISE
  //                                        `---------|---------'
  )
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_SPLO:
      return TAPPING_LAYER_TERM;
    case KC_ENRA:
      return TAPPING_LAYER_TERM;
    default:
      return TAPPING_TERM;
  }
}

int RGB_current_mode;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  bool continue_process = process_record_user_jtu(keycode, record);
  if (continue_process == false) {
    return false;
  }

  bool result = false;
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      result = false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      result = false;
      break;
    #ifdef RGBLIGHT_ENABLE
      //led operations - RGB mode change now updates the RGB_current_mode to allow the right RGB mode to be set after reactive keys are released
      case RGB_MOD:
          if (record->event.pressed) {
            rgblight_mode(RGB_current_mode);
            rgblight_step();
            RGB_current_mode = rgblight_config.mode;
          }
        break;
      case RGBRST:
          if (record->event.pressed) {
            eeconfig_update_rgblight_default();
            rgblight_enable();
            RGB_current_mode = rgblight_config.mode;
          }
        break;
    #endif
    default:
      result = true;
      break;
  }

  return result;
}

void keyboard_post_init_user(void) {
  #ifdef RGBLIGHT_ENABLE
    RGB_current_mode = rgblight_config.mode;
  #endif
}
