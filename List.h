#define MaxLength 100

typedef int ElementType;
typedef int Position;
typedef struct{
	ElementType Elements[MaxLength];
	Position Last;
}List;

//cac ham co ban

//khoi tao ds rong
void makenullList(List *pL){
	*pL = 0;
}
//kiem tra ds rong
int emptyList(List L){
	return L.Last == 0;
}
//kiem tra ds day
int fullList(List L){
	return L.Last == MaxLength;
}
//vi tri cuoi cung
Position endList(List L){
	return L.Last+1;
}
//vi tri dau tien
Position firstList(List L){
	return 1;
}
//vi tri ke tiep
Position next(Position P, List L){
	return P++;
}
//them phan tu vao vi tri P trong ds
void insertList(ElementType x, Position P, List *pL){
	if(P < firstList(*pL) || P > endList(*pL))
		printf("Vi tri khong hop le!");
	else if(fullList(*pL))
		printf("Danh sach day!");
	else{
		Position Q;
		for(Q = pL->Last; Q >= P; Q--)
			pL->Elements[Q] = pL->Elements[Q-1];
		pL->Elements[P-1] = x;
		pL->Last++;	
	}
	
}
//xoa phan tu o vi tri P trong ds
void deleteList(ElementType x, Position P, List *pL){
	if(P < firstList(*pL) || P > endList(*pL))
		printf("Vi tri khong hop le!");
	else if(emptyList(*pL))
		printf("Danh sach rong!");
	int i;
	for(i = P; i != endList(*pL); i++)
		pL->Elements[i-1] = pL->Elements[i];
	pL->Last++;
}
//tim vi tri x xuat hien dau tien trong ds
Position locate(ElementType x, List L){
	Position P;
	for(P = 1; P != L.last+1; P++){
		if(L.Elements[P-1] == x){
			return P;
			break;
		}
	}
	return L.Last+1;
}

//nhap danh sach
void readList(List *pL){
	makenullList(pL);
	int n;
	scanf("%d", &n);
	ElementType x;
	while(n--){
		scanf("%d", &x);
		insertList(x, endList(*pL), pL);
	}
}
//in ds
void printList(List L){
	Position P;
	for(P = 1; P != L.Last+1; P++)
		printf("%d ", L.Elements[P-1]);
	
}
//tap hop hop  - hieu
void unionSet(List L1, List L2, List *pL){
	makenullList(pL);
	Position P, Q;
	for(P = 1; P != L1.Last+1; P++)
		insertSet(L1.Elements[P-1], pL);
	for(Q = 1; Q != L2.Last+1; Q++){
		if(!member(L2.Elements[Q-1], *pL))
			insertSet(L2.Elements[Q-1], pL);
	}
}
//nhap ds
void readSet(List *pL){
	makenullList(pL);
	int n;
	scanf("%d", &n);
	ElementType x;
	while(n--){
		scanf("%d", &x);
		insertSet(x, pL);
	}
}
//xoa tat ca cac phan tu x trong ds
void removeAll(ElementType x, List *pL){
    while(locate(x, *pL) != endList(*pL))
        deleteList(locate(x, *pL), pL);
}
//tap hop giao cua 2 ds
void intersection(List L1, List L2, List *pL){
	makenullList(pL);
	Position P = 1;
	while(P != endList(L1)){
		if(member(retrieve(P, L1), L2))
			insertList(retrieve(P, L1), endList(*pL), pL);
		P++;
	}
}
