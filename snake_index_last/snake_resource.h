unsigned char code tcs_bt[2][32]={
{
0x02,0x00,0x01,0x00,0xFF,0xFE,0x04,0x40,0x14,0x50,0x24,0x48,0x44,0x44,0x00,0x00,
0x3F,0xF0,0x08,0x20,0x04,0x40,0x02,0x80,0x01,0x00,0x06,0xC0,0x18,0x30,0xE0,0x0E,
},
{
0x01,0x00,0x01,0x00,0x7F,0xFC,0x01,0x00,0x02,0x80,0x04,0x40,0x0A,0x20,0x31,0x18,
0xC0,0x06,0x01,0x00,0x08,0x88,0x48,0x84,0x48,0x12,0x48,0x12,0x87,0xF0,0x00,0x00,
},
};//变态

unsigned char code tcs_kn[2][32]={
{
0x00,0x00,0x7F,0xFC,0x41,0x04,0x41,0x04,0x41,0x04,0x5F,0xF4,0x41,0x04,0x43,0x84,
0x43,0x44,0x45,0x24,0x49,0x14,0x51,0x14,0x41,0x04,0x41,0x04,0x7F,0xFC,0x40,0x04,
},
{
0x00,0xA0,0x00,0x90,0xFC,0x80,0x05,0xFE,0x05,0x10,0x4B,0x10,0x2D,0xFC,0x29,0x10,
0x11,0x10,0x11,0xFC,0x29,0x10,0x25,0x10,0x45,0x10,0x81,0xFE,0x01,0x00,0x01,0x00,
}
};//困难

unsigned char code tcs_jd[2][32]={
{
0x20,0x40,0x3F,0x7E,0x48,0x90,0x85,0x08,0x10,0x00,0x0B,0xF8,0x20,0x08,0x27,0xC8,
0x24,0x48,0x24,0x48,0x27,0xC8,0x24,0x48,0x24,0x48,0x27,0xC8,0x20,0x08,0x20,0x18,
},
{
0x10,0x10,0x08,0x20,0x04,0x40,0x3F,0xF8,0x21,0x08,0x21,0x08,0x3F,0xF8,0x21,0x08,
0x21,0x08,0x3F,0xF8,0x01,0x00,0x01,0x00,0xFF,0xFE,0x01,0x00,0x01,0x00,0x01,0x00,
}
};//简单

unsigned char code jb[2][32]={
{
0x10,0x00,0x13,0xFC,0x20,0x84,0x20,0x88,0x48,0x88,0xF8,0x90,0x10,0x9C,0x20,0x84,
0x41,0x44,0xF9,0x44,0x41,0x28,0x01,0x28,0x1A,0x10,0xE2,0x28,0x44,0x44,0x01,0x82,//级
},
{
0x00,0x04,0x7F,0x04,0x41,0x04,0x41,0x24,0x41,0x24,0x7F,0x24,0x10,0x24,0x10,0x24,
0xFF,0x24,0x11,0x24,0x11,0x24,0x11,0x24,0x21,0x04,0x21,0x04,0x4A,0x14,0x84,0x08,//别
},
}; //级别

unsigned char code tcs_shuzi[10][16]={
{0x00,0x00,0x00,0x18,0x24,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x24,0x18,0x00,0x00,},//0
{0x00,0x00,0x00,0x10,0x70,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x7C,0x00,0x00,},//1
{0x00,0x00,0x00,0x3C,0x42,0x42,0x42,0x04,0x04,0x08,0x10,0x20,0x42,0x7E,0x00,0x00,},//2
{0x00,0x00,0x00,0x3C,0x42,0x42,0x04,0x18,0x04,0x02,0x02,0x42,0x44,0x38,0x00,0x00,},//3
{0x00,0x00,0x00,0x04,0x0C,0x14,0x24,0x24,0x44,0x44,0x7E,0x04,0x04,0x1E,0x00,0x00,},//4
{0x00,0x00,0x00,0x7E,0x40,0x40,0x40,0x58,0x64,0x02,0x02,0x42,0x44,0x38,0x00,0x00,},//5
{0x00,0x00,0x00,0x1C,0x24,0x40,0x40,0x58,0x64,0x42,0x42,0x42,0x24,0x18,0x00,0x00,},//6
{0x00,0x00,0x00,0x7E,0x44,0x44,0x08,0x08,0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x00,},//7
{0x00,0x00,0x00,0x3C,0x42,0x42,0x42,0x24,0x18,0x24,0x42,0x42,0x42,0x3C,0x00,0x00,},//8
{0x00,0x00,0x00,0x18,0x24,0x42,0x42,0x42,0x26,0x1A,0x02,0x02,0x24,0x38,0x00,0x00,} //9
};//0 - 9

