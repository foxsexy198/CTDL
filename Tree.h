#include <stdio.h>
//Khai bao cay
struct Node{
   int Data;
   struct Node *Left, *Right;
};
typedef struct Node* Tree;


//Khoi tao cay rong
Tree initTree(){
    Tree T = (struct Node*)malloc(sizeof(struct Node));
    T = NULL;
    return T;
}
//Kiem tra cay rong
int isEmpty(Tree T){
    return T == NULL;
}
//Tao nut co gia tri x
Tree createNode(int x){
   struct Node* N;
   N=(struct Node*)malloc(sizeof(struct Node));
   Data=x;
   Left=NULL;
   Right=NULL;
   return N;
}
//Tra ve con trai
Tree leftChild(Tree T){
	if(isEmptyTree(T))
		return NULL;
	return T->Left;
}
//Tra ve con phai
Tree rightChild(Tree T){
	if(isEmptyTree(T))
		return NULL;
	return T->Right;
}
//in cay duyet tien tu
void preOrder(Tree T){
	if(!isEmptyTree(T)){
		printf("%d ", T->Data);
		preOrder(leftChild(T));
		preOrder(rightChild(T));
	}
}
//in cay duyet trung tu
void inOrder(Tree T){
    if(!emptyTree(T)){
        inOrder(leftChild(T));
        printf("%d ", T->Data);
        inOrder(rightChild(T));
    }
}
//in cay duyet hau tu
void postOrder(Tree T){
    if(!emptyTree(T)){
        postOrder(leftChild(T));
        postOrder(rightChild(T));
        printf("%d ", T->Data);
    }
}
//Do cao cua cay
int getHeight(Tree T){
    if(T == NULL)
        return -1;
    else{
        int max = getHeight(T->Left);
        if(getHeight(T->Right) > max)
            max = getHeight(T->Right);
        return max + 1;
    }
}
//Dem so nut la cua cay
int getLeaves(Tree T){
    if(T == NULL)
        return 0;
    if(T->Left == 0 && T->Right == 0)
        return 1;
    else
        return getLeaves(T->Left) + getLeaves(T->Right);
}
//Tim chir mucj cua mot ky tu x trong chuoi trung tu in bat dau tu vi tri start den end
int findIndex(DataType x, char in[], int star, int end){
    int i=star;
    while (i<=end){
         if (x==in[i])
             return i;
 
       else
             i++;
   }
   return i;
}
//Dung cay nhi phan tu cac bieu thuc duyet tien tu va trung tu
//int preIndex = 0;
Tree createTree(char pre[], char in[], int in_start, int in_end){
    if(in_start > in_end)
        return NULL;
    
    Tree T = createNode(pre[preIndex++]);    
        
    if (in_start < in_end){
        int inIndex = findIndex(pre[preIndex-1], in, in_start, in_end);
        T->Left = createTree(pre, in, in_start, inIndex-1);
        T->Right = createTree(pre, in, inIndex+1, in_end);
    }
    return T;
}
//Tim gia tri lon nhat trong cay nhi phan
//#include <math.h>
DataType findMax(Tree T){
    if(T == NULL)
        return 0;
    DataType max = T->Data;
    if(T->Left != NULL)
        max = fmax(max, findMax(T->Left));
    if(T->Right != NULL)
        max = fmax(max, findMax(T->Right));
    return max;
}
//Tim va tra ve gia tri x trong cay
Tree findElement(DataType x, Tree T){
    if(T == NULL)
        return NULL;
    if(x == T->Data)
        return T;
    Tree tmp = findElement(x, T->Left);
    if (tmp != NULL)
        return tmp;
    return findElement(x, T->Right);
}
//Tinh duong kinh cua mot cay
void getDiameter(Tree T, int *n){
    if(T != NULL){
        *n = max(getHeight(T->Left) + getHeight(T->Right) + 3, *n);
        getDiameter(T->Left, n);
        getDiameter(T->Right, n);
    }
}
//Dem so nut co du 2 con
int getFullNodes(Tree T){
    if(T == NULL || isLeaf(T))
        return 0;
    if(T->Left == NULL)
        return getFullNodes(T->Right);
    if(T->Right == NULL)
        return getFullNodes(T->Left);
    return 1 + getFullNodes(T->Left) + getFullNodes(T->Right);
}
//Tao cay phan chieu
Tree convertTree(Tree T){
    if (T == NULL)
        return NULL;
    Tree P = createNode(T->Data);
    P->Left = convertTree(T->Right);
    P->Right = convertTree(T->Left);
    return P;
}
//Kiem tra xem 2 cay co la phan chieu cua nhau hay khong
int isMirrors(Tree T1, Tree T2){
    if (emptyTree(T1) && emptyTree(T2))
        return 1;
    if ((emptyTree(T1) && !emptyTree(T2)) || (!emptyTree(T1) && emptyTree(T2)))
        return 0;
    if (T1->Data != T2->Data)
        return 0;
    return isMirrors(T1->Left, T2->Right) && isMirrors(T1->Right, T2->Left);
}
//in noi dung cua mang path co do dai len
void printArray(int path[], int len){
 int i;
 for(i=0;i<len;i++)
    printf("%d",path[i]);
    printf("\n");
}
//Hien rhi tat ca cac duong di (tu nut goc den nut la)
void printAllPaths(Tree T, DataType path[], int len, int pathlen){
    if (T != NULL){
        path[len++] = T->Data;
        if (isLeaf(T) && pathlen == 0)
            printArray(path, len);
        else if (pathlen > 0){
            printAllPaths(T->Left, path, len, pathlen-1);
            printAllPaths(T->Right, path, len, pathlen-1);
        }
    }
}
//Tra ve nut cha cua x
Tree getParent(int x, Tree T){
    if(T == NULL)
        return NULL;
    if((T->Left != NULL && T->Left->Key == x) || (T->Right != NULL && T->Right->Key == x))
        return T;
    if(T->Key > x)
        return getParent(x, T->Left);
    return getParent(x, T->Right);
}
//Tinh chieu cao cua khoa x trong cay
int hNode(int x, Tree T){
    if(T == NULL)
        return -1;
    else if(x == T->Key)
        return getHeight(T);
    else if(x < T->Key)
        return hNode(x, T->Left);
    else
        return hNode(x, T->Right);
}
//Tra ve nut anh em ruot phai cua x
Tree rightSibling(int x, Tree T){
    if (T == NULL)
        return NULL;
    if (T->Left != NULL && T->Left->Key == x )
        return T->Right;
    if (T->Right != NULL && T->Right->Key == x)
        return NULL;
    if(x < T->Key)
        return rightSibling(x, T->Left);
    return rightSibling(x,  T->Right);
}
//Xoa nut nho nhat ben trai cua cay
int deleteMin(Tree *pT){
    int k;
    Tree tmp;
    if((*pT)->Left == NULL){
        k = (*pT)->Key;
        tmp = *pT;
        *pT = (*pT)->Right;
        free(tmp);
        return k;
    }
    else
        return deleteMin(&(*pT)->Left);
}
//Xoa mot nut trong cay
void deleteNode(int x, Tree *pT){
    if(*pT != NULL){
        if(x < (*pT)->Key)
            deleteNode(x, &(*pT)->Left);
        else if(x > (*pT)->Key)
            deleteNode(x, &(*pT)->Right);
        else{
            Tree tmp;
            if((*pT)->Left == NULL && (*pT)->Right == NULL){
                tmp = *pT;
                *pT = NULL;
                free(tmp);
            }
            else if((*pT)->Left != NULL && (*pT)->Right == NULL){
                tmp = (*pT);
                *pT = (*pT)->Left;
                free(tmp);
            }   
            else if((*pT)->Left == NULL && (*pT)->Right != NULL){
                tmp = (*pT);
                *pT = (*pT)->Right;
                free(tmp);
            }
            else if((*pT)->Left != NULL && (*pT)->Right != NULL)
                (*pT)->Key = deleteMin(&(*pT)->Right);
        }
    }
        
}
//in cac gia tri khoa tren duong di cua viec tim kiem khoa x
void printPath(int x, Tree T){
    if(T == NULL)
        printf("-> Khong thay");
    else if(x == T->Key)
        printf("%d -> Tim thay", T->Key);
    else if(x < T->Key){
        printf("%d ", T->Key);
        printPath(x, T->Left);
    }
    else{
        printf("%d ", T->Key);
        printPath(x, T->Right);
    }
        
}
//Them x vao cay 
void insertNode(int x, Tree *pT){
    if((*pT) == NULL){
        (*pT) = (struct Node*)malloc(sizeof(struct Node));
        (*pT)->Key = x;
        (*pT)->Left =   NULL;
        (*pT)->Right = NULL;
    }
    else if(x < (*pT)->Key)
        insertNode(x, &(*pT)->Left);
    else if(x > (*pT)->Key)
        insertNode(x, &(*pT)->Right);
}
//Tra ve con trai nhat (nho nhat) ben trai
Tree getMin(Tree T){
    if(T == NULL)
        return NULL;
    else if(T->Left == NULL)
        return T;
    return getMin(T->Left);
}
//Tra ve con phai nhat (lon nhat) ben phai
Tree getMax(Tree T){
    if(T == NULL)
        return NULL;
    else if(T->Right == NULL)
        return T;
    return getMax(T->Right);
}
//Tra ve nut dung truoc x - trung tu
Tree getPrevious(int x, Tree T){
    if(T == NULL)
        return NULL;
    if(T->Key == x)
        if(T->Left != NULL)
            return getMax(T->Left);
    
    Tree t = getMin(T->Right);
    if(t != NULL)
        if(t->Key == x)
            return T;
        
    if(x < T->Key)
        return getPrevious(x,T->Left);
    return getPrevious(x,T->Right);
    
}
//Tim va tra ve khoa x trong cay
Tree searchNode(int x, Tree T){
    if (T == NULL)
        return NULL;
    if (T->Key == x)
        return T;
    if (T->Key < x)
        return searchNode(x, T->Right);
    return searchNode(x, T->Left);
}
//Tra ve nut dung sau x - trung tu
Tree getNext(int x, Tree T){
    if (T == NULL)
        return NULL;
    if (T->Key == x)
        return getMin(T->Right);
    Tree res = getMax(T->Left);
    if (res != NULL && res->Key == x)
        return T;
    if (T->Key < x)
        return getNext(x, T->Right);
    return getNext(x, T->Left);
}
//Tra ve nut la toan hang trai nhat cua cay
Tree findLMOperand(Tree T){
    if(T == NULL)
        return NULL;
    else if(T->Left == NULL)
        return T;
    return findLMOperand(T->Left);
}
//in cac nut co cung chieu cao h
void printNodes(Tree T, int h){
    if(T != NULL){
        if(getHeight(T) == h)
            printf("%c ", T->Data);
        printNodes(T->Left, h);
        printNodes(T->Right, h);
    }
}
//Tinh va tra ve gia tri cua cay 
float compute(float a, float b, char c){
    if (c == '+')
        return a + b;
    if (c == '-')
        return a -b;
    if (c == '*')
        return a*b;
    if (c == '/')
        return 1.0*a/b;
    return (int)a % (int)b;
}

float solve(Tree T){
    if (T == NULL)
        return 0;
    if (isLeaf(T)) // convert from Character to Digit
        return T->Data -'0';
    return compute(solve(T->Left), solve(T->Right), T->Data);
}

float findValue(DataType x, Tree T){
    return solve(findElement(x, T));
}

//Kiem tra mot cay co la cay bieu thuc hay khong
int isDigit(char c){
    return '0' <= c && c <= '9';
}

int isExprTree(Tree T){
    if (T == NULL)
        return 1;
    if (isLeaf(T) && !isDigit(T->Data))
        return 0;
    if (!isLeaf(T) && isDigit(T->Data)) // la Toan Hang thi khong la Toan Tu 
        return 0;
    // Cay bieu thuc la cay nhi phan day du
    // -> Tat ca cac Node deu phai co 2 con
    if ((T->Left == NULL && T->Right != NULL) || (T->Left != NULL && T->Right == NULL))
        return 0;
    return isExprTree(T->Left) && isExprTree(T->Right);
}
//Tim va tra ve do sau cua nut co khoa x
int findLevel(KeyType x, Tree T){
    if(T == NULL)
        return -1;
    else if(x == T->Key)
        return 0;
    if(x > T->Key)
        return findLevel(x, T->Right) + 1;
    return findLevel(x, T->Left) + 1;
}
//Dem so nut tu nut goc den nut co khoa x
int countNodes(KeyType x, Tree T){
    if(T == NULL)
        return 0;
    else if(x == T->Key)
        return 1;
        
    if(x < T->Key)
        return 1+countNodes(x, T->Left);
    return 1+countNodes(x, T->Right);
}
//Cap nhat lai do sau cua tung nut
void updateLevel(Tree *pT, Tree T){
    if (T != NULL){
        if (T->Left != NULL){
            (*pT)->Left->Level = T->Level+1;
            updateLevel(&(*pT)->Left, T->Left);
        }
        if (T->Right != NULL){
            (*pT)->Right->Level = T->Level+1;
            updateLevel(&(*pT)->Right, T->Right);
        }
    }
}
