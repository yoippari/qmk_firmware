#ifndef YOIPPARI_COMMON_H
#define YOIPPARI_COMMON_H

/* Custom keys & combinations to be shorter for keymaps */
#define KC_LCA LCA(KC_NO)
/* Fillers to make layering more clear */
#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define TD_CTL TD(TD_CTL_CTLALT)
#define TD_ALT TD(TD_LALT_RALT)
#define MT_ENT SFT_T(KC_ENT)

/* Custom layer movements for keymaps */
#define TD_ADJ  TD(TD_ADJUST)
#define TO_GAME TO(_GAME)
#define MO_ADJ  MO(_ADJUST)

/*
 * This will expand values sent to it to send to the KEYMAP macro so defines
 * can be used by KEYMAP
 */
#define CATMAP(...) LAYOUT(__VA_ARGS__)

/*
  Each layer gets a name for readability, which is then used in the keymap matrix below.
  The underscores don't mean anything - you can have a layer called STUFF or any other name.
  Layer names don't all need to be of the same length, obviously, and you can also skip them
  entirely and just use numbers.
*/
#define _QWERTY  0
#define _COLEMAK 1
#define _WORKMAN 2
#define _DVORAK  3
#define _GAME    4
#define _LOWER  14
#define _FN  15
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  WORKMAN,
  DVORAK,
  LOWER,
  FN,
};

#endif