unsigned char code df[2][32]={
{
0x08,0x00,0x0B,0xF8,0x12,0x08,0x23,0xF8,0x4A,0x08,0x0B,0xF8,0x10,0x00,0x33,0xFC,
0x50,0x10,0x97,0xFE,0x10,0x10,0x12,0x10,0x11,0x10,0x10,0x10,0x10,0x50,0x10,0x20//得
},
{
0x00,0x40,0x04,0x40,0x04,0x20,0x08,0x20,0x10,0x10,0x20,0x08,0x40,0x04,0x9F,0xE2,
0x04,0x20,0x04,0x20,0x04,0x20,0x08,0x20,0x08,0x20,0x10,0x20,0x21,0x40,0x40,0x80,//分
},
};//得分

unsigned char code tcs_map[2][512]={
{
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
},//无地图
{
0xFF,0xFF,0xFF,0x00,0x00,0xFF,0xFF,0xFF,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
0x80,0x00,0x3F,0xFF,0xFF,0xFC,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x7F,0x00,0x00,0xFE,0x00,0x01,
0x80,0x80,0x40,0x00,0x00,0x02,0x01,0x01,0x80,0x80,0x40,0x00,0x00,0x02,0x01,0x01,
0x80,0x80,0x40,0x00,0x00,0x02,0x01,0x01,0x80,0x80,0x40,0x01,0x00,0x02,0x01,0x01,
0x80,0x80,0x40,0x01,0x00,0x02,0x01,0x01,0x80,0x80,0x40,0x01,0x00,0x02,0x01,0x01,
0x00,0x80,0x00,0x01,0x00,0x00,0x01,0x00,0x00,0x80,0x00,0x01,0x00,0x00,0x01,0x00,
0x00,0x80,0x00,0x01,0x00,0x00,0x01,0x00,0x00,0x80,0x00,0x01,0x00,0x00,0x01,0x00,
0x00,0x80,0x00,0x01,0x00,0x00,0x01,0x00,0x00,0x80,0x00,0x01,0x00,0x00,0x01,0x00,
0x00,0x80,0x00,0x01,0x00,0x00,0x01,0x00,0x00,0x80,0x00,0xFF,0xFE,0x00,0x01,0x00,
0x00,0x80,0x00,0x01,0x00,0x00,0x01,0x00,0x00,0x80,0x00,0x01,0x00,0x00,0x01,0x00,
0x00,0x80,0x00,0x01,0x00,0x00,0x01,0x00,0x00,0x80,0x00,0x01,0x00,0x00,0x01,0x00,
0x00,0x80,0x00,0x01,0x00,0x00,0x01,0x00,0x00,0x80,0x00,0x01,0x00,0x00,0x01,0x00,
0x00,0x80,0x00,0x01,0x00,0x00,0x01,0x00,0x00,0x80,0x00,0x01,0x00,0x00,0x01,0x00,
0x80,0x80,0x40,0x01,0x00,0x02,0x01,0x01,0x80,0x80,0x40,0x00,0x00,0x02,0x01,0x01,
0x80,0x80,0x40,0x00,0x00,0x02,0x01,0x01,0x80,0x80,0x40,0x00,0x00,0x02,0x01,0x01,
0x80,0x80,0x40,0x00,0x00,0x02,0x01,0x01,0x80,0x80,0x40,0x00,0x00,0x02,0x01,0x01,
0x80,0x00,0x7F,0x00,0x00,0xFE,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x3F,0xFF,0xFF,0xFC,0x00,0x01,
0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xFF,0xFF,0xFF,0x00,0x00,0xFF,0xFF,0xFF	
}
};//2张地图