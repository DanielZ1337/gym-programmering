#include <iostream>
#include <istream>
#include <ostream>
#include <fstream>
#include <string>
#include <cmath>
#include <bitset>
#include <algorithm> 

using namespace std;
string tekst;
string tekst1;
int bigNumber, x1, x2, x3, x4, x5, x1_f, x2_f, x3_f, x4_f;
size_t pos, pos2;
string fiveCharPayload;
string payloadText;
string payloadText1;
string directPayload;
ifstream payload("payload.txt");
ifstream payload1("de_Payload.txt");

void stringToASCII()
{
    //cout << ((int)fiveCharPayload[0]-33)*pow(85,4) << '+' << ((int)fiveCharPayload[1]-33)*pow(85,3) << '+' << ((int)fiveCharPayload[2]-33)*pow(85,2) << '+' << ((int)fiveCharPayload[3]-33)*pow(85,1) << '+' << ((int)fiveCharPayload[4]-33) << endl;
    //cout << ((int)fiveCharPayload[0]-33)*pow(85,4) + ((int)fiveCharPayload[1]-33)*pow(85,3) + ((int)fiveCharPayload[2]-33)*pow(85,2) + ((int)fiveCharPayload[3]-33)*pow(85,1) + ((int)fiveCharPayload[4]-33) << endl;
    bigNumber = ((int)fiveCharPayload[0] - 33) * pow(85, 4) + ((int)fiveCharPayload[1] - 33) * pow(85, 3) + ((int)fiveCharPayload[2] - 33) * pow(85, 2) + ((int)fiveCharPayload[3] - 33) * pow(85, 1) + ((int)fiveCharPayload[4] - 33);

    x1_f = floor(bigNumber / pow(256, 3));
    x1 = x1_f * pow(256, 3);
    x2_f = floor((bigNumber - x1) / pow(256, 2));
    x2 = x2_f * pow(256, 2);
    x3_f = floor((bigNumber - x1 - x2) / pow(256, 1));
    x3 = x3_f * pow(256, 1);
    x4_f = floor((bigNumber - x1 - x2 - x3) / pow(256, 0));

    //cout << x1_f << " " << x2_f << " " << x3_f << " " << x4_f << endl;
    //cout << tekst;
}

void payloadRead()
{
    while (getline(payload, directPayload))
    {
        payloadText += directPayload;
    }
    pos = payloadText.find("<~");
    pos2 = payloadText.find("~>");
    tekst = payloadText.substr(pos + 2, pos2 - pos - 2);
    //cout << payloadText;
}

void displayDecryptedPayload()
{
    ofstream decryptedPayload;
    decryptedPayload.open("de_Payload.txt");
    for (int i = 0; i <= tekst.size(); i += 5)
    {
        fiveCharPayload = tekst.substr(i, 5);
        //cout << fiveCharPayload << '\n';
        stringToASCII();
        char cx1 = char(x1_f);
        char cx2 = char(x2_f);
        char cx3 = char(x3_f);
        char cx4 = char(x4_f);

        decryptedPayload << cx1;
        decryptedPayload << cx2;
        decryptedPayload << cx3;
        decryptedPayload << cx4;
        
    }
    decryptedPayload.close();
}

void payloadRead1()
{
    while (getline(payload1, directPayload))
    {
        payloadText1 += directPayload;
    }
    pos = payloadText1.find("<~");
    pos2 = payloadText1.find("~>");
    payloadText1.replace(payloadText1.find("<~"), sizeof("<~") -1, "");
    payloadText1.replace(payloadText1.find("~>"), sizeof("~>") -1, "");
    tekst1 = payloadText1.substr(pos, pos2);
    //cout << payloadText;
}

void bitShitting()
{
    ofstream decryptedPayload1;
    decryptedPayload1.open("de_Payload1.txt");
    char cx1;
    char cx2;
    char cx3;
    char cx4;

    for (int i = 0; i <= tekst1.size(); i += 5)
    {
        fiveCharPayload = tekst1.substr(i, 5);
        stringToASCII();
        //cout << fiveCharPayload << "";
        char mask = 0b01010101;
        bitset<8> mkanb;
        bitset<8> mkanb1;

        mkanb = bitset<8>(x1_f ^ mask);
        //cout << mkanb << endl;
        mkanb1 = bitset<8>(x1_f ^ mask);

        mkanb >>= 1;
        if (mkanb1[0] == 1)
        {
            mkanb[7] = 1;
            //cout << mkanb1 << endl;
        }

        //cout << mkanb << endl << endl;
        cx1 = char(mkanb.to_ulong());
        //cout << x1_f << " ";
        
        //cout << cx1 << endl << endl;
        //cout << cx1 << endl;

        mkanb = bitset<8>(x2_f ^ mask);
        mkanb1 = bitset<8>(x2_f ^ mask);
        //cout << x2_f << endl;
        mkanb >>= 1;
        if (mkanb1[0] == 1)
        {
            //cout << mkanb << endl;
            mkanb[7] = 1;
        }
        cx2 = char(mkanb.to_ulong());

        mkanb = bitset<8>(x3_f ^ mask);
        mkanb1 = bitset<8>(x3_f ^ mask);
        //cout << x3_f << endl;
        mkanb >>= 1;
        if (mkanb1[0] == 1)
        {
            //cout << mkanb << endl;
            mkanb[7] = 1;
            //cout << mkanb1 << endl;
        }
        cx3 = char(mkanb.to_ulong());

        mkanb = bitset<8>(x4_f ^ mask);
        mkanb1 = bitset<8>(x4_f ^ mask);
        //cout << x4_f << endl;
        mkanb >>= 1;
        if (mkanb1[0] == 1)
        {
            //cout << mkanb << endl;
            mkanb[7] = 1;
            //cout << mkanb1 << endl;
        }
        cx4 = char(mkanb.to_ulong());

        decryptedPayload1 << cx1;
        decryptedPayload1 << cx2;
        decryptedPayload1 << cx3;
        decryptedPayload1 << cx4;
        
    }
    decryptedPayload1.close();
}

void displayDecryptedPayload_L2()
{
    cout << "yeet";
}

int main()
{
    //getline(cin, tekst);
    //tekst = "4[!!l";
    payloadRead();
    displayDecryptedPayload();
    payloadRead1();
    bitShitting();
    //displayDecryptedPayload_L2();

    return 0;
}
