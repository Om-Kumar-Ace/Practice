 Node*reverse(Node*head){
      
      if(head==NULL){
          return head;
      }
      
       Node*prev=NULL;
        Node*curr=head;
        Node*next;
        
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
           
        }
        return prev;
      
  }
    Node* addOne(Node* head) {
        // Your Code here
        // return head of list after adding one
        Node*curr=reverse(head);
        Node*temp=curr;
        int value=0;
        int carry=0;
         curr->data=curr->data+1;
        while(curr!=NULL){
            
              carry=(curr->data)/10;
             value=(curr->data)%10;
              curr->data=value;
                 if(carry!=0&&curr->next!=NULL){
                  curr=curr->next;
                 curr->data=curr->data+carry;
            }else if(carry!=0&&curr->next==NULL){
                Node*new_Node=new Node(carry);
                curr->next=new_Node;
                curr=new_Node;
                carry=0;
            }else{
                curr=curr->next;
            }

        }
        
        return reverse(temp);

    }