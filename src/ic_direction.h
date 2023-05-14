unsigned char maneuver_depart[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 
  0x00, 0x3C, 0x00, 0x00, 0x7E, 0x00, 0x00, 0xFF, 0x00, 0x80, 0xFF, 0x01, 
  0x80, 0xDB, 0x01, 0xC0, 0x99, 0x03, 0x80, 0x18, 0x01, 0x00, 0x18, 0x00, 
  0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 
  0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_destination[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7E, 0x00, 0x80, 0xFF, 0x01, 
  0xC0, 0xC3, 0x03, 0xE0, 0x00, 0x07, 0x60, 0x00, 0x06, 0x70, 0x00, 0x0E, 
  0x30, 0x18, 0x0C, 0x30, 0x3C, 0x0C, 0x30, 0x3C, 0x0C, 0x30, 0x18, 0x0C, 
  0x30, 0x00, 0x0C, 0x60, 0x00, 0x06, 0xE0, 0x00, 0x07, 0xC0, 0x00, 0x03, 
  0xC0, 0x81, 0x03, 0x80, 0xC3, 0x01, 0x00, 0xE7, 0x00, 0x00, 0x7E, 0x00, 
  0x00, 0x3C, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_destination_left[] = PROGMEM{
  0x00, 0x00, 0x00, 0xE0, 0x01, 0x00, 0xF8, 0x07, 0x00, 0x1C, 0x0E, 0x00, 
  0x0C, 0x0C, 0x00, 0x06, 0x18, 0x00, 0xC6, 0x18, 0x00, 0xC6, 0x18, 0x00, 
  0x06, 0x18, 0x00, 0x0C, 0x0C, 0x00, 0x0C, 0x0C, 0x00, 0x1C, 0x6E, 0x0E, 
  0x18, 0x66, 0x0E, 0x30, 0xF3, 0x1F, 0xF0, 0xF3, 0x1F, 0xE0, 0x79, 0x1E, 
  0xC0, 0x7C, 0x3E, 0x00, 0xFC, 0x3F, 0x00, 0xFC, 0x3F, 0x00, 0x7E, 0x7E, 
  0x00, 0x7E, 0x7E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_destination_right[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x80, 0x07, 0x00, 0xE0, 0x1F, 0x00, 0x70, 0x38, 
  0x00, 0x30, 0x30, 0x00, 0x18, 0x60, 0x00, 0x18, 0x63, 0x00, 0x18, 0x63, 
  0x00, 0x18, 0x60, 0x00, 0x30, 0x30, 0x00, 0x30, 0x30, 0x70, 0x76, 0x38, 
  0x70, 0x66, 0x18, 0xF8, 0xCF, 0x0C, 0xF8, 0xCF, 0x0F, 0x78, 0x9E, 0x07, 
  0x7C, 0x3E, 0x03, 0xFC, 0x3F, 0x00, 0xFC, 0x3F, 0x00, 0x7E, 0x7E, 0x00, 
  0x7E, 0x7E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_destination_straight[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7E, 0x00, 0x80, 0xFF, 0x01, 
  0xC0, 0xC3, 0x03, 0xE0, 0x00, 0x07, 0x60, 0x00, 0x06, 0x70, 0x00, 0x0E, 
  0x30, 0x18, 0x0C, 0x30, 0x3C, 0x0C, 0x30, 0x3C, 0x0C, 0x30, 0x18, 0x0C, 
  0x30, 0x00, 0x0C, 0x60, 0x00, 0x06, 0xE0, 0x00, 0x07, 0xC0, 0x00, 0x03, 
  0xC0, 0x81, 0x03, 0x80, 0xC3, 0x01, 0x00, 0xE7, 0x00, 0x00, 0x7E, 0x00, 
  0x00, 0x3C, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_fork_left[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x1F, 0x00, 
  0xF0, 0x1F, 0x00, 0xF0, 0x0F, 0x00, 0xF0, 0x01, 0x0C, 0xF0, 0x03, 0x0E, 
  0x70, 0x07, 0x07, 0x70, 0x8E, 0x03, 0x70, 0xDC, 0x01, 0x30, 0xF8, 0x00, 
  0x00, 0xF8, 0x00, 0x00, 0x70, 0x00, 0x00, 0x70, 0x00, 0x00, 0x70, 0x00, 
  0x00, 0x70, 0x00, 0x00, 0x70, 0x00, 0x00, 0x70, 0x00, 0x00, 0x70, 0x00, 
  0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_fork_right[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x0F, 
  0x00, 0xF8, 0x0F, 0x00, 0xF0, 0x0F, 0x30, 0x80, 0x0F, 0x70, 0xC0, 0x0F, 
  0xE0, 0xE0, 0x0E, 0xC0, 0x71, 0x0E, 0x80, 0x3B, 0x0E, 0x00, 0x1F, 0x0C, 
  0x00, 0x1F, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x0E, 0x00, 
  0x00, 0x0E, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x0E, 0x00, 
  0x00, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_keep_left[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x1F, 0x00, 
  0xF0, 0x1F, 0x00, 0xF0, 0x0F, 0x00, 0xF0, 0x01, 0x0C, 0xF0, 0x03, 0x0E, 
  0x70, 0x07, 0x07, 0x70, 0x8E, 0x03, 0x70, 0xDC, 0x01, 0x30, 0xF8, 0x00, 
  0x00, 0xF8, 0x00, 0x00, 0x70, 0x00, 0x00, 0x70, 0x00, 0x00, 0x70, 0x00, 
  0x00, 0x70, 0x00, 0x00, 0x70, 0x00, 0x00, 0x70, 0x00, 0x00, 0x70, 0x00, 
  0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_keep_right[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x0F, 
  0x00, 0xF8, 0x0F, 0x00, 0xF0, 0x0F, 0x30, 0x80, 0x0F, 0x70, 0xC0, 0x0F, 
  0xE0, 0xE0, 0x0E, 0xC0, 0x71, 0x0E, 0x80, 0x3B, 0x0E, 0x00, 0x1F, 0x0C, 
  0x00, 0x1F, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x0E, 0x00, 
  0x00, 0x0E, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x0E, 0x00, 
  0x00, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_merge[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 
  0x00, 0x3C, 0x00, 0x00, 0x7E, 0x00, 0x00, 0xFF, 0x00, 0x80, 0xFF, 0x01, 
  0x80, 0xDB, 0x01, 0xC0, 0x99, 0x03, 0x80, 0x18, 0x01, 0x00, 0x3C, 0x00, 
  0x00, 0x3C, 0x00, 0x00, 0x7E, 0x00, 0x00, 0xF7, 0x00, 0x00, 0xE7, 0x00, 
  0x80, 0xC3, 0x01, 0xC0, 0x81, 0x03, 0xC0, 0x81, 0x03, 0xC0, 0x00, 0x03, 
  0xC0, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_merge_left[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 
  0x00, 0x3C, 0x00, 0x00, 0x7E, 0x00, 0x00, 0xFF, 0x00, 0x80, 0xFF, 0x01, 
  0x80, 0xDB, 0x01, 0xC0, 0x99, 0x03, 0x80, 0x18, 0x01, 0x00, 0x3C, 0x00, 
  0x00, 0x3C, 0x00, 0x00, 0x7E, 0x00, 0x00, 0xF7, 0x00, 0x00, 0xE7, 0x00, 
  0x80, 0xC3, 0x01, 0xC0, 0x81, 0x03, 0xC0, 0x81, 0x03, 0xC0, 0x00, 0x03, 
  0xC0, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_merge_right[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 
  0x00, 0x3C, 0x00, 0x00, 0x7E, 0x00, 0x00, 0xFF, 0x00, 0x80, 0xFF, 0x01, 
  0x80, 0xDB, 0x01, 0xC0, 0x99, 0x03, 0x80, 0x18, 0x01, 0x00, 0x3C, 0x00, 
  0x00, 0x3C, 0x00, 0x00, 0x7E, 0x00, 0x00, 0xF7, 0x00, 0x00, 0xE7, 0x00, 
  0x80, 0xC3, 0x01, 0xC0, 0x81, 0x03, 0xC0, 0x81, 0x03, 0xC0, 0x00, 0x03, 
  0xC0, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_name_change[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 
  0x00, 0x3C, 0x00, 0x00, 0x7E, 0x00, 0x00, 0xFF, 0x00, 0x80, 0xFF, 0x01, 
  0x80, 0xDB, 0x01, 0xC0, 0x99, 0x03, 0x80, 0x18, 0x01, 0x00, 0x18, 0x00, 
  0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 
  0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 
  0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_off_ramp_keep_left[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x1F, 0x00, 
  0xF0, 0x1F, 0x00, 0xF0, 0x0F, 0x00, 0xF0, 0x01, 0x0C, 0xF0, 0x03, 0x0E, 
  0x70, 0x07, 0x07, 0x70, 0x8E, 0x03, 0x70, 0xDC, 0x01, 0x30, 0xF8, 0x00, 
  0x00, 0xF8, 0x00, 0x00, 0x70, 0x00, 0x00, 0x70, 0x00, 0x00, 0x70, 0x00, 
  0x00, 0x70, 0x00, 0x00, 0x70, 0x00, 0x00, 0x70, 0x00, 0x00, 0x70, 0x00, 
  0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_off_ramp_keep_right[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x0F, 
  0x00, 0xF8, 0x0F, 0x00, 0xF0, 0x0F, 0x30, 0x80, 0x0F, 0x70, 0xC0, 0x0F, 
  0xE0, 0xE0, 0x0E, 0xC0, 0x71, 0x0E, 0x80, 0x3B, 0x0E, 0x00, 0x1F, 0x0C, 
  0x00, 0x1F, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x0E, 0x00, 
  0x00, 0x0E, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x0E, 0x00, 
  0x00, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_off_ramp_normal_left[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x0E, 
  0xC0, 0x07, 0x0E, 0xF0, 0x01, 0x0E, 0xF8, 0x00, 0x0E, 0xF8, 0x07, 0x0E, 
  0xF8, 0x3F, 0x0E, 0x70, 0x7F, 0x0E, 0x60, 0xF0, 0x0E, 0xE0, 0xC0, 0x0F, 
  0xC0, 0x81, 0x0F, 0xC0, 0x00, 0x0F, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x0E, 
  0x00, 0x00, 0x0E, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x0E, 
  0x00, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_off_ramp_normal_right[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0xE0, 0x00, 
  0x70, 0xE0, 0x03, 0x70, 0x80, 0x0F, 0x70, 0x00, 0x1F, 0x70, 0xE0, 0x1F, 
  0x70, 0xFC, 0x1F, 0x70, 0xFE, 0x0E, 0x70, 0x0F, 0x06, 0xF0, 0x03, 0x07, 
  0xF0, 0x81, 0x03, 0xF0, 0x00, 0x03, 0xF0, 0x00, 0x00, 0x70, 0x00, 0x00, 
  0x70, 0x00, 0x00, 0x70, 0x00, 0x00, 0x70, 0x00, 0x00, 0x70, 0x00, 0x00, 
  0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_off_ramp_sharp_left[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x80, 0x03, 0x00, 0xC0, 0x0F, 0x00, 0xE0, 0x0F, 0x00, 0x70, 0x1C, 
  0x00, 0x38, 0x1C, 0x18, 0x1C, 0x1C, 0x38, 0x0E, 0x1C, 0x38, 0x07, 0x1C, 
  0xB8, 0x03, 0x1C, 0xF8, 0x01, 0x1C, 0xF8, 0x00, 0x1C, 0xF8, 0x00, 0x1C, 
  0xF8, 0x0F, 0x1C, 0xF8, 0x0F, 0x1C, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x1C, 
  0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_off_ramp_sharp_right[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xC0, 0x01, 0x00, 0xF0, 0x03, 0x00, 0xF0, 0x07, 0x00, 0x38, 0x0E, 0x00, 
  0x38, 0x1C, 0x00, 0x38, 0x38, 0x18, 0x38, 0x70, 0x1C, 0x38, 0xE0, 0x1C, 
  0x38, 0xC0, 0x1D, 0x38, 0x80, 0x1F, 0x38, 0x00, 0x1F, 0x38, 0x00, 0x1F, 
  0x38, 0xF0, 0x1F, 0x38, 0xF0, 0x1F, 0x38, 0x00, 0x00, 0x38, 0x00, 0x00, 
  0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_off_ramp_slight_left[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x7F, 0x00, 
  0xC0, 0x7F, 0x00, 0xC0, 0x3F, 0x00, 0xC0, 0x07, 0x00, 0xC0, 0x0F, 0x00, 
  0xC0, 0x1D, 0x00, 0xC0, 0x39, 0x00, 0xC0, 0x71, 0x00, 0xC0, 0xE0, 0x00, 
  0x00, 0xC0, 0x01, 0x00, 0x80, 0x03, 0x00, 0x80, 0x03, 0x00, 0x00, 0x03, 
  0x00, 0x00, 0x07, 0x00, 0x00, 0x07, 0x00, 0x00, 0x07, 0x00, 0x00, 0x07, 
  0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_off_ramp_slight_right[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x03, 
  0x00, 0xFE, 0x03, 0x00, 0xFC, 0x03, 0x00, 0xE0, 0x03, 0x00, 0xF0, 0x03, 
  0x00, 0xB8, 0x03, 0x00, 0x9C, 0x03, 0x00, 0x8E, 0x03, 0x00, 0x07, 0x03, 
  0x80, 0x03, 0x00, 0xC0, 0x01, 0x00, 0xC0, 0x01, 0x00, 0xC0, 0x00, 0x00, 
  0xE0, 0x00, 0x00, 0xE0, 0x00, 0x00, 0xE0, 0x00, 0x00, 0xE0, 0x00, 0x00, 
  0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_off_ramp_u_turn_left[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x01, 
  0x00, 0xFC, 0x03, 0x00, 0xFE, 0x07, 0x00, 0x07, 0x0E, 0x00, 0x03, 0x1C, 
  0x80, 0x03, 0x1C, 0x80, 0x03, 0x1C, 0x80, 0x03, 0x1C, 0x88, 0x23, 0x1C, 
  0xB8, 0x3B, 0x1C, 0xF8, 0x3F, 0x1C, 0xF0, 0x1F, 0x1C, 0xE0, 0x0F, 0x1C, 
  0xC0, 0x07, 0x1C, 0x80, 0x03, 0x1C, 0x00, 0x01, 0x1C, 0x00, 0x00, 0x1C, 
  0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_off_ramp_u_turn_right[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x0F, 0x00, 
  0xC0, 0x3F, 0x00, 0xE0, 0x7F, 0x00, 0x70, 0xE0, 0x00, 0x38, 0xC0, 0x00, 
  0x38, 0xC0, 0x01, 0x38, 0xC0, 0x01, 0x38, 0xC0, 0x01, 0x38, 0xC4, 0x11, 
  0x38, 0xDC, 0x1D, 0x38, 0xFC, 0x1F, 0x38, 0xF8, 0x0F, 0x38, 0xF0, 0x07, 
  0x38, 0xE0, 0x03, 0x38, 0xC0, 0x01, 0x38, 0x80, 0x00, 0x38, 0x00, 0x00, 
  0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_on_ramp_keep_left[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x1F, 0x00, 
  0xF0, 0x1F, 0x00, 0xF0, 0x0F, 0x00, 0xF0, 0x01, 0x0C, 0xF0, 0x03, 0x0E, 
  0x70, 0x07, 0x07, 0x70, 0x8E, 0x03, 0x70, 0xDC, 0x01, 0x30, 0xF8, 0x00, 
  0x00, 0xF8, 0x00, 0x00, 0x70, 0x00, 0x00, 0x70, 0x00, 0x00, 0x70, 0x00, 
  0x00, 0x70, 0x00, 0x00, 0x70, 0x00, 0x00, 0x70, 0x00, 0x00, 0x70, 0x00, 
  0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_on_ramp_keep_right[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x0F, 
  0x00, 0xF8, 0x0F, 0x00, 0xF0, 0x0F, 0x30, 0x80, 0x0F, 0x70, 0xC0, 0x0F, 
  0xE0, 0xE0, 0x0E, 0xC0, 0x71, 0x0E, 0x80, 0x3B, 0x0E, 0x00, 0x1F, 0x0C, 
  0x00, 0x1F, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x0E, 0x00, 
  0x00, 0x0E, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x0E, 0x00, 
  0x00, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_on_ramp_normal_left[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x80, 0x03, 0x00, 0xC0, 0x01, 0x00, 0xE0, 0x01, 0x00, 0xF0, 0x00, 0x00, 
  0xF8, 0xFF, 0x03, 0xFC, 0xFF, 0x0F, 0xF8, 0xFF, 0x1F, 0xF0, 0x00, 0x38, 
  0xE0, 0x01, 0x38, 0xC0, 0x01, 0x38, 0x80, 0x03, 0x38, 0x00, 0x00, 0x38, 
  0x00, 0x00, 0x38, 0x00, 0x00, 0x38, 0x00, 0x00, 0x38, 0x00, 0x00, 0x38, 
  0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_on_ramp_normal_right[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0xC0, 0x01, 0x00, 0x80, 0x03, 0x00, 0x80, 0x07, 0x00, 0x00, 0x0F, 
  0xE0, 0xFF, 0x1F, 0xF0, 0xFF, 0x3F, 0xF8, 0xFF, 0x1F, 0x1C, 0x00, 0x0F, 
  0x1C, 0x80, 0x07, 0x1C, 0x80, 0x03, 0x1C, 0xC0, 0x01, 0x1C, 0x00, 0x00, 
  0x1C, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x1C, 0x00, 0x00, 
  0x1C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_on_ramp_sharp_left[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x80, 0x03, 0x00, 0xC0, 0x0F, 0x00, 0xE0, 0x0F, 0x00, 0x70, 0x1C, 
  0x00, 0x38, 0x1C, 0x18, 0x1C, 0x1C, 0x38, 0x0E, 0x1C, 0x38, 0x07, 0x1C, 
  0xB8, 0x03, 0x1C, 0xF8, 0x01, 0x1C, 0xF8, 0x00, 0x1C, 0xF8, 0x00, 0x1C, 
  0xF8, 0x0F, 0x1C, 0xF8, 0x0F, 0x1C, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x1C, 
  0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_on_ramp_sharp_right[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xC0, 0x01, 0x00, 0xF0, 0x03, 0x00, 0xF0, 0x07, 0x00, 0x38, 0x0E, 0x00, 
  0x38, 0x1C, 0x00, 0x38, 0x38, 0x18, 0x38, 0x70, 0x1C, 0x38, 0xE0, 0x1C, 
  0x38, 0xC0, 0x1D, 0x38, 0x80, 0x1F, 0x38, 0x00, 0x1F, 0x38, 0x00, 0x1F, 
  0x38, 0xF0, 0x1F, 0x38, 0xF0, 0x1F, 0x38, 0x00, 0x00, 0x38, 0x00, 0x00, 
  0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_on_ramp_slight_left[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x7F, 0x00, 
  0xC0, 0x7F, 0x00, 0xC0, 0x3F, 0x00, 0xC0, 0x07, 0x00, 0xC0, 0x0F, 0x00, 
  0xC0, 0x1D, 0x00, 0xC0, 0x39, 0x00, 0xC0, 0x71, 0x00, 0xC0, 0xE0, 0x00, 
  0x00, 0xC0, 0x01, 0x00, 0x80, 0x03, 0x00, 0x80, 0x03, 0x00, 0x00, 0x03, 
  0x00, 0x00, 0x07, 0x00, 0x00, 0x07, 0x00, 0x00, 0x07, 0x00, 0x00, 0x07, 
  0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_on_ramp_slight_right[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x03, 
  0x00, 0xFE, 0x03, 0x00, 0xFC, 0x03, 0x00, 0xE0, 0x03, 0x00, 0xF0, 0x03, 
  0x00, 0xB8, 0x03, 0x00, 0x9C, 0x03, 0x00, 0x8E, 0x03, 0x00, 0x07, 0x03, 
  0x80, 0x03, 0x00, 0xC0, 0x01, 0x00, 0xC0, 0x01, 0x00, 0xC0, 0x00, 0x00, 
  0xE0, 0x00, 0x00, 0xE0, 0x00, 0x00, 0xE0, 0x00, 0x00, 0xE0, 0x00, 0x00, 
  0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_on_ramp_u_turn_left[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x01, 
  0x00, 0xFC, 0x03, 0x00, 0xFE, 0x07, 0x00, 0x07, 0x0E, 0x00, 0x03, 0x1C, 
  0x80, 0x03, 0x1C, 0x80, 0x03, 0x1C, 0x80, 0x03, 0x1C, 0x88, 0x23, 0x1C, 
  0xB8, 0x3B, 0x1C, 0xF8, 0x3F, 0x1C, 0xF0, 0x1F, 0x1C, 0xE0, 0x0F, 0x1C, 
  0xC0, 0x07, 0x1C, 0x80, 0x03, 0x1C, 0x00, 0x01, 0x1C, 0x00, 0x00, 0x1C, 
  0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_on_ramp_u_turn_right[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x0F, 0x00, 
  0xC0, 0x3F, 0x00, 0xE0, 0x7F, 0x00, 0x70, 0xE0, 0x00, 0x38, 0xC0, 0x00, 
  0x38, 0xC0, 0x01, 0x38, 0xC0, 0x01, 0x38, 0xC0, 0x01, 0x38, 0xC4, 0x11, 
  0x38, 0xDC, 0x1D, 0x38, 0xFC, 0x1F, 0x38, 0xF8, 0x0F, 0x38, 0xF0, 0x07, 
  0x38, 0xE0, 0x03, 0x38, 0xC0, 0x01, 0x38, 0x80, 0x00, 0x38, 0x00, 0x00, 
  0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_roundabout_enter_and_exit_ccw[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x80, 0xCF, 0x01, 
  0xE0, 0xFF, 0x03, 0xF0, 0xFF, 0x07, 0x78, 0xF8, 0x0F, 0x38, 0xFC, 0x1D, 
  0x1C, 0xDC, 0x39, 0x1C, 0xC8, 0x11, 0x1C, 0xC0, 0x01, 0x1C, 0xC0, 0x01, 
  0x1C, 0xC0, 0x01, 0x38, 0xE0, 0x00, 0x78, 0xF0, 0x00, 0xF0, 0x7F, 0x00, 
  0xE0, 0x3F, 0x00, 0x80, 0x0F, 0x00, 0x00, 0x07, 0x00, 0x00, 0x07, 0x00, 
  0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_roundabout_enter_and_exit_ccw_normal_left[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0xC0, 0x81, 0x0F, 0xE0, 0xC1, 0x1F, 0xF0, 0xE0, 0x3F, 
  0x78, 0xF0, 0x78, 0xFC, 0x7F, 0x70, 0xFE, 0x7F, 0x70, 0xFC, 0x7F, 0x70, 
  0x78, 0x70, 0x78, 0xF0, 0xE0, 0x3F, 0xE0, 0xC1, 0x1F, 0xC0, 0x81, 0x0F, 
  0x00, 0x00, 0x07, 0x00, 0x00, 0x07, 0x00, 0x00, 0x07, 0x00, 0x00, 0x07, 
  0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_roundabout_enter_and_exit_ccw_normal_right[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0xF0, 0x81, 0x03, 0xF8, 0x83, 0x07, 0xFC, 0x07, 0x0F, 
  0x0E, 0x0E, 0x1E, 0x0E, 0xFE, 0x3F, 0x0E, 0xFE, 0x7F, 0x0E, 0xFE, 0x3F, 
  0x0E, 0x0F, 0x1E, 0xFC, 0x07, 0x0F, 0xF8, 0x83, 0x07, 0xF0, 0x81, 0x03, 
  0xE0, 0x00, 0x00, 0xE0, 0x00, 0x00, 0xE0, 0x00, 0x00, 0xE0, 0x00, 0x00, 
  0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_roundabout_enter_and_exit_ccw_sharp_left[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0xE0, 0x03, 0x00, 0xF0, 0x07, 0x00, 0xF8, 0x0F, 0x00, 0x3C, 0x1E, 
  0x00, 0x1C, 0x1C, 0x00, 0x1C, 0x1C, 0x00, 0x1C, 0x1C, 0x00, 0x3C, 0x1E, 
  0x30, 0xF8, 0x0F, 0x70, 0xFC, 0x07, 0x70, 0xEE, 0x03, 0x70, 0x07, 0x03, 
  0xF0, 0x03, 0x03, 0xF0, 0x01, 0x03, 0xF0, 0x01, 0x03, 0xF0, 0x1F, 0x03, 
  0xF0, 0x1F, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_roundabout_enter_and_exit_ccw_sharp_right[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xC0, 0x07, 0x00, 0xE0, 0x0F, 0x00, 0xF0, 0x1F, 0x00, 0x38, 0x38, 0x00, 
  0x38, 0x38, 0x00, 0x38, 0x38, 0x00, 0x38, 0x38, 0x00, 0x38, 0x3C, 0x00, 
  0xF0, 0x1F, 0x0C, 0xE0, 0x3F, 0x0E, 0xC0, 0x77, 0x0E, 0xC0, 0xE1, 0x0E, 
  0xC0, 0xC1, 0x0F, 0xC0, 0x81, 0x0F, 0xC0, 0x81, 0x0F, 0xC0, 0xF9, 0x0F, 
  0xC0, 0xF9, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_roundabout_enter_and_exit_ccw_slight_left[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x1F, 0x00, 
  0xF0, 0x1F, 0x00, 0xF0, 0x0F, 0x00, 0xF0, 0x01, 0x00, 0xF0, 0x03, 0x00, 
  0x70, 0xF7, 0x01, 0x70, 0xFE, 0x03, 0x70, 0xFC, 0x07, 0x30, 0x1E, 0x0F, 
  0x00, 0x0E, 0x0E, 0x00, 0x0E, 0x0E, 0x00, 0x0E, 0x0E, 0x00, 0x0E, 0x0F, 
  0x00, 0xFC, 0x07, 0x00, 0xF8, 0x03, 0x00, 0xF0, 0x01, 0x00, 0xE0, 0x00, 
  0x00, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_roundabout_enter_and_exit_ccw_slight_right[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x07, 
  0x00, 0xFC, 0x07, 0x00, 0xF8, 0x07, 0x00, 0xC0, 0x07, 0x00, 0xE0, 0x07, 
  0x80, 0xFF, 0x07, 0xC0, 0x7F, 0x07, 0xE0, 0x3F, 0x07, 0x70, 0x78, 0x06, 
  0x70, 0x70, 0x00, 0x70, 0x70, 0x00, 0x70, 0x70, 0x00, 0x70, 0x78, 0x00, 
  0xE0, 0x3F, 0x00, 0xC0, 0x1F, 0x00, 0x80, 0x0F, 0x00, 0x00, 0x07, 0x00, 
  0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_roundabout_enter_and_exit_ccw_straight[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x3C, 0x00, 0x00, 0x7E, 0x00, 
  0x00, 0xFF, 0x00, 0x80, 0xDB, 0x01, 0xC0, 0x99, 0x03, 0x80, 0x18, 0x01, 
  0x00, 0x7C, 0x00, 0x00, 0xFF, 0x00, 0x80, 0xFF, 0x01, 0x80, 0xC3, 0x01, 
  0x80, 0x81, 0x03, 0x80, 0x81, 0x03, 0x80, 0x81, 0x03, 0x80, 0xC3, 0x01, 
  0x80, 0xFF, 0x01, 0x00, 0xFF, 0x00, 0x00, 0x7C, 0x00, 0x00, 0x18, 0x00, 
  0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_roundabout_enter_and_exit_ccw_u_turn[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7C, 0x00, 0x00, 0xFE, 0x00, 
  0x00, 0xFF, 0x01, 0x80, 0x83, 0x03, 0x80, 0x83, 0x03, 0x80, 0x83, 0x03, 
  0x80, 0x83, 0x03, 0x80, 0x83, 0x03, 0x00, 0xEF, 0x01, 0x00, 0xEE, 0x00, 
  0x00, 0x2E, 0x00, 0x20, 0x8E, 0x00, 0xE0, 0xEE, 0x00, 0xE0, 0xFF, 0x00, 
  0xC0, 0x7F, 0x00, 0x80, 0x3F, 0x00, 0x00, 0xDF, 0x00, 0x00, 0xEE, 0x00, 
  0x00, 0xE4, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_roundabout_enter_and_exit_cw[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x80, 0xF3, 0x01, 
  0xC0, 0xFF, 0x07, 0xE0, 0xFF, 0x0F, 0xF0, 0x1F, 0x1E, 0xB8, 0x3F, 0x1C, 
  0x9C, 0x3B, 0x38, 0x88, 0x13, 0x38, 0x80, 0x03, 0x38, 0x80, 0x03, 0x38, 
  0x80, 0x03, 0x38, 0x00, 0x07, 0x1C, 0x00, 0x0F, 0x1E, 0x00, 0xFE, 0x0F, 
  0x00, 0xFC, 0x07, 0x00, 0xF0, 0x01, 0x00, 0xE0, 0x00, 0x00, 0xE0, 0x00, 
  0x00, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_roundabout_enter_and_exit_cw_normal_left[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0xC0, 0x81, 0x0F, 0xE0, 0xC1, 0x1F, 0xF0, 0xE0, 0x3F, 
  0x78, 0x70, 0x70, 0xFC, 0x7F, 0x70, 0xFE, 0x7F, 0x70, 0xFC, 0x7F, 0x70, 
  0x78, 0xF0, 0x70, 0xF0, 0xE0, 0x3F, 0xE0, 0xC1, 0x1F, 0xC0, 0x81, 0x0F, 
  0x00, 0x00, 0x07, 0x00, 0x00, 0x07, 0x00, 0x00, 0x07, 0x00, 0x00, 0x07, 
  0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_roundabout_enter_and_exit_cw_normal_right[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0xF0, 0x81, 0x03, 0xF8, 0x83, 0x07, 0xFC, 0x07, 0x0F, 
  0x1E, 0x0F, 0x1E, 0x0E, 0xFE, 0x3F, 0x0E, 0xFE, 0x7F, 0x0E, 0xFE, 0x3F, 
  0x1E, 0x0E, 0x1E, 0xFC, 0x07, 0x0F, 0xF8, 0x83, 0x07, 0xF0, 0x81, 0x03, 
  0xE0, 0x00, 0x00, 0xE0, 0x00, 0x00, 0xE0, 0x00, 0x00, 0xE0, 0x00, 0x00, 
  0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_roundabout_enter_and_exit_cw_sharp_left[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0xE0, 0x03, 0x00, 0xF0, 0x07, 0x00, 0xF8, 0x0F, 0x00, 0x1C, 0x1C, 
  0x00, 0x1C, 0x1C, 0x00, 0x1C, 0x1C, 0x00, 0x1C, 0x1C, 0x00, 0x3C, 0x1C, 
  0x30, 0xF8, 0x0F, 0x70, 0xFC, 0x07, 0x70, 0xEE, 0x03, 0x70, 0x87, 0x03, 
  0xF0, 0x83, 0x03, 0xF0, 0x81, 0x03, 0xF0, 0x81, 0x03, 0xF0, 0x9F, 0x03, 
  0xF0, 0x9F, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_roundabout_enter_and_exit_cw_sharp_right[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xC0, 0x07, 0x00, 0xE0, 0x0F, 0x00, 0xF0, 0x1F, 0x00, 0x78, 0x3C, 0x00, 
  0x38, 0x38, 0x00, 0x38, 0x38, 0x00, 0x38, 0x38, 0x00, 0x78, 0x3C, 0x00, 
  0xF0, 0x1F, 0x0C, 0xE0, 0x3F, 0x0E, 0xC0, 0x77, 0x0E, 0xC0, 0xE0, 0x0E, 
  0xC0, 0xC0, 0x0F, 0xC0, 0x80, 0x0F, 0xC0, 0x80, 0x0F, 0xC0, 0xF8, 0x0F, 
  0xC0, 0xF8, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_roundabout_enter_and_exit_cw_slight_left[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x3F, 0x00, 
  0xE0, 0x3F, 0x00, 0xE0, 0x1F, 0x00, 0xE0, 0x03, 0x00, 0xE0, 0x07, 0x00, 
  0xE0, 0xFF, 0x01, 0xE0, 0xFE, 0x03, 0xE0, 0xFC, 0x07, 0x60, 0x1E, 0x0E, 
  0x00, 0x0E, 0x0E, 0x00, 0x0E, 0x0E, 0x00, 0x0E, 0x0E, 0x00, 0x1E, 0x0E, 
  0x00, 0xFC, 0x07, 0x00, 0xF8, 0x03, 0x00, 0xF0, 0x01, 0x00, 0xE0, 0x00, 
  0x00, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_roundabout_enter_and_exit_cw_slight_right[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x0F, 
  0x00, 0xF8, 0x0F, 0x00, 0xF0, 0x0F, 0x00, 0x80, 0x0F, 0x00, 0xC0, 0x0F, 
  0x80, 0xEF, 0x0E, 0xC0, 0x7F, 0x0E, 0xE0, 0x3F, 0x0E, 0xF0, 0x78, 0x0C, 
  0x70, 0x70, 0x00, 0x70, 0x70, 0x00, 0x70, 0x70, 0x00, 0xF0, 0x70, 0x00, 
  0xE0, 0x3F, 0x00, 0xC0, 0x1F, 0x00, 0x80, 0x0F, 0x00, 0x00, 0x07, 0x00, 
  0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_roundabout_enter_and_exit_cw_straight[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x3C, 0x00, 0x00, 0x7E, 0x00, 
  0x00, 0xFF, 0x00, 0x80, 0xDB, 0x01, 0xC0, 0x99, 0x03, 0x80, 0x18, 0x01, 
  0x00, 0x3E, 0x00, 0x00, 0xFF, 0x00, 0x80, 0xFF, 0x01, 0x80, 0xC3, 0x01, 
  0xC0, 0x81, 0x01, 0xC0, 0x81, 0x01, 0xC0, 0x81, 0x01, 0x80, 0xC3, 0x01, 
  0x80, 0xFF, 0x01, 0x00, 0xFF, 0x00, 0x00, 0x3E, 0x00, 0x00, 0x18, 0x00, 
  0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_roundabout_enter_and_exit_cw_u_turn[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3E, 0x00, 0x00, 0x7F, 0x00, 
  0x80, 0xFF, 0x00, 0xC0, 0xC1, 0x01, 0xC0, 0xC1, 0x01, 0xC0, 0xC1, 0x01, 
  0xC0, 0xC1, 0x01, 0xC0, 0xC1, 0x01, 0x80, 0xF7, 0x00, 0x00, 0x77, 0x00, 
  0x00, 0x74, 0x00, 0x00, 0x71, 0x04, 0x00, 0x77, 0x07, 0x00, 0xFF, 0x07, 
  0x00, 0xFE, 0x03, 0x00, 0xFC, 0x01, 0x00, 0xFB, 0x00, 0x00, 0x77, 0x00, 
  0x00, 0x27, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_roundabout_enter_ccw[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x80, 0xCF, 0x01, 
  0xE0, 0xFF, 0x03, 0xF0, 0xFF, 0x07, 0x78, 0xF8, 0x0F, 0x38, 0xFC, 0x1D, 
  0x1C, 0xDC, 0x39, 0x1C, 0xC8, 0x11, 0x1C, 0xC0, 0x01, 0x1C, 0xC0, 0x01, 
  0x1C, 0xC0, 0x01, 0x38, 0xE0, 0x00, 0x78, 0xF0, 0x00, 0xF0, 0x7F, 0x00, 
  0xE0, 0x3F, 0x00, 0x80, 0x0F, 0x00, 0x00, 0x07, 0x00, 0x00, 0x07, 0x00, 
  0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_roundabout_enter_cw[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x80, 0xF3, 0x01, 
  0xC0, 0xFF, 0x07, 0xE0, 0xFF, 0x0F, 0xF0, 0x1F, 0x1E, 0xB8, 0x3F, 0x1C, 
  0x9C, 0x3B, 0x38, 0x88, 0x13, 0x38, 0x80, 0x03, 0x38, 0x80, 0x03, 0x38, 
  0x80, 0x03, 0x38, 0x00, 0x07, 0x1C, 0x00, 0x0F, 0x1E, 0x00, 0xFE, 0x0F, 
  0x00, 0xFC, 0x07, 0x00, 0xF0, 0x01, 0x00, 0xE0, 0x00, 0x00, 0xE0, 0x00, 
  0x00, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_roundabout_exit_ccw[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x38, 0x00, 
  0x00, 0x7C, 0x00, 0x00, 0xFE, 0x00, 0x00, 0xFF, 0x01, 0x80, 0xFB, 0x03, 
  0xC0, 0xB9, 0x03, 0x80, 0x38, 0x01, 0x00, 0x38, 0x00, 0x00, 0x38, 0x00, 
  0x80, 0x3F, 0x00, 0xE0, 0x7F, 0x00, 0xF0, 0xFF, 0x00, 0x70, 0xE0, 0x01, 
  0x00, 0xC0, 0x03, 0x00, 0x80, 0x03, 0x00, 0x00, 0x07, 0x00, 0x00, 0x07, 
  0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_roundabout_exit_cw[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x1C, 0x00, 
  0x00, 0x3E, 0x00, 0x00, 0x7F, 0x00, 0x80, 0xFF, 0x00, 0xC0, 0xDF, 0x01, 
  0xC0, 0x9D, 0x03, 0x80, 0x1C, 0x01, 0x00, 0x1C, 0x00, 0x00, 0x1C, 0x00, 
  0x00, 0xFC, 0x01, 0x00, 0xFE, 0x07, 0x00, 0xFF, 0x0F, 0x80, 0x07, 0x0E, 
  0xC0, 0x03, 0x00, 0xC0, 0x01, 0x00, 0xE0, 0x00, 0x00, 0xE0, 0x00, 0x00, 
  0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_straight[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 
  0x00, 0x3C, 0x00, 0x00, 0x7E, 0x00, 0x00, 0xFF, 0x00, 0x80, 0xFF, 0x01, 
  0x80, 0xDB, 0x01, 0xC0, 0x99, 0x03, 0x80, 0x18, 0x01, 0x00, 0x18, 0x00, 
  0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 
  0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 
  0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_turn_normal_left[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x80, 0x03, 0x00, 0xC0, 0x01, 0x00, 0xE0, 0x01, 0x00, 0xF0, 0x00, 0x00, 
  0xF8, 0xFF, 0x03, 0xFC, 0xFF, 0x0F, 0xF8, 0xFF, 0x1F, 0xF0, 0x00, 0x38, 
  0xE0, 0x01, 0x38, 0xC0, 0x01, 0x38, 0x80, 0x03, 0x38, 0x00, 0x00, 0x38, 
  0x00, 0x00, 0x38, 0x00, 0x00, 0x38, 0x00, 0x00, 0x38, 0x00, 0x00, 0x38, 
  0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_turn_normal_right[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0xC0, 0x01, 0x00, 0x80, 0x03, 0x00, 0x80, 0x07, 0x00, 0x00, 0x0F, 
  0xE0, 0xFF, 0x1F, 0xF0, 0xFF, 0x3F, 0xF8, 0xFF, 0x1F, 0x1C, 0x00, 0x0F, 
  0x1C, 0x80, 0x07, 0x1C, 0x80, 0x03, 0x1C, 0xC0, 0x01, 0x1C, 0x00, 0x00, 
  0x1C, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x1C, 0x00, 0x00, 
  0x1C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_turn_sharp_left[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x80, 0x03, 0x00, 0xC0, 0x0F, 0x00, 0xE0, 0x0F, 0x00, 0x70, 0x1C, 
  0x00, 0x38, 0x1C, 0x18, 0x1C, 0x1C, 0x38, 0x0E, 0x1C, 0x38, 0x07, 0x1C, 
  0xB8, 0x03, 0x1C, 0xF8, 0x01, 0x1C, 0xF8, 0x00, 0x1C, 0xF8, 0x00, 0x1C, 
  0xF8, 0x0F, 0x1C, 0xF8, 0x0F, 0x1C, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x1C, 
  0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_turn_sharp_right[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xC0, 0x01, 0x00, 0xF0, 0x03, 0x00, 0xF0, 0x07, 0x00, 0x38, 0x0E, 0x00, 
  0x38, 0x1C, 0x00, 0x38, 0x38, 0x18, 0x38, 0x70, 0x1C, 0x38, 0xE0, 0x1C, 
  0x38, 0xC0, 0x1D, 0x38, 0x80, 0x1F, 0x38, 0x00, 0x1F, 0x38, 0x00, 0x1F, 
  0x38, 0xF0, 0x1F, 0x38, 0xF0, 0x1F, 0x38, 0x00, 0x00, 0x38, 0x00, 0x00, 
  0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_turn_slight_left[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x7F, 0x00, 
  0xC0, 0x7F, 0x00, 0xC0, 0x3F, 0x00, 0xC0, 0x07, 0x00, 0xC0, 0x0F, 0x00, 
  0xC0, 0x1D, 0x00, 0xC0, 0x39, 0x00, 0xC0, 0x71, 0x00, 0xC0, 0xE0, 0x00, 
  0x00, 0xC0, 0x01, 0x00, 0x80, 0x03, 0x00, 0x80, 0x03, 0x00, 0x00, 0x03, 
  0x00, 0x00, 0x07, 0x00, 0x00, 0x07, 0x00, 0x00, 0x07, 0x00, 0x00, 0x07, 
  0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_turn_slight_right[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x03, 
  0x00, 0xFE, 0x03, 0x00, 0xFC, 0x03, 0x00, 0xE0, 0x03, 0x00, 0xF0, 0x03, 
  0x00, 0xB8, 0x03, 0x00, 0x9C, 0x03, 0x00, 0x8E, 0x03, 0x00, 0x07, 0x03, 
  0x80, 0x03, 0x00, 0xC0, 0x01, 0x00, 0xC0, 0x01, 0x00, 0xC0, 0x00, 0x00, 
  0xE0, 0x00, 0x00, 0xE0, 0x00, 0x00, 0xE0, 0x00, 0x00, 0xE0, 0x00, 0x00, 
  0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_u_turn_left[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x01, 
  0x00, 0xFC, 0x03, 0x00, 0xFE, 0x07, 0x00, 0x07, 0x0E, 0x00, 0x03, 0x1C, 
  0x80, 0x03, 0x1C, 0x80, 0x03, 0x1C, 0x80, 0x03, 0x1C, 0x88, 0x23, 0x1C, 
  0xB8, 0x3B, 0x1C, 0xF8, 0x3F, 0x1C, 0xF0, 0x1F, 0x1C, 0xE0, 0x0F, 0x1C, 
  0xC0, 0x07, 0x1C, 0x80, 0x03, 0x1C, 0x00, 0x01, 0x1C, 0x00, 0x00, 0x1C, 
  0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

unsigned char maneuver_u_turn_right[] = PROGMEM{
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x0F, 0x00, 
  0xC0, 0x3F, 0x00, 0xE0, 0x7F, 0x00, 0x70, 0xE0, 0x00, 0x38, 0xC0, 0x00, 
  0x38, 0xC0, 0x01, 0x38, 0xC0, 0x01, 0x38, 0xC0, 0x01, 0x38, 0xC4, 0x11, 
  0x38, 0xDC, 0x1D, 0x38, 0xFC, 0x1F, 0x38, 0xF8, 0x0F, 0x38, 0xF0, 0x07, 
  0x38, 0xE0, 0x03, 0x38, 0xC0, 0x01, 0x38, 0x80, 0x00, 0x38, 0x00, 0x00, 
  0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

