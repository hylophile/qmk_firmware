#include QMK_KEYBOARD_H

#define COLEMAK_DH 0
#define NUM_LAYER 1
#define SYM_RIGHT 2
#define SYM_LEFT 3
#define UMLAUTS 4

#define ________ KC_TRANSPARENT

// Left-hand home row mods
#define HOME_R LALT_T(KC_R)
#define HOME_S LSFT_T(KC_S)
#define HOME_T LCTL_T(KC_T)
#define HOME_G LGUI_T(KC_G)

// Right-hand home row mods
#define HOME_M LGUI_T(KC_M)
#define HOME_N RCTL_T(KC_N)
#define HOME_E RSFT_T(KC_E)
#define HOME_I LALT_T(KC_I)

/* #define A_D SEND_STRING(SS_TAP(X_RGUI)"a\"") */
/* #define A_D SEND_STRING("avoien") */

#define M_COMPOSE X_RGUI
#define COMPOSE KC_RGUI

enum custom_keycodes {
    A_D = SAFE_RANGE,
    O_D,
    U_D,
    ESZ,
    CTRLCC,
    CTRLCK,
    CTRLCQUOTE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case A_D:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(M_COMPOSE)"a\"");
            /* SEND_STRING("QMK is the best thing ever!"); */
        } else {
            // when keycode QMKBEST is released
        }
        break;
    case O_D:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(M_COMPOSE)"o\"");
        }
        break;
    case U_D:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(M_COMPOSE)"u\"");
        }
        break;
    case ESZ:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(M_COMPOSE)"ss");
        }
    case CTRLCC:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL("cc"));
        }
        break;
    case CTRLCK:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL("ck"));
        }
        break;
    case CTRLCQUOTE:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL("c"));
            SEND_STRING("'");
        }
        break;
    }
    return true;
};
enum unicode_names {
    A_DIAE_CAP,
    A_DIAE,
    O_DIAE_CAP,
    O_DIAE,
    U_DIAE_CAP,
    U_DIAE,
    SHARP_S
};

const uint32_t PROGMEM unicode_map[] = {
    [A_DIAE_CAP]  = 0x00C4,
    [A_DIAE]  = 0x00E4,
    [O_DIAE_CAP]  = 0x00D6,
    [O_DIAE]  = 0x00F6,
    [U_DIAE_CAP]  = 0x00DC,
    [U_DIAE]  = 0x00FC,
    [SHARP_S]  = 0x00DF,
};
/****************************************************************************************************

* Keymap: Default Layer in Qwerty
*
* ,-------------------------------------------------------------------------------------------------------------------.
* | Esc    |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F8  |  F9  |  F10 |  F12 | PSCR | SLCK | PAUS |  FN0 |  BOOT  |
* |--------+------+------+------+------+------+---------------------------+------+------+------+------+------+--------|
* | =+     |  1!  |  2@  |  3#  |  4$  |  5%  |                           |  6^  |  7&  |  8*  |  9(  |  0)  | -_     |
* |--------+------+------+------+------+------|                           +------+------+------+------+------+--------|
* | Tab    |   Q  |   W  |   E  |   R  |   T  |                           |   Y  |   U  |   I  |   O  |   P  | \|     |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | Caps   |   A  |   S  |   D  |   F  |   G  |                           |   H  |   J  |   K  |   L  |  ;:  | '"     |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | Shift  |   Z  |   X  |   C  |   V  |   B  |                           |   N  |   M  |  ,.  |  .>  |  /?  | Shift  |
* `--------+------+------+------+------+-------                           `------+------+------+------+------+--------'
*          | `~   | INS  | Left | Right|                                         | Up   | Down |  [{  |  ]}  |
*          `---------------------------'                                         `---------------------------'
*                                        ,-------------.         ,-------------.
*                                        | Ctrl | Alt  |         | Gui  | Ctrl |
*                                 ,------|------|------|         |------+------+------.
*                                 |      |      | Home |         | PgUp |      |      |
*                                 | BkSp | Del  |------|         |------|Return| Space|
*                                 |      |      | End  |         | PgDn |      |      |
*                                 `--------------------'         `--------------------'
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[COLEMAK_DH] = LAYOUT(

KC_MAIL,                 KC_F1,                    KC_F2,           KC_F3,            KC_F4,                 KC_F5,                     KC_F6,                   KC_F7,         KC_F8,
KC_EQL,                  KC_1,                     KC_2,            KC_3,             KC_4,                  KC_5,
KC_TAB,                  KC_Q,                     KC_W,            KC_F,             KC_P,                  KC_B,
KC_DEL,                  KC_A,                     HOME_R,          HOME_S,           HOME_T,                  HOME_G,
OSL(UMLAUTS),            KC_Z,                     KC_X,            KC_C,             KC_D,                  KC_V,
KC_LEFT,                 KC_DOWN,                  KC_UP,           KC_RIGHT,
OSL(SYM_RIGHT),          KC_MS_BTN3,
LSFT(KC_INSERT),
/* LCTL_T(KC_BSPC),         LALT_T(KC_ESC),           KC_F21, */
KC_BSPC,                 KC_ESC,                   KC_F21,

