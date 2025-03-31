 #include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

// tao node moi
node *makenode(int x) {
    node *newnode = new node();// cap phat dong cho no
    newnode->data = x;//mot cai node moi truy cap toi data thi gan bang x
    newnode->next = NULL;//con node moi tao truy cap toi next thi gan bang null
    return newnode;
}

// duyet danh sach lien ket
void duyet(node *head) {
    while (head != NULL) {
        cout << head->data << " ";// gia tri cua no 
        head = head->next;// dich sang node tiep theo trong dslk
    }
    cout << endl;
}

// dem so luong phan tu trong dslk 
int cnt(node *head) {
    int dem = 0;
    while (head != NULL) {//neu ma node dau tien no khong co rong (no co phan tu )
        dem++;
        head = head->next;// no tro toi node tiep theo
    }
    return dem;
}

// them phan tu vao dau danh sach 
void insertfirst(node *&head, int x) {
    node *newnode = makenode(x);// cap phat dong cho no vi no khong co san ptu nhu trong mang
    newnode->next = head;//node moi tro toi next gan cho bang node dau tien 
    head = newnode;// cap nhat lai node dau tien cho cai node moi
}

// them phan tu vao cuoi danh sach 
void insertlast(node *&head, int x) {
    node *newnode = makenode(x);// cap phat dong co node 
    if (head == NULL) {// neu node dau tien ma rong thi ta cap nhat thang la head la newnode luon
        head = newnode;// cap nhat head = newnode 
        return;
    }
    node *tmp = head;//tao them 1 node tam nhu la kieu thay the cho head
    while (tmp->next != NULL) {//neu ma tam(head) ma truy cap toi next ko phai la rong 
        tmp = tmp->next;//thi minh gan cai temp = temp truy cap toi next 
    }
    tmp->next = newnode;//sau do thi minh cap nhat tmp truy cap toi newnode 
}

// them phan tu vao giua dslk 
void insertmidle(node *&head, int k, int x) {
    int n = cnt(head);//dem so luong phan tu trong node 
    if (k < 1 || k > n + 1) {//neu ma vi tri can chen nho hon 1 hoac vi tri can chen no lon hon cai so luong phan tu trong node
        cout << "Vi tri chen khong hop le!\n";
        return;
    }
    if (k == 1) { // neu chen vao vi tri dau tien 
        insertfirst(head, x);// goi lai cai ham dau tien va truyen vo
        return;
    }

    node *newnode = makenode(x);// cap phat dong cho no 
    node *tmp = head;//tiep tuc tao mot node tam thay the cho head
    for (int i = 1; i < k - 1; i++) {
        tmp = tmp->next;
    }
    newnode->next = tmp->next;
    tmp->next = newnode;
}
// xoa phan tu dau trong danh sach 
void popfirst(node *&head){
	if(head==NULL) return;
	node *tmp = head ;
	head = head ->next ;
	delete tmp ;
}
//xoa phan tu cuoi trong danh sach lien ket
void popback(node *&head){
	node *tmp = head ;
	if(head==NULL) return ;
	if(tmp->next ==NULL){
		head = NULL ; delete tmp ;
		return ;
	}
	while (tmp->next->next !=NULL){
		tmp = tmp->next ;
	}
	node *last = tmp->next ;
	tmp->next=NULL;
	delete last ;
}
void erase (node *&head , int k ){
	int n = cnt(head);
	if(k<1 || k>n) return ;
	if(k==1){
		popfirst(head );
	}
	else {
		node *tmp = head;
		for(int i = 1 ; i<=k-2 ; i++){
			tmp = tmp ->next ;
		}
		node *knode = tmp->next ;
		tmp->next = knode ->next ;
		delete knode ;
	}
}
int main() {
    node *head = NULL;
    while (1) {
        cout << "--------------------------------\n";
        cout << "1. Them vao dau danh sach\n";
        cout << "2. Them vao cuoi danh sach\n";
        cout << "3. Them vao giua danh sach\n";
        cout << "4. Xoa node dau tien trong danh sach\n ";
        cout << "5. Xoa giua trong danh sach\n";
        cout << "6. Xoa node cuoi trong danh sach\n ";
        cout << "7. Duyet danh sach\n";
        cout << "0. Thoat khoi chuong trinh\n";
        cout << "--------------------------------\n";
        int lc;
        cout << "Moi ban nhap lua chon: ";
        cin >> lc;

        if (lc == 1) {
            int x;
            cout << "Moi ban nhap so x: ";
            cin >> x;
            insertfirst(head, x);
        } 
        else if (lc == 2) {
            int x;
            cout << "Moi ban nhap so x: ";
            cin >> x;
            insertlast(head, x);
        } 
        else if (lc == 3) {
            int x, k;
            cout << "Moi ban nhap so x: ";
            cin >> x;
            cout << "Moi chon vi tri can chen: ";
            cin >> k;
            insertmidle(head, k, x);
        } 
        else if (lc==4){
        	popfirst(head);
        }
        else if(lc==5){
        	int k ;
        	cout<<" chon vi tri ban can xoa :\n";
        	cin>>k;
        	erase(head,k );
        }
        else if(lc==6){
        	popback(head);
        }
        else if (lc == 7) {
            cout << "Danh sach lien ket: ";
            duyet(head);
        } 
        else {
            break;
        }
    }
    return 0;
}

