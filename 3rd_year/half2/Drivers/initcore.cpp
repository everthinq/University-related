
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <iostream.h>
#pragma hdrstop

//---------------------------------------------------------------------------
void PartInfo(int n, int partitions, int localdisk, int flag)
 {
        HANDLE hOut;
        DWORD buf=0;
        BYTE asd[512];
        int t=1;
        LARGE_INTEGER li;
        int step = 0;
        unsigned long int type = 0;
        unsigned long int c = 0;
        unsigned long int a = 0;

        li.QuadPart = (__int64)n*(__int64)512;

        hOut = CreateFile("\\\\.\\PhysicalDrive1", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE , NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
        if (hOut != INVALID_HANDLE_VALUE)
        {
                li.LowPart = SetFilePointer(hOut,li.LowPart,&li.HighPart,FILE_BEGIN);
                ReadFile (hOut,&asd, sizeof(asd),&buf,NULL);
                for(int i=446;i<512;i++)
                {
                        //printf("%02x ",asd[i]);
                        //if(t++%16==0) cout<<endl;
                }
                cout<<endl;
                for(int k=0; k<4; k++)
                {

                        type = asd[450+step]&0xFF;
                                if (type != 0)
                                {
                                cout<<"Type is ";
                                switch(type)
                                {
                                        case 0: {cout<<"Empty"<<endl;break;}
                                        case 1: {cout<<"FAT12"<<endl;break;}
                                        case 4: {cout<<"FAT16 <32M"<<endl;break;}
                                        case 5: {cout<<"Extended"<<endl;break;}
                                        case 6: {cout<<"FAT16"<<endl;break;}
                                        case 7: {cout<<"HPFS/NTFS"<<endl;break;}
                                        case 11: {cout<<"FAT32"<<endl;break;}
                                        case 12: {cout<<"FAT32 (LBA)"<<endl;break;}
                                        case 14: {cout<<"FAT16 (LBA)"<<endl;break;}
                                        case 15: {cout<<"FAT16 (LBA)"<<endl;break;}
                                }
                                if ((type != 5)&&(type != 15)) {
                                        BYTE d[]= {asd[457+step],asd[456+step],asd[455+step],asd[454+step]};
                                        c = ((d[0]&0xFF)<<24)+((d[1]&0xFF)<<16)+((d[2]&0xFF)<<8)+(d[3]&0xFF);//sectors before
                                        cout<<"Begin: "<<n+c<<endl;
                                        BYTE b[]= {asd[461+step],asd[460+step],asd[459+step],asd[458+step]};
                                        a = ((b[0]&0xFF)<<24)+((b[1]&0xFF)<<16)+((b[2]&0xFF)<<8)+(b[3]&0xFF);// total sectors
                                        cout<<"End: "<<n+c+a<<endl;
                                        cout<<"Number of partitions: "<<((n+c+a)-(n+c))<<endl; //end - begin
                                        cout<<"Disk size: "<< ((n+c+a)-(n+c)) * 512 << endl;
                                        }
                                else {
                                        BYTE d[]= {asd[457+step],asd[456+step],asd[455+step],asd[454+step]};
                                        c = ((d[0]&0xFF)<<24)+((d[1]&0xFF)<<16)+((d[2]&0xFF)<<8)+(d[3]&0xFF);
                                        cout<<"Begin: "<<n+c<<endl;
                                        BYTE b[]= {asd[461+step],asd[460+step],asd[459+step],asd[458+step]};
                                        a = ((b[0]&0xFF)<<24)+((b[1]&0xFF)<<16)+((b[2]&0xFF)<<8)+(b[3]&0xFF);
                                        cout<<"End: "<<n+c+a<<endl;
                                        cout<<"Number of partitions: "<<((n+c+a)-(n+c))<<endl;
                                        cout<<"Disk size: "<< ((n+c+a)-(n+c)) * 512 << endl;
                                        }
                                if ((type != 5)&&(type != 15)&&(type != 0))partitions+=1;
                                if ((type != 5)&&(type != 15)) cout<<"Number of DISKpartitions = "<<partitions<<endl << endl;
                                }
                                //here gonna be write!!!
                                if ((flag !=1)&&(type != 5)&&(type != 15)&&(localdisk == partitions)) {
                                        flag = 1;
                                        cout<<"-----------------------Start writting-------------------"<<endl;
                                        unsigned long int data = 0;
                                        cout<<"Insert new value for disk size :"<<endl;
                                        cin>>data;
                                        unsigned long int *ptr = (unsigned long int*)(asd+458);
                                        cout<<"Current size: "<<*ptr<<endl;
                                        BYTE bytes[4];
                                        bytes[0] = data&0x000000FF;
                                        bytes[1] = (data&0x0000FF00)>>8;
                                        bytes[2] = (data&0x00FF0000)>>16;
                                        bytes[3] = (data&0xFF000000)>>24; //ELDER bytes
                                        for(int j=0; j<4; j++)
                                        {
                                                printf("%02x ",bytes[j]);
                                                asd[458+step+j] = bytes[j];
                                                cout<<endl;
                                        }
                                        cout<<"Calling writting function ... "<<endl;
                                        int t=1;
                                        for(int i=446;i<512;i++)
                                        {
                                                printf("%02x ",asd[i]);
                                                if(t++%16==0) cout<<endl;
                                        }
                                        cout<<endl;
                                        li.LowPart = SetFilePointer(hOut,li.LowPart,&li.HighPart,FILE_BEGIN);
                                        WriteFile (hOut,&asd, sizeof(asd),&buf,NULL);
                                        cout<<"Writting function is ended."<<endl;
                                        cout<<"-------------------------End writting-------------------"<<endl;
                                        getch();

                                }
                                step += 16;
                                if (n == 0) n = c;
                                else if ((type == 5) || (type == 15))
                                {
                                        n = c;
                                        PartInfo(n, partitions, localdisk, flag);}
                                }
                CloseHandle(hOut);
        }
        else cout<<"Can't open core..."<<endl;
 }
#pragma argsused
int main(int argc, char* argv[])
{
    int partitions = 0;
    int localdisk = 0;
    int flag = 0;
    unsigned long int n=0;
    cout<<"Insert disk number : "<<endl;
    cin>>localdisk;
    PartInfo(n, partitions, localdisk, flag);


    //int t = 0xABCDFFAF;
    //t = (t&0x000000FF);
    //printf("%x", t);

    getch();
}
//---------------------------------------------------------------------------


