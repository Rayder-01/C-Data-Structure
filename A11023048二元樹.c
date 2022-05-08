#include <stdio.h>
#include <stdlib.h>

#define Num 20
void CreateBinaryTree(int*, int);
void Postorder(int);
void Inorder(int);
void Preorder(int);

int data[Num]={0};
int BinaryTree[Num]={0};

int main(void) {
    int n,i;
    printf("��J�`�I�ӼơG");
    scanf("%d", &n);
    printf("��J %d �Ӹ`�I�����e�G\n", n);
    for(i=0; i<n; i++) {
    	printf("�� %d �Ӹ`�I�����e�G", i+1);
       scanf(" %d", &data[i]);
    }
    CreateBinaryTree(data, n); //�I�s�إߤG����
    printf("�e�Ǫ����G�G\n");
    Preorder(1);   //�e��
    printf("\n");
    printf("���Ǫ����G�G\n");
    Inorder(1);   //����
    printf("\n");
    printf("��Ǫ����G�G\n");
    Postorder(1);   //���
    printf("\n");
    system("PAUSE");
    return 0;
}

void CreateBinaryTree(int data[], int n) {   //�إߤG����
    int node=1, temp;
    int i;
    for (i=0; i<Num; i++) {BinaryTree[i]=0;}  //��ȳ]�w
    for (i=0; i<n; i++) {
        BinaryTree[node]=data[i];
        node=node + 1;
        }
}

void Postorder(int node) {   //��ǰl��
    if (BinaryTree[node] != 0) {
         Postorder(2*node);    //���j���l��
         Postorder(2*node+1);  //���j�k�l��
         if (BinaryTree[node] != 0) {  //�C�L���
             printf("%d ",BinaryTree[node]);
             }
         }
    }

void Inorder(int node) {  //���ǰl��
    if (BinaryTree[node] != 0) {
        Inorder(2*node);   //���j���l��
        if (BinaryTree[node] != 0) {  //�C�L���
            printf("%d ", BinaryTree[node]);
            }
        Inorder(2*node+1);  //���j�k�l��             
        }
    }

void Preorder(int node) {  //�e�ǰl��
    if (BinaryTree[node]!=0) {
         if (BinaryTree[node]!=0) {
             printf("%d ",BinaryTree[node]);  //�C�L���
             }
         Preorder(2*node);    //���j���l��
         Preorder(2*node+1);  //���j�k�l��
         }
    }
