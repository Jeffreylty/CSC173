int print_CSG(CSGLIST csg);
int print_CSG(CSGLIST csg){
	printf("(%s, %d, %s)",csg->Courses, csg->StudentId, csg->Grade);
	return 1;
}
