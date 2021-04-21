#include <iostream>
#define MAX 1000
using namespace std;

void ShowMenu()
{
    cout << "*************************" << endl;
    cout << "***** 1�������ϵ�� *****" << endl;
    cout << "***** 2����ʾ��ϵ�� *****" << endl;
    cout << "***** 3��ɾ����ϵ�� *****" << endl;
    cout << "***** 4��������ϵ�� *****" << endl;
    cout << "***** 5���޸���ϵ�� *****" << endl;
    cout << "***** 6�������ϵ�� *****" << endl;
    cout << "***** 0���Ƴ�ͨѶ¼ *****" << endl;
    cout << "*************************" << endl;
}

struct contact
{
    string name;
    int sex;
    string phonenumber;
};

struct contacts
{
    contact contacts[MAX];
    int number;//ͨѶ¼����
};

void addContact(contacts &person)
{
    if(person.number == MAX)
    {
        cout << "ͨѶ¼����,�޷���ӡ�\n";
    }
    else
    {
        //�������
        string addname;
        cout << "������������";
        cin >> addname;
        person.contacts[person.number].name = addname;
        //��ӵ绰����
        string phone;
        cout << "������绰���룺";
        cin >> phone;
        person.contacts[person.number].phonenumber = phone;
        //����Ա�
        int sex;
        while(true)
        {
            cout << "�������Ա���1orŮ0��:";
            cin >> sex;
            if(sex == 1 || sex == 0)
            {
                person.contacts[person.number].sex = sex;
                break;
            }
            else
                cout << "��������ȷ�Ա�";
        }

        person.number++;
    }
}

void showContact(contacts person)
{
    if(person.number == 0)
    {
        cout << "��ϵ��Ϊ��\n";
    }
    else
    {
        for(int i = 0; i < person.number; i++)
        {
            cout << "������ " << person.contacts[i].name;
            string p_sex;
            if(person.contacts[i].sex == 1)
            {
                p_sex = "��";
            }
            else
            {
                p_sex = "Ů";
            }
            cout << "     �Ա�:  " << p_sex;

            cout << "     �绰:  " << person.contacts[i].phonenumber << endl;
        }
    }
}

int IsExist(contacts person, string p_name)//�ж���ϵ���Ƿ����
{
    if(person.number == 0)
    {
        cout << "��ϵ��Ϊ��\n";
    }
    else
    {
        for(int i = 0; i < person.number; i++)
        {
            if(p_name == person.contacts[i].name)
                return i;
        }
        return -1;
    }
    return -1;
}

void DeleteContact(contacts &person)//ɾ����ϵ��
{
    cout << "Pleas input a contact name you want to delete : \n";
    string p_name;
    cin >> p_name;
    if(IsExist(person, p_name) != -1)
    {
        int ret = IsExist(person, p_name);
        for(; ret < person.number; ret++)
        {
            person.contacts[ret] = person.contacts[ret+1];
            person.number--;
            cout << "ɾ���ɹ���\n";
        }
    }
    else
    {
        cout << "���޴��ˣ�\nɾ��ʧ�ܣ�\n";
    }

}

void FindContact(contacts person)//����
{
    cout << "Pleas input a contact name you want to find : \n";
    string p_name;
    cin >> p_name;
    int ret = IsExist(person, p_name);
    if(ret != -1)
    {
        cout << "���� ��" << person.contacts[ret].name << endl;
        string p_sex;
            if(person.contacts[ret].sex == 1)
            {
                p_sex = "��";
            }
            else
            {
                p_sex = "Ů";
            }
        cout << "     �Ա�:  " << p_sex;
        cout << "�绰 ��" << person.contacts[ret].phonenumber << endl;
    }
    else
    {
        cout << "���޴��ˣ�\n����ʧ�ܣ�\n";
    }
}

void ModifyContact(contacts &person)//�޸�
{
    cout << "Pleas input a contact name you want to modify : \n";
    string p_name;
    cin >> p_name;

    int ret = IsExist(person, p_name);

    if(ret != -1)
    {
        string phone;
        cout << "Pleas updata the contact phone number: \n";
        cin >> phone;
        person.contacts[ret].phonenumber = phone;

        int sex;
        cout << "Pleas updata the contact sex(1--man or 0--woman): \n";
        cin >> sex;
        person.contacts[ret].sex = sex;
    }
    else
    {
        cout << "���޴���!\n";
    }

}

void ClearContacts(contacts &person)//���
{
    person.number = 0;
}

int main()
{
    contacts person;
    person.number =0;
    //��ʼ��;

    int slec = 0, slec1 = 0;

    while(1)
    {
        ShowMenu();

        cin >> slec;

        switch(slec)
        {
        case 1://�����ϵ��
            addContact(person);
            break;
        case 2://��ʾ��ϵ��
            showContact(person);
            break;
        case 3://ɾ����ϵ��
            DeleteContact(person);
            break;
        case 4://������ϵ��
            FindContact(person);
            break;
        case 5://�޸���ϵ��
            ModifyContact(person);
            break;
        case 6://���ͨѶ¼
            ClearContacts(person);
            break;
        case 0:
            cout << "��ӭ�´�ʹ�ã�\n";
            return 0;
            break;
        default:
            break;
        }

        cout << "�����밴1:\n";

        cin >> slec1;

        switch(slec1)
        {
        case 1:
            system("cls");
            break;
        default:
            return 0;
            break;
        }

    }

    return 0;
}
