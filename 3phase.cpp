#include <iostream>
#include <iomanip>
using namespace std;
float totUV(float maxVa ,float maxVb ,float maxVc) {
        return (maxVa > maxVb) ? (maxVa > maxVc ? maxVa : maxVc) : (maxVb > maxVc ? maxVb : maxVc);
        }
float totUI(float maxIa ,float maxIb ,float maxIc) {
        return (maxIa > maxIb) ? (maxIa > maxIc ? maxIa : maxIc) : (maxIb > maxIc ? maxIb : maxIc);
        }
int main() {
    float va, vb, vc;
    int menu;
    char pilihulang;
    float ia, ib, ic;
    float  maxVa, maxVb, maxVc;
    float maxIa, maxIb, maxIc;
    float averUV,UVaver,maks;
    float averUI, UIaver,maksUI;
do {
    cout << "Selamat datang di Program Ketidakseimbangan 3 Phase" << endl;
    do {
    //decision voltage & current
    cout << "Berikut menu perhitungan program ketidakseimbangan 3 phase : " << endl;
    cout << "1. Tegangan " << endl;
    cout << "2. Arus " << endl;
    cout << "Apakah anda ingin menghitung tegangan / arus ? : ";
    cin >> menu;
    if ( menu == 0 || menu <= 0 || menu > 2){
        cout << "Inputan anda tidak valid, silahkan input kembali!" << endl;
    }
    } while (menu == 0 || menu <= 0 || menu > 2);

    //decision current or voltage
    if (menu == 1){
        cout << "Input Tegangan 3 Phase" << endl;
        cout << "Silahkan masukkan tegangan a (VR) : ";
        cin >> va;
        cout << endl;
        cout << "Silahkan masukkan tegangan b (VS) : ";
        cin >> vb;
        cout << endl;
        cout << "Silahkan masukkan tegangan c (VT) : ";
        cin >> vc;
        cout << endl;

        // Rumus UV (Tegangan rata-rata)
        float averageVoltage = (va + vb + vc) / 3;
        maxVa = va - averageVoltage;
        maxVb = vb - averageVoltage;
        maxVc = vc - averageVoltage;
        averUV = averageVoltage;

        // Total UV
        if (averUV != 0) { // Menangani pembagian dengan nol
        float maks = totUV(maxVa ,maxVb ,maxVc);
            UVaver = (maks / averageVoltage) * 100;
            cout << "percentage ketidakseimbangan 3 phase tegangan sebesar : " << setprecision(3) << UVaver << "%" << endl;
        } else {
            cout << "Rata-rata tegangan tidak boleh nol." << endl;
        }
    } else if (menu == 2) {        
        cout << "Input Current 3 Phase" << endl;
        cout << "Silahkan masukkan arus a (IR) : ";
        cin >> ia;
        cout << endl;
        cout << "Silahkan masukkan arus b (IS) : ";
        cin >> ib;
        cout << endl;
        cout << "Silahkan masukkan arus c (IT) : ";
        cin >> ic;
        cout << endl;

        // Rumus UI (Arus rata-rata)
        float averageCurrent = (ia + ib + ic) / 3;
        maxIa = ia - averageCurrent;
        maxIb = ib - averageCurrent;
        maxIc = ic - averageCurrent;
        averUI = averageCurrent;

        // Total UI
        if (averUI != 0) { // Menangani pembagian dengan nol
        float maksUI = totUI(maxIa ,maxIb ,maxIc);
            UIaver = (maksUI / averageCurrent) * 100;
            cout << "percentage ketidakseimbangan 3 phase tegangan sebesar : " << setprecision(3) << UIaver << "%" << endl;
        } else {
            cout << "Rata-rata arus tidak boleh nol." << endl;
        }
    
    }
    
//iterasi order
    cout << "Apakah anda ingin menggunakan program kembali? (Y/N)";
    cin >> pilihulang;
    //for voltage
    
}   while (pilihulang == 'Y' || pilihulang == 'y');
    cout << "Terima kasih telah menggunakan program ini" << endl;
    return 0;
}
