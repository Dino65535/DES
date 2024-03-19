#include <iostream>
#include <vector>
#include <string>
using namespace std;

void check(vector<bool> v){
    int space = 4;
    for(int i=0; i<v.size(); i++){
        if(i && i%space==0)cout << " ";
        cout << v[i];
    }
    cout << "\n";
}

string hex_to_binary(string str){
    string ret = "";
    for(int i=0; i<16; i++){
        switch(str[i]){
        case '0':
            ret += "0000";
            break;
        case '1':
            ret += "0001";
            break;
        case '2':
            ret += "0010";
            break;
        case '3':
            ret += "0011";
            break;
        case '4':
            ret += "0100";
            break;
        case '5':
            ret += "0101";
            break;
        case '6':
            ret += "0110";
            break;
        case '7':
            ret += "0111";
            break;
        case '8':
            ret += "1000";
            break;
        case '9':
            ret += "1001";
            break;
        case 'A':
            ret += "1010";
            break;
        case 'B':
            ret += "1011";
            break;
        case 'C':
            ret += "1100";
            break;
        case 'D':
            ret += "1101";
            break;
        case 'E':
            ret += "1110";
            break;
        case 'F':
            ret += "1111";
            break;
        }
    }
    return ret;
}

void binary_to_hex(vector<bool> v){
    string ret = "", str="";

    for(int i=0; i<16; i++){
        int j = v[i*4]*8 + v[i*4+1]*4 + v[i*4+2]*2 + v[i*4+3];
        switch(j){
        case 0:
            ret += "0";
            break;
        case 1:
            ret += "1";
            break;
        case 2:
            ret += "2";
            break;
        case 3:
            ret += "3";
            break;
        case 4:
            ret += "4";
            break;
        case 5:
            ret += "5";
            break;
        case 6:
            ret += "6";
            break;
        case 7:
            ret += "7";
            break;
        case 8:
            ret += "8";
            break;
        case 9:
            ret += "9";
            break;
        case 10:
            ret += "A";
            break;
        case 11:
            ret += "B";
            break;
        case 12:
            ret += "C";
            break;
        case 13:
            ret += "D";
            break;
        case 14:
            ret += "E";
            break;
        case 15:
            ret += "F";
            break;
        }
    }
    cout << ret << "\n";
}

void initial_permutation(vector<bool>* v){
    vector<bool> ret(64, false);
    int IP[64] = {58, 50, 42, 34, 26, 18, 10, 2,
                  60, 52, 44, 36, 28, 20, 12, 4,
                  62, 54, 46, 38, 30, 22, 14, 6,
                  64, 56, 48, 40, 32, 24, 16, 8,
                  57, 49, 41, 33, 25, 17,  9, 1,
                  59, 51, 43, 35, 27, 19, 11, 3,
                  61, 53, 45, 37, 29, 21, 13, 5,
                  63, 55, 47, 39, 31, 23, 15, 7};

    for(int i=0; i<64; i++)
        ret[i] = (*v)[IP[i]-1];

    *v = ret;
}

void final_permutation(vector<bool>* v){
    vector<bool> ret(64, false);
    int IP_inverse[64] = {40, 8, 48, 16, 56, 24, 64, 32,
                          39, 7, 47, 15, 55, 23, 63, 31,
                          38, 6, 46, 14, 54, 22, 62, 30,
                          37, 5, 45, 13, 53, 21, 61, 29,
                          36, 4, 44, 12, 52, 20, 60, 28,
                          35, 3, 43, 11, 51, 19, 59, 27,
                          34, 2, 42, 10, 50, 18, 58, 26,
                          33, 1, 41,  9, 49, 17, 57, 25};

    for(int i=0; i<64; i++)
        ret[i] = (*v)[IP_inverse[i]-1];

    *v = ret;
}

