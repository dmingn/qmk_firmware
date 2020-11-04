#include QMK_KEYBOARD_H
#include "keymap_jp.h"


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
  RGBRST = SAFE_RANGE,
  LOWER,
  RAISE,
};

// enum tapdances{
//   TD_CODO = 0,
//   TD_SLRO,
// };

// Layer Mode aliases
#define KC_MLAD  MO(_ADJUST)

// Base layer mod tap
#define JP_A_SF  LSFT_T(JP_A)
#define JP_Z_CT  LCTL_T(JP_Z)
#define JP_X_AL  LALT_T(JP_X)
#define JP_C_GU  LGUI_T(JP_C)
#define JP_SSCT  RCTL_T(JP_SLSH)
#define KC_BSSF  RSFT_T(KC_BSPC)

// Lower layer mod tap
#define KC_F6SF  LSFT_T(KC_F6)
#define KC_DLSF  RSFT_T(KC_DEL)
#define KC_11CT  LCTL_T(KC_F11)
#define KC_12AL  LALT_T(KC_F12)

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
       JP_Z_CT,  JP_X_AL,  JP_C_GU,     JP_V,     JP_B,     JP_N,     JP_M,  JP_COMM,   JP_DOT,  JP_SSCT,
  //`---------+---------+---------+---------+---------+---------+---------+---------+---------+---------'
                                               KC_SPLO,  KC_ENRA
  //                                        `---------|---------'
  ),

  [_LOWER] = LAYOUT(
  //,---------------------------------------------------------------------------------------------------.
         KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,  JP_MINS,  JP_CIRC,   JP_YEN,    JP_AT,  JP_LBRC,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       KC_F6SF,    KC_F7,    KC_F8,    KC_F9,   KC_F10,  XXXXXXX,  JP_SCLN,  JP_COLN,  JP_RBRC,  KC_DLSF,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       KC_11CT,  KC_12AL,   KC_ESC,   KC_TAB,  JP_MHEN,  JP_HENK,  XXXXXXX,  XXXXXXX,  XXXXXXX,  JP_BSLS,
  //`---------+---------+---------+---------+---------+---------+---------+---------+---------+---------'
                                               _______,  KC_MLAD
  //                                        `---------|---------'
  ),

  [_RAISE] = LAYOUT(
  //,---------------------------------------------------------------------------------------------------.
          JP_1,     JP_2,     JP_3,     JP_4,     JP_5,     JP_6,     JP_7,     JP_8,     JP_9,     JP_0,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       KC_LSFT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_LEFT,  KC_DOWN,    KC_UP,  KC_RGHT,  KC_DLSF,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       KC_LCTL,  KC_LALT,  KC_LGUI,  XXXXXXX,  XXXXXXX,  KC_MINS,    KC_RO,  KC_COMM,   KC_DOT,  JP_SSCT,
  //`---------+---------+---------+---------+---------+---------+---------+---------+---------+---------'
                                               _______,  _______
  //                                        `---------|---------'
  ),

  [_ADJUST] = LAYOUT(
  //,---------------------------------------------------------------------------------------------------.
        RESET,    RGBRST,  AG_NORM,  AG_SWAP,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   KC_INS,  KC_PSCR,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       RGB_TOG,  RGB_HUI,  RGB_SAI,  RGB_VAI,  XXXXXXX,  KC_MS_L,  KC_MS_D,  KC_MS_U,  KC_MS_R,  KC_NLCK,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       RGB_MOD,  RGB_HUD,  RGB_SAD,  RGB_VAD,  XXXXXXX,  KC_BTN1,  KC_BTN2,  XXXXXXX,  XXXXXXX,  XXXXXXX,
  //`---------+---------+---------+---------+---------+---------+---------+---------+---------+---------'
                                               _______,  _______
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

  bool result = false;
  switch (keycode) {
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