KC_F9,                   KC_F10,                   KC_F11,          KC_F12,           KC_AUDIO_MUTE,         KC_AUDIO_VOL_DOWN,         KC_AUDIO_VOL_UP,         COMPOSE,       RESET,
KC_6,                    KC_7,                     KC_8,            KC_9,             KC_0,                  KC_MINUS,
KC_J,                    KC_L,                     KC_U,            KC_Y,             KC_SEMICOLON,          KC_BACKSLASH,
HOME_M,                  HOME_N,                   HOME_E,          HOME_I,           KC_O,                  KC_QUOTE,
KC_K,                    KC_H,                     KC_COMMA,        KC_DOT,           KC_SLASH,              OSL(UMLAUTS),
/* KC_LEFT,                 KC_DOWN,                  KC_UP,           KC_RIGHT, */
________,                ________,                 ________,        ________,
KC_CAPS_LOCK,            OSL(SYM_LEFT),
KC_F23,
/* COMPOSE,                 LALT_T(KC_ENTER),         LCTL_T(KC_SPC) */
COMPOSE,                 KC_ENTER,                 KC_SPC

    ),

[SYM_LEFT] = LAYOUT(



________,         ________,         ________,         ________,         ________,         ________,         ________,         ________,         ________,
________,         ________,         ________,         ________,         ________,         ________,
________,         ________,         KC_UNDERSCORE,    KC_LEFT_BRACKET,  KC_RIGHT_BRACKET, KC_CIRCUMFLEX,
________,         KC_BACKSLASH,     KC_SLASH,         KC_LCBR,          KC_RCBR,          KC_ASTR,
________,         KC_HASH,          KC_DOLLAR,        KC_PIPE,          KC_TILDE,         KC_GRAVE,
________,         ________,         ________,         ________,
________,         ________,
________,
________,         ________,         ________,

________,         ________,         ________,         ________,         ________,         ________,         ________,         ________,         ________,
________,         ________,         ________,         ________,         ________,         ________,
________,         ________,         ________,         ________,         ________,         ________,
________,         ________,         ________,         ________,         ________,         ________,
________,         ________,         ________,         ________,         ________,         ________,
________,         ________,         ________,         ________,
________,         ________,
________,
________,         ________,         ________

    ),

[SYM_RIGHT] = LAYOUT(

________,         ________,         ________,         ________,         ________,         ________,         ________,         ________,         ________,
________,         ________,         ________,         ________,         ________,         ________,
________,         ________,         ________,         ________,         ________,         ________,
________,         ________,         ________,         ________,         ________,         ________,
________,         ________,         ________,         ________,         ________,         ________,
________,         ________,         ________,         ________,
________,         ________,
________,
________,         ________,         ________,

________,         ________,         ________,         ________,         ________,         ________,         ________,         ________,         ________,
________,         ________,         ________,         ________,         ________,         ________,
KC_EXCLAIM,       KC_LABK,          KC_RABK,          KC_EQUAL,         KC_AMPERSAND,     ________,
KC_QUESTION,      KC_LEFT_PAREN,    KC_RIGHT_PAREN,   KC_MINUS,         KC_COLON,         KC_AT,
KC_PLUS,          KC_PERCENT,       KC_DOUBLE_QUOTE,  KC_QUOTE,         KC_SEMICOLON,     ________,
________,         ________,         ________,         ________,
________,         ________,
________,
________,         ________,         ________

    ),

[UMLAUTS] = LAYOUT(

________,         ________,         ________,         ________,         ________,         ________,         ________,         ________,         ________,
________,         ________,         ________,         ________,         ________,         ________,
________,         ________,         ________,         ________,         ________,         ________,
________,         A_D,              ________,         ESZ,              ________,         ________,
________,         ________,         ________,         CTRLCC,           CTRLCK,           CTRLCQUOTE,
________,         ________,         ________,         ________,
________,         ________,
________,
________,         ________,         ________,

________,         ________,         ________,         ________,         ________,         ________,         ________,         ________,         ________,
________,         ________,         ________,         ________,         ________,         ________,
________,         ________,         U_D,              ________,         ________,         ________,
________,         ________,         ________,         ________,         O_D,              ________,
________,         ________,         ________,         ________,         ________,         ________,
________,         ________,         ________,         ________,
________,         ________,
________,
________,         ________,         ________

    ),

[16] = LAYOUT(

________,         ________,         ________,         ________,         ________,         ________,         ________,         ________,         ________,
________,         ________,         ________,         ________,         ________,         ________,
________,         ________,         ________,         ________,         ________,         ________,
________,         ________,         ________,         ________,         ________,         ________,
________,         ________,         ________,         ________,         ________,         ________,
________,         ________,         ________,         ________,
________,         ________,
________,
________,         ________,         ________,

________,         ________,         ________,         ________,         ________,         ________,         ________,         ________,         ________,
________,         ________,         ________,         ________,         ________,         ________,
________,         ________,         ________,         ________,         ________,         ________,
________,         ________,         ________,         ________,         ________,         ________,
________,         ________,         ________,         ________,         ________,         ________,
________,         ________,         ________,         ________,
________,         ________,
________,
________,         ________,         ________

    )
};

// Local Variables:
// eval: (apheleia-mode -1)
// End:
