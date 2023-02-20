

// Khai bao ds lien ket
typedef int ElementType;	//kieu phan tu
struct Node{
	ElementType Element;	//chua noi dung phan tu
	struct Node *Next;		// co tro chi den phan tu ke tiep
};
typedef struct Node *Position;	//kieu vi tri
typedef Position List;			// kieu danh sach


// Khoi tao ds rong
void makenullList(List *pL){
	(*pL) = (struct Node*)malloc(sizeof(struct Node));
	(*pL)->Next = NULL;
}

// kiem tra danh sach rong
int emptyList(List L){
	return L->Next == NULL;
}

// tim vi tri xuat hien dau tien
Position locate(ElementType x, List L){
	Position P = L;
	while(P->Next != NULL){
		if(retrieve(P, L) == x)
			return P;
	}
}

// noi dung tai vi tri P
ElementType retrieve(Position P, List L){
	if(L->Next != NULL)
		return P->Next->Element;
}

// vi tri dau tien trong ds

Position firstList(List L){
	return L;
}

// vi tri sau vi tri cuoi cung
Position endList(List L){
	Position P = L;
	while(P->Next != NULL)
		P = P->Next;
	return P;
}

// xac dinh vi tri phan tu ke tiep
Position next(Position P, List L){
	return P->Next;
}

// vi tri phan tu truoc do
Position previous(Position P, List L){
	Position Q = L;
	while(Q->Next != P)
		Q = Q->Next;
	return Q;
}

// chen phan tu x vao vi tri dau tien
void addFirst(ElementType x, List *pL){
	Position P = *pL;
	Position T = (struct Node*)malloc(sizeof(struct Node));
	T->Element = x;
	T->Next = P->Next;
	P->Next = T;
}

// chen phan tu x vao vi tri P trong ds
void insertList(ElementType x, Position P, List *pL){
	Position T = (struct Node*)malloc(sizeof(struct Node));
	T->Element = x;
	T->Next = P->Next;
	P->Next = T;
}

// xoa vi tri P trong ds
void deleteList(Position P, List *pL){
	Position tmp = P->Next;
	P->Next = T->Next;
	free(tmp);
}

// noi phan tu x vao ds
void append(ElementType x, List *pL){
	Position P = endList(*pL);
	Position T = (struct Node*)malloc(sizeof(struct Node));
	T->Element = x;
	P->Next = T;
	T->Next = NULL;
}

// nhap ds
List readSet(){
	List L;
	makenullList(&L);
	int n;
	scanf("%d", &n);
	ElementType x;
	while(n--){
		scanf("%d", &x);
		if(!member(x, L))
			addFirst(x, &L);
	}
	return L;
}

// xoa tat ca phan tu x trong ds
void deleteX(ElementType x, List *pL){
	Position P = locate(x, *pL);
	while(P->Next != NULL){
		if(retrieve(P, *pL) == x)
			deleteList(P, pL);
		else
			P = next(P, *pL);
	}
}

// tinh trung binh cong
float getAvg(List L){
	int n = 0;
	float sum = 0;
	Position P = L;
	if(emptyList(L))
		return -10000.0f;
	else{
		while(P->Next != NULL){
    		sum += retrieve(P, L);
    		n++;
		P = next(P, L);
		}
	}
	
	return sum/n;
}

// kiem tra phan tu x co trong ds hay khong
ElementType retrieve(Position P, List L){
	return P->Next->Element;
}
int member(ElementType x, List L){
	Position P = L;
	while(P->Next != NULL){
		if(retrieve(P, L) == x)
			return 1;
		P = P->Next;
	}
	return 0;
}