void expansion(vector<bool>* v){
    vector<bool> ret(48, false);
    int E[48] = {32,  1,  2,  3,  4,  5,
                  4,  5,  6,  7,  8,  9,
                  8,  9, 10, 11, 12, 13,
                 12, 13, 14, 15, 16, 17,
                 16, 17, 18, 19, 20, 21,
                 20, 21, 22, 23, 24, 25,
                 24, 25, 26, 27, 28, 29,
                 28, 29, 30, 31, 32,  1};

    for(int i=0; i<48; i++)
        ret[i] = (*v)[E[i]-1];

    *v = ret;
}

void PC_1(vector<bool>* v){
    vector<bool> ret(56, false);
    int PC1[56] = {57, 49, 41, 33, 25, 17,  9,
                    1, 58, 50, 42, 34, 26, 18,
                   10,  2, 59, 51, 43, 35, 27,
                   19, 11,  3, 60, 52, 44, 36,
                   63, 55, 47, 39, 31, 23, 15,
                    7, 62, 54, 46, 38, 30, 22,
                   14,  6, 61, 53, 45, 37, 29,
                   21, 13,  5, 28, 20, 12,  4};

    for(int i=0; i<56; i++)
        ret[i] = (*v)[PC1[i]-1];

    *v = ret;
}

void shift_left(vector<bool>* v, int shift_bit){
    if(shift_bit == 1){ //Cn:0~27  Dn:28~55
        int t0 = (*v)[0], t28 = (*v)[28];
        for(int i=0; i<55; i++)
            (*v)[i] = (*v)[i+1];
        (*v)[27] = t0;
        (*v)[55] = t28;

    }
    else if(shift_bit == 2){
        int t0 = (*v)[0], t1 = (*v)[1], t28 = (*v)[28], t29 = (*v)[29];
        for(int i=0; i<54; i++)
            (*v)[i] = (*v)[i+2];
        (*v)[26] = t0;
        (*v)[27] = t1;
        (*v)[54] = t28;
        (*v)[55] = t29;
    }
}

void PC_2(vector<bool>* v){
    vector<bool> ret(48, false);
    int PC2[48] = {14, 17, 11, 24,  1,  5,
                    3, 28, 15,  6, 21, 10,
                   23, 19, 12,  4, 26,  8,
                   16,  7, 27, 20, 13,  2,
                   41, 52, 31, 37, 47, 55,
                   30, 40, 51, 45, 33, 48,
                   44, 49, 39, 56, 34, 53,
                   46, 42, 50, 36, 29, 32};

    for(int i=0; i<48; i++)
        ret[i] = (*v)[PC2[i]-1];

    *v = ret;
}

void Sbox(vector<bool>* v){
    vector<bool> ret(32, false);
    int index = 0;
    int s[8][4][16] = { { 14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7,
                          0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,
                          4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0,
                          15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13 },
                        { 15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10,
                          3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,
                          0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15,
                          13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9 },
                        { 10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8,
                          13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,
                          13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7,
                          1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12 },
                        { 7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,
                          13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,
                          10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4,
                          3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14 },
                        { 2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9,
                          14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6,
                          4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14,
                          11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3 },
                        { 12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11,
                          10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8,
                          9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6,
                          4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13 },
                        { 4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1,
                          13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6,
                          1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2,
                          6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12 },
                        { 13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7,
                          1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2,
                          7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8,
                          2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11 } };

    for(int i=0; i<8; i++){
        int row = 0, col = 0;
        col = (*v)[i*6]*2 + (*v)[i*6+5]; //xyyyyx > find xx
        row = (*v)[i*6+1]*8 + (*v)[i*6+2]*4 + (*v)[i*6+3]*2 + (*v)[i*6+4]; //xyyyyx > find yyyy

        int box_number = s[i][col][row];
        for(int j=1; j<=4; j++){
            ret[(i+1)*4-j] = box_number%2;
            box_number /= 2;
        }
    }

    *v = ret;
}

