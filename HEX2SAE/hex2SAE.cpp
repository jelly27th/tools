#include "hex2SAE.h"
#include <QByteArray>


char FaultField[4] = {'P', 'C', 'B', 'U'};
char HexField[16] = {0x00, 0x01, 0x02, 0x03,
                     0x04, 0x05, 0x06, 0x07,
                     0x08, 0x09, 0x0A, 0x0B,
                     0x0C, 0x0D, 0x0E, 0x0F};
char DTCType[4] = {'0', '1', '2', '3'};

QString SAEFile;
QString hexFile;

// reference: 
// https://blog.csdn.net/wjz110201/article/details/130294940?spm=1001.2101.3001.6661.1&utm_medium=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7EPayColumn-1-130294940-blog-128841817.235%5Ev39%5Epc_relevant_default_base&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7EPayColumn-1-130294940-blog-128841817.235%5Ev39%5Epc_relevant_default_base
// https://blog.csdn.net/guohengcook/article/details/81416004
// https://zhuanlan.zhihu.com/p/555254853?utm_id=0

void SAE2Hex(FILE* ipf, FILE* opf) {

    char buffer[9];
    char tmp[7] = {0};

    while (fgets(buffer, sizeof(buffer), ipf) != NULL) {
    
        for (int i = 2; i < 7; i++) {
                tmp[i-1] = buffer[i];
        }
        
        // Get DTCHighByte bit6_7 from SAE's FaultField
        char bit6_7 = 0x8;
        if (buffer[0] >= 97 && buffer[0] <= 102) {
            buffer[0] -= 32;
        }
        switch (buffer[0]) {
        case 'P': 
            bit6_7 = 0x0;
            break;
        case 'C':
            bit6_7 = 0x1;
            break;
        case 'B':
            bit6_7 = 0x2;
            break;
        case 'U':
            bit6_7 = 0x3;
            break;
        default:
            break;
        }

        // Get DTCHighByte bit4_5 from SAE's DTCType
        char bit4_5 = buffer[1] - 48;
        
        // Get DTCHighByte bit6_7 by merging bit6_7 and bit4_5
        char bit4_7 = 0;
        bit4_7 |= (bit6_7 & 0x03) << 2;
        bit4_7 |= (bit4_5 & 0x03);
        
        // Convert to ASCII
        if (bit4_7 >=0 && bit4_7 <= 9) {
            tmp[0] = bit4_7 + 48;
        } else if (bit4_7 >= 10 && bit4_7 <= 15) {
            tmp[0] = bit4_7 + 55;
        }
        tmp[6] = '\n';

        // clear buffer
        for (int i = 0; i < sizeof(buffer); i++) {
                buffer[i] = 0;  
        }

        fputs(tmp, opf);        
        
    }
}

void Hex2SAE(FILE* ipf, FILE* opf) {
    char buffer[8];
    char tmp[8] = {0};

    while (fgets(buffer, sizeof(buffer), ipf) != NULL) {
    
        for (int i = 0; i < 6; i++) {
                tmp[i+1] = buffer[i];
        }
        
        // Get bit 4~7 from DTCHighByte
        char bit4_7 = tmp[1];
        // '0' ~ '9'
        if (bit4_7 >= 48 && bit4_7 <= 57) {
                bit4_7 -= 48;
        // 'A' ~ 'F'
        } else if (bit4_7 >= 65 && bit4_7 <= 70) {
                bit4_7 -= 55;
        // 'a' ~ 'f'
        } else if (bit4_7 >= 97 && bit4_7 <= 102) {
                bit4_7 -= 87;
        }
        bit4_7 = HexField[bit4_7];
        
        // Caluate Fault Field from DTCHighByte bit 6~7 and
        // DTC Type from DTCHighByte bit 4~5
        char bit6_7 = (bit4_7 & 0x0C) >> 2;
        tmp[0] = FaultField[bit6_7];
        char bit4_5 = bit4_7 & 0x03;
        tmp[1] = DTCType[bit4_5];
        tmp[7] = '\n';
        
        // clear buffer
        for (int i = 0; i < sizeof(buffer); i++) {
                buffer[i] = 0;  
        }

        fputs(tmp, opf);        
            
    }
}

void FilePathCheck(FILE* ipf, FILE* opf) {
    if (NULL == ipf) {
        printf("error! failed to open input file.\n");
        exit(EXIT_FAILURE);
    } else if (NULL == opf) {
        printf("error! failed to open output file.\n");
        exit(EXIT_FAILURE);
    }
}
