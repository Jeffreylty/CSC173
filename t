int print_CSG(CSGLIST csg);
int print_CSG(CSGLIST csg){
	if (csg != NULL){
		printf("(%s, %d, %s) ", csg->Courses, csg->StudentId, csg->Grade);
	}
	return 1;
}

int print_CSGTable(CSGHASHTABLE csgt);
int print_CSGTable(CSGHASHTABLE csgt){
	for(int i = 0; i < 1009; i++){
		if (csgt[i] != NULL){
			print_CSG(csgt[i]);
		}
	}
	printf("\n");
	return 1;
}
