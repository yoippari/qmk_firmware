#ifndef YOIPPARI_KEYMAP_H
#define YOIPPARI_KEYMAP_H

#include "action_layer.h"
#include "eeconfig.h"
#include "YOIPPARI-common.h"

/* Tap dance keycodes */
enum tap_dance_keycodes {
  TD_CTL_CTLALT = 0,
  TD_LALT_RALT,
};

/*
  Used to indicate a CTRL should be pressed on one press, or CTRL+ALT on
  a double tap
*/
void dance_ctl_ctlalt_each(qk_tap_dance_state_t *state, void *user_data) {
  register_code(KC_LCTL);
  if(state->count > 1) {
    register_code(KC_LALT);
  }
}

/* Used to release CTRL or the double tapped variant CTRL+ALT */
void dance_ctl_ctlalt_reset(qk_tap_dance_state_t *state, void *user_data) {
  unregister_code(KC_LCTL);
  if(state->count > 1) {
    unregister_code(KC_LALT);
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_CTL_CTLALT] = ACTION_TAP_DANCE_FN_ADVANCED(dance_ctl_ctlalt_each, NULL, dance_ctl_ctlalt_reset),
  [TD_LALT_RALT]  = ACTION_TAP_DANCE_DOUBLE(KC_LALT, KC_RALT),
};

/*
 * ,-----------------------------------------..-----------------------------------------.
 * |  OS  | PgUp | PgDn | Alt  | FN   | SPACE|| SPACE/LOWER | Left | Down |  Up  |Right |
 * `-----------------------------------------'`-----------------------------------------'
 */
#define BOTTOM_GRID_ROW \
  KC_LGUI , KC_PGUP, KC_PGDN, KC_LALT, FN  , KC_SPC , LT(_LOWER, KC_SPC) , LT(_LOWER, KC_SPC)  , KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT



/*
 * ,-----------------------------------------..-----------------------------------------.
 * | Tab  |                                  ||                                  |  -   |
 * `-----------------------------------------'`-----------------------------------------'
 */
#define STD_TAB_ROW(...) KC_TAB, __VA_ARGS__, KC_MINS

/*
 * ,-----------------------------------------..-----------------------------------------.
 * | Ctrl |                                  ||                                  |  '   |
 * `-----------------------------------------'`-----------------------------------------'
 */

#define STD_CTRL_ROW(...) KC_LCTL, __VA_ARGS__, KC_QUOT

/*
 * ,-----------------------------------------..-----------------------------------------.
 * | Shift|                                  ||                                  |Enter |
 * `-----------------------------------------'`-----------------------------------------'
 */
#define STD_LSFT_ROW(...) KC_LSFT, __VA_ARGS__, MT_ENT

/* Qwerty
 * ,-----------------------------------------..-----------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  ||   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * | CTRL |   A  |   S  |   D  |   F  |   G  ||   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  ||   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |  OS  | PgUp | PgDn | Alt  | FN   | SPACE|| SPACE/LOWER | Left | Down |  Up  |Right |
 * `-----------------------------------------'`-----------------------------------------'
 */
#define QWERTY_LAYER \
  STD_TAB_ROW( KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P     ), \
  STD_CTRL_ROW( KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN ), \
  STD_LSFT_ROW(KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH  ),  \
  BOTTOM_GRID_ROW

/* Colemak
 * ,-----------------------------------------.,-----------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  ||   J  |   L  |   U  |   Y  |   ;  |  -   |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * | CTRL |   A  |   R  |   S  |   T  |   D  ||   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  ||   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |  OS  | PgUp | PgDn | Alt  | FN   | SPACE|| SPACE/LOWER | Left | Down |  Up  |Right |
 * `-----------------------------------------'`-----------------------------------------'
 */
#define COLEMAK_LAYER \
  STD_TAB_ROW( KC_Q   , KC_W   , KC_F   , KC_P   , KC_G   , KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN), \
  STD_CTRL_ROW( KC_A   , KC_R   , KC_S   , KC_T   , KC_D   , KC_H   , KC_N   , KC_E   , KC_I   , KC_O  ), \
  STD_LSFT_ROW(KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_K   , KC_M   , KC_COMM, KC_DOT , KC_SLSH), \
  BOTTOM_GRID_ROW

