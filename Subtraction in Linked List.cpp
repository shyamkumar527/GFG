//POTD - 4/2/24
int count(Node* head){
    int c=0;
    while(head){
        c++;
        head=head->next;
    }
    return c;
}
Node* rev(Node* head){
    Node *nn=NULL,*n1;
    while(head!=NULL){
        n1=head->next;
        head->next=nn;
        nn=head;
        head=n1;
    }
    return nn;
}
Node* remzero(Node* head){
    while(head){
        if(head->data==0) head=head->next;
        else return head;
    }
    return head;
}
void print(Node *head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<"\n";
}
Node* subLinkedList(Node* head1, Node* head2) {
    head1=remzero(head1);
    head2=remzero(head2);
    if(head1==NULL and head2==NULL){
        Node *nn=new Node(0);
        return nn;
    }
    if(head1==NULL) return head2;
    if(head2==NULL) return head1;
    int c1=count(head1), c2=count(head2),br=0;
    Node *fir,*sec,*t1=head1,*t2=head2,*h1,*h2;
    if(c2>c1){
        swap(head1,head2);
    }
    else if(c1==c2){
        int c=1;
        while(t1){
            if(t1->data>t2->data){
                c=0;
                break;
            }
            else if(t2->data>t1->data){
                swap(head1,head2);
                c=0;
                break;
            }
            t1=t1->next;
            t2=t2->next;
        }
        if(c==1){
            Node *nn=new Node(0);
            return nn;
        }
    }
    head1=rev(head1);
    head2=rev(head2);
    fir=head1;
    sec=head2;
    while(sec){
        if(br==0){
            if(fir->data>=sec->data) fir->data=(fir->data - sec->data);
            else{
                br=1;
                fir->data=(fir->data+10) - sec->data;
            }
        }
        else{
            if(fir->data>sec->data){
                fir->data=((fir->data-1) - sec->data);
                br=0;
            }
            else fir->data=(fir->data+9) - sec->data;
        }
        fir=fir->next;
        sec=sec->next;
    }
    while(fir){
        if(br==1){
            if(fir->data>0){
                fir->data=fir->data-1;
                br=0;
            }
            else fir->data=9;
        }
        fir=fir->next;
    }
    head1=rev(head1);
    head1=remzero(head1);
    return head1;
}
