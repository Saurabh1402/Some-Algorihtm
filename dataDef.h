struct BTNodeInt{
	int data;
	struct BTNodeInt *left;
	struct BTNodeInt *right;
};

struct DynQueueBTNode{
	struct BTNodeInt **array;
	int capacity;
	int front,rear;
};