void p_permutation(vector<bool>* v){
    vector<bool> ret(32, false);
    int P[32] = { 16,  7, 20, 21, 29, 12, 28, 17,
                   1, 15, 23, 26,  5, 18, 31, 10,
                   2,  8, 24, 14, 32, 27,  3,  9,
                  19, 13, 30,  6, 22, 11,  4, 25};

    for(int i=0; i<32; i++)
        ret[i] = (*v)[P[i]-1];

    *v = ret;
}

int main()
{
    string M = "ABCDEF9873216540"; //plaintext for Hex
    string K = "0001001100110100010101110111100110011011101111001101111111110001"; //Key

    if(M.length() != 16 || K.length() != 64){ //exception case
        cout << "plaintext or key length is wrong!";
        return 0;
    }

    vector<bool> M_binary(64, false), K_binary(64, false); //store plaintext & Key binary
    vector<vector<bool>> subkey_table(16, vector<bool>(56, 0)); //store subkeys for decryption

    M = hex_to_binary(M);
    for(int i=0; i<64; i++){ //convert string(M&K) to binary
        if(M[i] == '0')M_binary[i] = false;
        else M_binary[i] = true;

        if(K[i] == '0')K_binary[i] = false;
        else K_binary[i] = true;
    }

    initial_permutation(&M_binary);

    PC_1(&K_binary);

    vector<bool> LM(M_binary.begin(), M_binary.begin()+32);
    vector<bool> RM(M_binary.begin()+32, M_binary.end());

    for(int i=0; i<16; i++){ //Encrypt
        vector<bool> LM_temp = LM, RM_temp = RM;
        LM = RM;

        expansion(&RM_temp);

        if(i == 0 || i == 1 || i == 8 || i == 15) //in round 1.2.9.16 shift left one
            shift_left(&K_binary, 1);
        else
            shift_left(&K_binary, 2);

        vector<bool> sub_key = K_binary;
        subkey_table[i] = sub_key;

        PC_2(&sub_key);

        for(int j=0; j<48; j++) //XOR
            sub_key[j] = sub_key[j] ^ RM_temp[j];

        Sbox(&sub_key);

        p_permutation(&sub_key);

        for(int j=0; j<32; j++) //XOR
            RM[j] = sub_key[j] ^ LM_temp[j];
    }

    vector<bool> ciphertext;
    ciphertext.insert(ciphertext.end(), RM.begin(), RM.end()); //insert RM first
    ciphertext.insert(ciphertext.end(), LM.begin(), LM.end()); //because in the end need change LM&RM

    final_permutation(&ciphertext);
    cout << "ciphertext binary : ";
    check(ciphertext);
    cout << "\nciphertext Hex : ";
    binary_to_hex(ciphertext);

    //=============Decrypt=============

    initial_permutation(&ciphertext);
    LM.assign(ciphertext.begin(), ciphertext.begin()+32);
    RM.assign(ciphertext.begin()+32, ciphertext.end());

    for(int i=0; i<16; i++){ //Decrypt
        vector<bool> LM_temp = LM, RM_temp = RM;
        LM = RM;

        expansion(&RM_temp);

        vector<bool> sub_key = subkey_table[15-i]; //get subkeys from table

        PC_2(&sub_key);

        for(int j=0; j<48; j++) //XOR
            sub_key[j] = sub_key[j] ^ RM_temp[j];

        Sbox(&sub_key);

        p_permutation(&sub_key);

        for(int j=0; j<32; j++) //XOR
            RM[j] = sub_key[j] ^ LM_temp[j];
    }

    vector<bool> plaintext;
    plaintext.insert(plaintext.end(), RM.begin(), RM.end()); //insert RM first
    plaintext.insert(plaintext.end(), LM.begin(), LM.end()); //because in the end need change LM&RM

    final_permutation(&plaintext);
    cout << "\n\nplaintext binary : ";
    check(plaintext);
    cout << "\nplaintext Hex : ";
    binary_to_hex(plaintext);
    return 0;
}