/* Workman
 * ,-----------------------------------------..-----------------------------------------.
 * | Tab  |   Q  |   D  |   R  |   W  |   B  ||   J  |   F  |   U  |   P  |   ;  |  -   |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * | CTRL |   A  |   S  |   H  |   T  |   G  ||   Y  |   N  |   E  |   O  |   I  |  "   |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   M  |   C  |   V  ||   K  |   L  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |  OS  | PgUp | PgDn | Alt  | FN   | SPACE|| SPACE/LOWER | Left | Down |  Up  |Right |
 * `-----------------------------------------'`-----------------------------------------'
 */
#define WORKMAN_LAYER \
  STD_TAB_ROW( KC_Q   , KC_D   , KC_R   , KC_W   , KC_B   , KC_J   , KC_F   , KC_U   , KC_P   , KC_SCLN), \
  STD_CTRL_ROW( KC_A   , KC_S   , KC_H   , KC_T   , KC_G   , KC_Y   , KC_N   , KC_E   , KC_O   , KC_I  ), \
  STD_LSFT_ROW(KC_Z   , KC_X   , KC_M   , KC_C   , KC_V   , KC_K   , KC_L   , KC_COMM, KC_DOT , KC_SLSH), \
  BOTTOM_GRID_ROW

/* Dvorak
 * ,-----------------------------------------..-----------------------------------------.
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  ||   F  |   G  |   C  |   R  |   L  |  /   |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * | CTRL |   A  |   O  |   E  |   U  |   I  ||   D  |   H  |   T  |   N  |   S  |  -   |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  ||   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |  OS  | PgUp | PgDn | Alt  | FN   | SPACE|| SPACE/LOWER | Left | Down |  Up  |Right |
 * `-----------------------------------------'`-----------------------------------------'
 */
#define DVORAK_LAYER \
  KC_TAB  , KC_QUOT, KC_COMM, KC_DOT , KC_P   , KC_Y   , KC_F   , KC_G   , KC_C   , KC_R   , KC_L,  KC_SLSH  , \
  TD_CTL, KC_A   , KC_O   , KC_E   , KC_U   , KC_I   , KC_D   , KC_H   , KC_T   , KC_N   , KC_S , KC_MINS , \
  STD_LSFT_ROW(KC_SCLN, KC_Q   , KC_J   , KC_K   , KC_X   , KC_B   , KC_M   , KC_W   , KC_V   , KC_Z),         \
  BOTTOM_GRID_ROW

/* Game (Qwerty without one shot modifiers & tap dancing)
 * ,-----------------------------------------..-----------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  ||   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * | CTRL |   A  |   S  |   D  |   F  |   G  ||   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  ||   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * | GUI  | PGUP | PGDN | ALT  |  FN  |SPACE || Space/LOWER | Left | Down |  Up  |Right |
 * `-----------------------------------------'`-----------------------------------------'
 */
#define GAME_LAYER \
  KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_MINS, \
  KC_LCTL , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_ENT , \
  KC_LGUI , KC_PGUP, KC_PGDN, KC_LALT, FN  , KC_SPC , LT(_LOWER, KC_SPC) , LT(_LOWER, KC_SPC)  , KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT

/* Lower
 * ,-----------------------------------------..-----------------------------------------.
 * |      |      |      |      |      |      || NLCK |   7  |   8  |   9  |   *  | BKSP |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |      |      |   [  |   ]  |   |  | HOME || PGUP |   4  |   5  |   6  |   +  |  -   |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * | CTRL |      |      |      |  = + | END  || PGDN |   1  |   2  |   3  |      |  =   |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * | SHIFT|      |      |      |      |      ||      |   0  |   ,  |   .  |   /  |  ENT |
 * |------+------+------+------+------+------||------+------+------+------+------+------|
 * |  OS  | HOME | END  | Alt  | FN   | SPACE|| SPACE/LOWER | Left | Down |  Up  |Right |
 * `-----------------------------------------'`-----------------------------------------'
 */
