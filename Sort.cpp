void LLC::mergesort(Node *head){
	if(*head == NULL || head->next == NULL){
		return 0;
	}
	Node a = this->head;
	Node b = this->head->next;
	Node temp = this->head->next->next;
	bool switch = true;
	while(temp->next != NULL){ //This while loop alternates the nodes into two seperate LinkedLists
		if(switch){
			a->next = temp; //^^ said lists begin at the head, and second nodes of the LLC
			a = a->next;
		}else{
			b->next = temp;
			b = b-> next;
		}
		switch = !switch;
		temp = temp->next;
	}

	this->head = mergeCombine(mergesort(this->head), mergesort(this->head->next));
	temp = this->head;
	while(temp->next != NULL){
		temp= temp->next;
	}
	this->tail = temp;
}	


Node* LLC::mergeCombine(Node* a, Node* b){
	Node* first = NULL;
	if(a==NULL){
		return b;
	} else if (b==NULL){
		return a;
	}

	if(a.getRand() <= b.getRand()){
		first = a;
		first->next = mergeCombine(a->next, b);
	} else {
		first = b;
		first->next = mergeCombine(a, b->next);
	}
	return first;
}

