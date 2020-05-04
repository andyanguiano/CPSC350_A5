NaiveList::NaiveList(){
  size = 0;
  front = NULL:
}

NaiveList::~NaiveList(){

}

unsigned int NaiveList::getSize(){
  return size;
}

bool NaiveList::isEmpty(){
  return (size == 0);
}

void NaiveList::printList(){
  ListNode *current = front;

  while(current != NULL){
    cout << current->data << endl;
    current = current->next;//listnode
  }

}

void NaiveList::insertFront(int d){
  ListNode *node = new ListNode(d);
  node->next = front;
  front = node;
  size++;
}

int NaiveList::removeFront(){
  //check if isEmpty
  int temp = front->data;
  ListNode *ft = front;
  front = front->next;
  ft->next = NULL;
  delete ft;
  size--;

  return temp;
}

int NaiveList::search(int val){
  int pos = -1
  ListNode *curr = front;
  //loop and attempt to find the value
  while(curr != NULL){
    ++pos;
    if(curr->data == val){
      //we found it
      break;
    }else{
      //we didnt continue iterating
      curr = curr->next;
    }

    if(curr == NULL){
      //didnt find it
      pos = -1
    }
    return pos;
  }
}

int NaiveList::removeAtPos(int pos){
  //error to make sure pos does not exceed size of listnode
  int idx = 0;

  ListNode *curr;
  ListNode *prev = front;

  while(idx != pos){
    //loop until I find the position
    prev = curr;
    curr = cur->next;
    idx++
  }

  //continue with the delete process
  prev->next = curr->next;
  curr->next = NULL;
  int temp = curr->data;
  delete curr;
  size--;

  return temp;
}
