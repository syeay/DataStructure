#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct NODE {
	char szData[64];
	struct NODE* next;
}NODE;

NODE g_pHead = {0};

int IsEmpty() {
	if (g_pHead.next == NULL)
		return 1;
	return 0;
}

// 연결 리스트 전체 데이터 출력 함수
void PrintList() {
	NODE* pHead = &g_pHead;
	while (pHead != NULL) {
		printf("[%p] %s, next[%p]\n", pHead, pHead->szData, pHead->next);
		pHead = pHead->next;
	}

	putchar('\n');
}

int InsertAtHead(char* pszData) {
	NODE* pNode = (NODE*)malloc(sizeof(NODE));
	// 메모리 초기화
	memset(pNode, 0, sizeof(NODE));

	strcpy_s(pNode->szData, sizeof(pNode->szData), pszData);

	// 노드 추가
	if (IsEmpty())
		g_pHead.next = pNode;
	else {
		pNode->next = g_pHead.next;
		g_pHead.next = pNode;
	}
	return 1;
}

int InsertAtTail(char* pszData) {
	// 마지막 노드 찾기 (단일 연결리스트의 단점)
	NODE* pTmp = &g_pHead;
	while (pTmp->next != 0) {
		pTmp = pTmp->next;
	}
	
	// 추가할 노드 생성 및 초기화
	NODE* pNode = (NODE*)malloc(sizeof(NODE));
	memset(pNode, 0, sizeof(NODE));
	strcpy_s(pNode->szData, sizeof(pNode->szData), pszData);

	pTmp->next = pNode;
}

void ReleaseList() {
	NODE* pTmp = &g_pHead;
	while (pTmp != NULL) {
		NODE* pDelete = pTmp;
		pTmp = pTmp->next;
		printf("Delete: [%p] %s\n", pDelete, pDelete->szData);
		free(pDelete);
	}
}

int FindData(char* pszData) {
	NODE* pTmp = &g_pHead;
	while (pTmp != NULL) {
		if (strcmp(pTmp->szData, pszData) == 0)
			return 1;
		pTmp = pTmp->next;
	}
	return 0;
}

int DeleteData(char* pszData) {
	NODE* pTmp = &g_pHead;
	NODE* pPrev = NULL;
	while (pTmp != NULL) {
		if (strcmp(pTmp->szData, pszData) == 0) {
			printf("DeleteData(): %s\n", pTmp->szData);
			if (pPrev != NULL)
				pPrev->next = pTmp->next;
			else {
				g_pHead = *(pTmp->next);
			}
			free(pTmp);
			return 1;
		}
		pPrev = pTmp;
		pTmp = pTmp->next;
	}
	return 0;
}

int main() {
	// list 테스트를 위한 코드
	InsertAtHead("TEXT01");
	InsertAtHead("TEXT02");
	InsertAtHead("TEXT03");
	PrintList();

	if (FindData("TEXT01")==1)
		printf("FindData(): TEST01 found\n");
	if (FindData("TEXT02") == 1)
		printf("FindData(): TEST02 found\n");
	if (FindData("TEXT03") == 1)
		printf("FindData(): TEST03 found\n");

	DeleteData("TEXT01");
	DeleteData("TEXT02");
	DeleteData("TEXT03");

	puts("INPUTATTAIL()");

	InsertAtTail("TEXT01");
	InsertAtTail("TEXT02");
	InsertAtTail("TEXT03");
	PrintList();
	if (FindData("TEXT01") == 1)
		printf("FindData(): TEST01 found\n");
	if (FindData("TEXT02") == 1)
		printf("FindData(): TEST02 found\n");
	if (FindData("TEXT03") == 1)
		printf("FindData(): TEST03 found\n");

	DeleteData("TEXT01");
	DeleteData("TEXT02");
	DeleteData("TEXT03");

	//ReleaseList();

	return 0;
}

// 1. 전체 리스트 출력 함수 작성 (while문으로)
// 2. 새 노드 추가 함수 작성 (개발에 앞서 절차를 정확히 글로 기술!)
// 3. 전체 리스트 삭제 함수 작성
// 4. 각 함수를 작성할 때마다 main()에서 테스트 코드를 실행한다!



// 더미 헤드 없는 방식
//#include <stdio.h>
//#include <string.h>
//#include <malloc.h>
//
//typedef struct NODE {
//	char szData[64];
//	struct NODE* next;
//}NODE;
//
//NODE* g_pHead = NULL;
//
//// 연결 리스트 전체 데이터 출력 함수
//void PrintList() {
//	NODE* pHead = g_pHead;
//	while (pHead != NULL) {
//		printf("[%p] %s, next[%p]\n", pHead, pHead->szData, pHead->next);
//		pHead = pHead->next;
//	}
//
//	putchar('\n');
//}
//
//int InsertNewNode(char* pszData) {
//	NODE* pNode = (NODE*)malloc(sizeof(NODE));
//	// 메모리 초기화
//	memset(pNode, 0, sizeof(NODE));
//
//	strcpy_s(pNode->szData, sizeof(pNode->szData), pszData);
//
//	// 노드 추가
//	if (g_pHead == NULL)
//		g_pHead = pNode;
//	else {
//		pNode->next = g_pHead;
//		g_pHead = pNode;
//	}
//
//	return 1;
//}
//
//void ReleaseList() {
//	NODE* pTmp = g_pHead;
//	while (pTmp != NULL) {
//		NODE* pDelete = pTmp;
//		pTmp = pTmp->next;
//		printf("Delete: [%p] %s\n", pDelete, pDelete->szData);
//		free(pDelete);
//	}
//	g_pHead = NULL;
//}
//
//int FindData(char* pszData) {
//	NODE* pTmp = g_pHead;
//	while (pTmp != NULL) {
//		if (strcmp(pTmp->szData, pszData) == 0)
//			return 1;
//		pTmp = pTmp->next;
//	}
//	return 0;
//}
//
//int DeleteData(char* pszData) {
//	NODE* pTmp = g_pHead;
//	NODE* pPrev = NULL;
//	while (pTmp != NULL) {
//		if (strcmp(pTmp->szData, pszData) == 0) {
//			printf("DeleteData(): %s\n", pTmp->szData);
//			if (pPrev != NULL)
//				pPrev->next = pTmp->next;
//			else {
//				g_pHead = pTmp->next;
//			}
//			free(pTmp);
//			return 1;
//		}
//		pPrev = pTmp;
//		pTmp = pTmp->next;
//	}
//	return 0;
//}
//
//int main() {
//	// list 테스트를 위한 코드
//	InsertNewNode("TEXT01");
//	PrintList();
//	InsertNewNode("TEXT02");
//	PrintList();
//	InsertNewNode("TEXT03");
//	PrintList();
//
//	if (FindData("TEXT01")==1)
//		printf("FindData(): TEST01 found\n");
//	if (FindData("TEXT02") == 1)
//		printf("FindData(): TEST02 found\n");
//	if (FindData("TEXT03") == 1)
//		printf("FindData(): TEST03 found\n");
//
//	DeleteData("TEXT01");
//	DeleteData("TEXT02");
//	DeleteData("TEXT03");
//
//	ReleaseList();
//
//	return 0;
//}
