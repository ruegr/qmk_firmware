// !!! DO NOT ADD #pragma once !!! //

// Step 1.
// Declare custom effects using the RGB_MATRIX_EFFECT macro
// (note the lack of semicolon after the macro!)
RGB_MATRIX_EFFECT(static_key_highlight)

// Step 2.
// Define effects inside the `RGB_MATRIX_CUSTOM_EFFECT_IMPLS` ifdef block
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

// e.g: A simple effect, self-contained within a single method
static bool static_key_highlight(effect_params_t* params) {



  RGB_MATRIX_USE_LIMITS(led_min, led_max);

  RGB mainCol = rgb_matrix_hsv_to_rgb(rgb_matrix_config.hsv);

  for (uint8_t i = led_min; i < led_max; i++) {
    switch(i) {
        // RED Highlights
        case 0: // [ESC]
            rgb_matrix_set_color(i, RGB_RED);
            break;

        // Movement Keys
        case 43: // [W]
        case 62: // [A]
        case 63: // [S]
        case 64: // [D]
        case 96: // [CTRL-L]
        case 99: // [SPACE]
        // Missing: [X], [Y]
            rgb_matrix_set_color(i, RGB_BLUE);
            break;

        // Interaction keys
        // Missing [M], [N], [T]
        case 41: // [TAB]
        case 42: // [Q]
        case 44: // [E]
            rgb_matrix_set_color(i, RGB_GREEN);
            break;

        // communication keys
        // Missing [ENTER], [H], [C], [Q], [ALT]

        // Weapon Keys
        case 21: // [1]
        case 22: // [2]
        case 23: // [3]
        case 24: // [4]
        case 45: // [R]
        case 65: // [F]
        case 66: // [G]
        // Missing [V]
            rgb_matrix_set_color(i, RGB_ORANGE);
            break;

        // all other keys - controllable main color
        default:
            rgb_matrix_set_color(i, mainCol.r, mainCol.g, mainCol.b);
    }
  }
  return rgb_matrix_check_finished_leds(led_max);
}



#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