#define LOWER_LAYER \
  KC_TILD     , KC_NO  , KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NLCK  , KC_KP_7  , KC_KP_8  , KC_KP_9  , KC_PAST , KC_BSPC  , \
  KC_NO       , KC_NO  , KC_LBRC  , KC_RBRC  , KC_BSLS  , KC_HOME  , KC_PGUP  , KC_KP_4  , KC_KP_5  , KC_KP_6  , KC_PPLS , KC_PMNS  , \
  KC_LCTL     , KC_NO  , KC_NO    , KC_NO    , KC_EQL   , KC_END   , KC_PGDN  , KC_KP_1  , KC_KP_2  , KC_KP_3  , KC_NO   , KC_PEQL , \
  STD_LSFT_ROW( KC_NO  , KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_KP_0  , KC_COMM  , KC_DOT   , KC_PSLS) ,       \
  KC_LGUI     ,KC_HOME , KC_END   , KC_LALT  , _______  , KC_SPC   , _______  , _______  , KC_LEFT  , KC_DOWN  , KC_UP    , KC_RGHT

/* FN
*,------+------+------+------+------+------||------+------+------+------+------+------.
*|      |  F1  |  F2  |  F3  |  F4  |      || Vol+ |      | PSCR | PAUSE|      |  DEL |
*|------+------+------+------+------+------||------+------+------+------+------+------|
*| Ctrl |  F5  |  F6  |  F7  |  F8  |      || Vol- |      |      |      |      |  INS |
*|------+------+------+------+------+------||------+------+------+------+------+------|
*| Shift|  F9  |  F10 |  F11 |  F12 |      || Mute |      |      |      |      |      |
*|------+------+------+------+------+------||------+------+------+------+------+------|
*| GUI  | HOME | END  | ALT  |      | SPACE||   Space     | Left | Down |  Up  |Right |
*`-----------------------------------------''-----------------------------------------'
*/
#define FN_LAYER \
  KC_NO   , KC_F1  , KC_F2   , KC_F3    , KC_F4   , KC_NO  , KC_VOLU, KC_NO  ,KC_PSCR   ,KC_PAUS   ,KC_NO   ,KC_DEL  ,\
  KC_LCTL , KC_F5  , KC_F6   , KC_F7    , KC_F8   , KC_NO  , KC_VOLD, KC_NO  ,KC_NO   ,KC_NO   ,KC_NO   ,KC_INS   ,\
  KC_LSFT , KC_F9  , KC_F10  ,  KC_F11  , KC_F12  , KC_NO  , KC_MUTE, KC_NO  ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,\
  KC_LGUI ,KC_HOME , KC_END  , KC_LALT  , _______ , _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT


#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
float tone_workman[][2]    = SONG(PLOVER_SOUND);
#else
float tone_qwerty;
float tone_dvorak;
float tone_colemak;
float tone_workman;
#define PLAY_SONG(tone)
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  layer_state_set(default_layer);
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        PLAY_SONG(tone_qwerty);
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        PLAY_SONG(tone_colemak);
        persistent_default_layer_set(1UL<<_COLEMAK);
      }
      return false;
      break;
    case WORKMAN:
      if (record->event.pressed) {
        PLAY_SONG(tone_workman);
        persistent_default_layer_set(1UL<<_WORKMAN);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        PLAY_SONG(tone_dvorak);
        persistent_default_layer_set(1UL<<_DVORAK);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _FN, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _FN, _ADJUST);
      }
      return false;
      break;
    case FN:
      if (record->event.pressed) {
        layer_on(_FN);
        update_tri_layer(_LOWER, _FN, _ADJUST);
      } else {
        layer_off(_FN);
        update_tri_layer(_LOWER, _FN, _ADJUST);
      }
      return false;
      break;
  }

  return true;
}

#endif
