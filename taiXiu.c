#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
int a = 5;
void login()
{
    int name, password;
    printf("\n=>> Ten Dang Nhap : ");
    scanf("%d", &name);
    printf("=>> Mat Khau : ");
    scanf("%d", &password);
    if (name !=1 || password!=2004)
    {
        printf("\n=>> Ten Dang Nhap Hoac Mat Khau Sai !");
        exit(0);
    }
    else
    {
        printf("\n=>> Dang Nhap Thanh Cong !\n");
    }
    for (int i = 0; i < 45; i++)
    {
        Sleep(50);
        printf("%c", a);
    }
}
int check()
{
    int age;
    printf("\nNhap Vao Tuoi Cua Ban (Tuoi >= 18) : ");
    scanf("%d", &age);
    if (age < 18)
    {
        printf("\n=>> Ban Khong Du Tuoi De Choi Tro Nay !");
        exit(0);
    }
    printf("\n");
    for (int i = 0; i < 45; i++)
    {
        Sleep(50);
        printf("%c", a);
    }
}
// hàm này sẽ random các con số trong mặt xúc sắc (random từ 1 đến 6)
int random(int minN, int maxN)
{
    return minN + rand() % (maxN + 1 - minN);
}
/*
*hàm processing này sẽ xử lí và lấy ngẫu nhiễn 1 con số đã random trong xúc sắc và Xử lí kết quả
*người chơi đặt cược
- sô tiền đặt cược
- sau khi đạt cược số tiền hiện tại = tiền - số tiền cược
  + nếu người chơi chọn tài mà kết quả ra xỉu thì số tiền = số tiền - tiền cược -> thua
  + nếu người chơi chọn đúng thì số tiền = số tiền + tiền cược -> thắng
*nếu ketqua = 4 & 10 => Tai
*nếu  ketqua = 11 & 17 => Xiu
*/
void processing()
{
    int diceOne, diceTwo, diceThree;
    int money = 500000000, tienCuoc;
    int option, luaChon;
    do
    {
        printf("\n================Moi Ban Chon=================");
        printf("\n\t(1). Nhan 1 De Chon Tai ");
        printf("\n\t(2). Nhan 2 De chon Xiu ");
        printf("\n\t(0). Thoat");
        printf("\n=============================================");
        printf("\n>>> Moi Ban Nhap Lua Chon : ");
        scanf("%d", &option);
        if (option == 0)
        {
            exit(0);
        }
        printf("\n");
        for (int i = 0; i < 45; i++)
        {
            Sleep(50);
            printf("%c", a);
        }
        printf("\nSo Tien Hien Tai Cua Ban La : %d ", money);
        printf("\nNhap So Tien Cuoc(Toi Thieu 10000) : ");
        scanf("%d", &tienCuoc);
        if (tienCuoc > money || tienCuoc < 10000)
        {
            printf("\n=>> Ban Khong Du Tien Choi !");
            exit(0);
        }
        else
        {
            printf("\n=>> So Tien Con Lai Sau Khi Cuoc : %d", money - tienCuoc);
            printf("\n=>> BAN DA VAO GAME !\n");
        }
        for (int i = 0; i < 45; i++)
        {
            Sleep(50);
            // printf("\n");
            printf("%c", a);
        }
        if (option == 1)
        {
            int c = 175;
            printf("\nBan Da Cuoc Tai Vui Long Cho Ket Qua : ");
            // tgian chờ kết quả
            for (int i = 0; i < 5; i++)
            {
                Sleep(300);
                printf("%c", c);
            }
        }
        else
        {
            int c = 175;
            printf("\nBan Da Cuoc Xiu Vui Long Cho Ket Qua : ");
            // tgian chờ kết quả
            for (int i = 0; i < 5; i++)
            {
                Sleep(300);
                printf("%c", c);
            }
        }
        srand((int)time(0));
        // vòng lặp xửxử lí xúc xắc 1
        for (int i = 1; i < 6; ++i)
        {
            diceOne = random(1, 6);
            diceOne %= 10;
        }
        printf("\n->> Con Xuc Xac 1 :  %d ", diceOne);
        // vòng lặp xử lí xúc xắc 2
        for (int i2 = 1; i2 < 6; ++i2)
        {
            diceTwo = random(1, 6);
            diceTwo %= 10;
        }
        printf("\n->> Con Xuc Xac 2 :  %d ", diceTwo);
        // vòng lặp xử lí xúc xắc 3
        for (int i3 = 1; i3 < 6; ++i3)
        {
            diceThree = random(1, 6);
            diceThree %= 10;
        }
        printf("\n->> Con Xuc Xac 3 :  %d ", diceThree);

        // xử lí in ra kết quả
        int result = diceOne + diceTwo + diceThree;
        // kiểm tra lựa chọn của người chơi nếu người chơi chọn Tai
        if (option == 1)
        {
            if (result >= 11 && result <= 17)
            {
                printf("\n=>> Ket Qua : Tai");
                printf("\n=>> Chuc Mung Ban Da Thang ");
                money += tienCuoc;
                printf("\n=>> So Tien Hien Tai Cua Ban La : %d", money);
            }
            else if (result >= 4 && result <= 10)
            {
                printf("\n=>> Ket Qua : Xiu");

                printf("\n=>> Ban Da Thua ");
                printf("\n=>> Chuc Ban May Man Lan Sau  ");
                money -= tienCuoc;
                printf("\n=>> So Tien Hien Tai Cua Ban La : %d", money);
                if (money == 0)
                {
                    exit(0);
                }
            }
            else
            {
                printf("\n=>> Bi Lua Roi Nha !");
                exit(0);
            }
        }
        // kiểm tra lựa chọn của người chơi nếu người chơi chọn Xiu
        else if (option == 2)
        {
            if (result >= 4 && result <= 10)
            {
                printf("\n=>> Ket Qua : Xiu");
                printf("\n=>> Chuc Mung Ban Da Thang  ");
                money += tienCuoc;
                printf("\n=>> So Tien Hien Tai Cua Ban La : %d\n", money);
            }
            else if (result >= 11 && result <= 17)
            {
                printf("\n=>> Ket Qua : Tai");
                printf("\n=>> Ban Da Thua ");
                printf("\n=>> Chuc Ban May Man Lan Sau  ");
                money -= tienCuoc;
                printf("\n=>> So Tien Hien Tai Cua Ban La : %d", money);
                if (money == 0)
                {
                    exit(0);
                }
            }
            else
            {
                printf("\n=>> Bi Lua Roi Nha !\n");
                exit(0);
            }
        }
        else
        {
            printf("\nLoi : Ban Lua Chon Khong Dung !\n");
        }

        printf("\n");
        for (int i = 0; i < 45; i++)
        {
            Sleep(50);
            printf("%c", a);
        }
        printf("\n=>>Nhap so bat ki de tiep tuc. Nhap 0 de thoat : ");
        scanf("%d", &luaChon);
    } while (luaChon != 0);
}
void byCopyright()
{
    int ki_tu = 64;
    printf("=>> %c BY COPYRIGHT : PHAM TIEN DUC \n", ki_tu);
    for (int i = 0; i < 45; i++)
    {
        Sleep(50);
        printf("%c", a);
    }
}
int main()
{
    system("color 2");
    byCopyright();
    printf("\n");
    login();
    printf("\nChoi Game Qua 180p Moi Ngay Co Anh Huong Cho Suc Khoe !");
    check();
    processing();
    return 0;
}