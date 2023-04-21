#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum ferris_layers {
  L_BASE,
  L_NAV,
  L_SYM,
  L_NUM,
  L_FUN,
  L_SYS,
};

enum ferris_keycodes {
  GUI_TAB = SAFE_RANGE,
  GUI_GRV,
};

bool tabbing = false;

// Layer-Taps
#define NAV_TAB  LT(L_NAV, KC_TAB)
#define SYM_SPC  LT(L_SYM, KC_SPC)
#define NUM_BSPC LT(L_NUM, KC_BSPC)
#define FUN_ENT  LT(L_FUN, KC_ENT)

// Mod-Taps
#define CTL_A    MT(MOD_LCTL, KC_A)
#define ALT_S    MT(MOD_LALT, KC_S)
#define GUI_D    MT(MOD_LGUI, KC_D)
#define SFT_F    MT(MOD_LSFT, KC_F)
#define SFT_J    MT(MOD_RSFT, KC_J)
#define GUI_K    MT(MOD_RGUI, KC_K)
#define ALT_L    MT(MOD_RALT, KC_L)
#define CTL_SCLN MT(MOD_RCTL, KC_SCLN)

// Combos
const uint16_t PROGMEM combo_escape[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM combo_delete[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM combo_caps_word[] = {SFT_F, SFT_J, COMBO_END};
const uint16_t PROGMEM combo_sys_layer[] = {NAV_TAB, SYM_SPC, COMBO_END};
const uint16_t PROGMEM combo_right_brace[] = {KC_LCBR, KC_BSLS, COMBO_END};
const uint16_t PROGMEM combo_right_paren[] = {KC_LPRN, KC_SLSH, COMBO_END};
const uint16_t PROGMEM combo_right_bracket[] = {KC_LBRC, KC_PIPE, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo_escape, KC_ESC),
    COMBO(combo_delete, KC_DEL),
    COMBO(combo_caps_word, CAPS_WORD),
    COMBO(combo_sys_layer, MO(L_SYS)),
    COMBO(combo_right_brace, KC_RCBR),
    COMBO(combo_right_paren, KC_RPRN),
    COMBO(combo_right_bracket, KC_RBRC),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[L_BASE] = LAYOUT(
KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,  /**/  KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   ,
CTL_A  , ALT_S  , GUI_D  , SFT_F  , KC_G   ,  /**/  KC_H   , SFT_J  , GUI_K  , ALT_L  , CTL_SCLN,
KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,  /**/  KC_N   , KC_M   , KC_COMM, KC_DOT , KC_QUOT,
                           NAV_TAB, SYM_SPC,  /**/  NUM_BSPC, FUN_ENT
),

[L_NAV] = LAYOUT(
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  /**/  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, XXXXXXX,  /**/  KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, XXXXXXX,
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  /**/  KC_HOME, KC_PGDN, KC_PGUP, KC_END , XXXXXXX,
                           XXXXXXX, XXXXXXX,  /**/  GUI_TAB, GUI_GRV
),

[L_SYM] = LAYOUT(
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  /**/  KC_PERC, KC_LCBR, KC_BSLS, KC_CIRC, KC_DLR ,
KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, XXXXXXX,  /**/  KC_GRV , KC_LPRN, KC_SLSH, KC_QUES, KC_EXLM,
XXXXXXX, XXXXXXX, XXXXXXX, KC_TILD, XXXXXXX,  /**/  KC_HASH, KC_LBRC, KC_PIPE, KC_AMPR, KC_AT  ,
                           XXXXXXX, XXXXXXX,  /**/  KC_UNDS, KC_MINS
),

[L_NUM] = LAYOUT(
KC_PLUS, KC_MINS, KC_ASTR, KC_SLSH, KC_EQL ,  /**/  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
KC_0   , KC_1   , KC_2   , KC_3   , KC_4   ,  /**/  XXXXXXX, KC_RSFT, KC_RGUI, KC_RALT, KC_RCTL,
KC_5   , KC_6   , KC_7   , KC_8   , KC_9   ,  /**/  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                           XXXXXXX, XXXXXXX,  /**/  XXXXXXX, XXXXXXX
),

[L_FUN] = LAYOUT(
XXXXXXX, KC_F10 , KC_F11 , KC_F12 , XXXXXXX,  /**/  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
XXXXXXX, KC_F1  , KC_F2  , KC_F3  , KC_F4  ,  /**/  XXXXXXX, KC_RSFT, KC_RGUI, KC_RALT, KC_RCTL,
KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  ,  /**/  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                           XXXXXXX, XXXXXXX,  /**/  XXXXXXX, XXXXXXX
),

[L_SYS] = LAYOUT(
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  /**/  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  /**/  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
QK_BOOT, QK_RBT , XXXXXXX, XXXXXXX, XXXXXXX,  /**/  XXXXXXX, XXXXXXX, XXXXXXX, QK_RBT , QK_BOOT,
                           XXXXXXX, XXXXXXX,  /**/  XXXXXXX, XXXXXXX
),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case GUI_TAB:
            if (record->event.pressed) {
                if (!tabbing) {
                    register_code(KC_LGUI);
                    tabbing = true;
                }
                tap_code(KC_TAB);
            }
            return false;
        case GUI_GRV:
            if (record->event.pressed) {
                if (!tabbing) {
                    register_code(KC_LGUI);
                    tabbing = true;
                }
                tap_code(KC_GRV);
            }
            return false;

        default:
            if (tabbing) {
                unregister_code(KC_LGUI);
                tabbing = false;
            }
            return true;
    }
}
