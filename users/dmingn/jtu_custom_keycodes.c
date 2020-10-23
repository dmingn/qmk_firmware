#include QMK_KEYBOARD_H
#include "keymap_jp.h"
#include "jtu_custom_keycodes.h"

#define TAP(keycode) tap_code(keycode);
#define SHIFT_TAP(keycode)  \
    register_code(KC_LSFT); \
    tap_code(keycode);      \
    unregister_code(KC_LSFT);
#define CASE(keycode_ju, action, action_shift)                 \
    case keycode_ju:                                           \
        if (record->event.pressed) {                           \
            lshift = keyboard_report->mods & MOD_BIT(KC_LSFT); \
            rshift = keyboard_report->mods & MOD_BIT(KC_RSFT); \
            if (lshift || rshift) {                            \
                if (lshift) unregister_code(KC_LSFT);          \
                if (rshift) unregister_code(KC_RSFT);          \
                action_shift;                                  \
                if (lshift) register_code(KC_LSFT);            \
                if (rshift) register_code(KC_RSFT);            \
            } else {                                           \
                action;                                        \
            }                                                  \
        }                                                      \
        return false;

bool process_record_user_jtu(uint16_t keycode, keyrecord_t *record) {
    static bool lshift = false;
    static bool rshift = false;

    switch (keycode) {
        CASE(JU_2, TAP(JP_2), TAP(JP_AT))
        CASE(JU_6, TAP(JP_6), TAP(JP_CIRC))
        CASE(JU_7, TAP(JP_7), SHIFT_TAP(JP_6))
        CASE(JU_8, TAP(JP_8), SHIFT_TAP(JP_COLN))
        CASE(JU_9, TAP(JP_9), SHIFT_TAP(JP_8))
        CASE(JU_0, TAP(JP_0), SHIFT_TAP(JP_9))
        CASE(JU_MINS, TAP(JP_MINS), SHIFT_TAP(JP_BSLS))
        CASE(JU_EQL, SHIFT_TAP(JP_MINS), SHIFT_TAP(JP_SCLN))
        CASE(JU_LBRC, TAP(JP_LBRC), SHIFT_TAP(JP_LBRC))
        CASE(JU_RBRC, TAP(JP_RBRC), SHIFT_TAP(JP_RBRC))
        CASE(JU_BSLS, TAP(JP_BSLS), SHIFT_TAP(JP_YEN))
        CASE(JU_SCLN, TAP(JP_SCLN), TAP(JP_COLN))
        CASE(JU_QUOT, SHIFT_TAP(JP_7), SHIFT_TAP(JP_2))
        CASE(JU_GRV, SHIFT_TAP(JP_AT), SHIFT_TAP(JP_CIRC))
        case JU_CAPS:
            if (record->event.pressed) {
                SHIFT_TAP(JP_EISU);
            }
            return false;
    }
    return true;
}
