#pragma once

char lower_to_upper(char ch);
char upper_to_lower(char ch);
char space_to_dash(char ch);
char reverse_letter(char ch);
char* letter_modifier(char *text, char(*ptr)(char));