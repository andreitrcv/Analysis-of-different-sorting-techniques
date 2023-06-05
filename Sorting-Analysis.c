#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

   typedef enum {IS , MS, HS, QS, RS, M3QS, TRQS, OPTRQS} alg; //choose an algorithm
    
    void CopyFromL(int* i, int array[], int L[], int k);
    void CopyFromR(int* j, int array[], int R[], int k);
    int MedianOfThreePartition(int array[], int p, int r);
    void OptimalTailQuickSort(int array[], int p, int r);
    void Merge(int array[], int p, int q, int r);
    void MergeSort(int array[], int p, int r);
    void AdaptedInsertionSort(int array[], int p, int r);
    void HybridSort(int array[], int p, int r);
    void GenerateRandomArray(int array[], int length);
    void RemixingArray(int array[], int length);
    void InsertionSort(int array[], int length);
    float SingleExperiment(int length, int max_instances, alg option);
    int Experiment(int min_length, int max_length);
    int Partition(int array[], int p, int r);


    int main(){
        Experiment(10, 1000);
        return 1;
    }


    void CopyFromL(int* i, int array[], int L[], int k){
        array[k] = L[*i];
        *i = *i + 1;
    }

    void CopyFromR(int* j, int array[], int R[], int k){
        array[k] = R[*j];
        *j = *j + 1;
    }
    
    void OptimalTailQuickSort(int array[], int p, int r){
    // - eliminazione tail ricorsione
    // - ottimizzazione chiamata ricorsiva
    // - pivot pseudo-ottimale(mediana di tre)
    // - caso base per array < 93 (con InsertionSort)
        int k = 0;
        int q = 0;
        while(p < r){
            if(r - p + 1 > 93){
                q = MedianOfThreePartition(array, p, r);
                if(q < ((p+r)/2)){ // mi voglio richiamare sulla porzione più piccola
                    OptimalTailQuickSort(array, p, q - 1);
                    p = q + 1;
                }
                else{
                    OptimalTailQuickSort(array, q + 1, r);
                    r = q - 1;
                }
            }
            else{
                AdaptedInsertionSort(array, p, r);
                return; //l'array ha meno di 93 elementi, quindi una volta ordinato ho finito
            }
        } 
    }

    void TailQuickSort(int array[], int p, int r){
        int q = 0;
        while(p<r){
            q = Partition(array, p, r);
            TailQuickSort(array, p, q - 1);
            p = q + 1;
        }
    }//con questa versione non c'è garanzia che lo stack si occupi O(n) nel caso peggiore


    int MedianOfThree(int array[], int i, int j, int k){

        if (array[i] > array[j]){
            if(array[j] >= array[k])
                return j;
            else if (array[i] < array[k])
                return i;
            else
                return k;
        }else{
            if(array[i] >= array[k])
                return i;
            else if (array[j] < array[k])
                return j;
            else return k;
        }
    }

    void SwapValue(int array[], int s, int r){
        int temp = array[s];
        array[s] = array[r];
        array[r] = temp;
    }

    int MedianOfThreePartition(int array[], int p, int r){
        int s = MedianOfThree(array, p, r, (p+r)/2);
        SwapValue(array, s, r);
        return Partition(array, p, r);
    }
    
    void MedianOfThreeQuickSort(int array[], int p, int r){
        int q;
        if (p < r){//aggiungi commenti
            q = MedianOfThreePartition(array, p, r);
            MedianOfThreeQuickSort(array, p, q - 1);
            MedianOfThreeQuickSort(array, q + 1, r);
        }
    }

    int Partition(int array[], int p, int r){
        int x = array[r];
        int i = p - 1;
        for (int j = p; j <= r-1; j++)
            if (array[j] <= x){
                i++;
                SwapValue(array, i, j);
            }
        SwapValue(array, i+1, r);
        return i+1;
    }

    void QuickSort(int array[], int p, int r){
        int q = 0;
        if (p < r){
            q = Partition(array, p, r);
            QuickSort(array, p, q - 1);
            QuickSort(array, q + 1, r);
        }
    }


    int RandomizedPartition(int array[], int p, int r){
        int s = (rand() % (r - p + 1)) + p;
        SwapValue(array, s, r);
        return Partition(array, p, r);

    }

    void RandomizedQuickSort(int array[], int p, int r){
        int q = 0;
        if (p < r){
            q = RandomizedPartition(array, p, r);
            RandomizedQuickSort(array, p, q - 1);
            RandomizedQuickSort(array, q + 1, r);
        }
    }

    void Merge(int array[], int p, int q, int r){
        int n1 = q - p + 1;
        int n2 = r-q;
        //int *L = (int*)malloc(n1 * sizeof(int));
        //int *R = (int*)malloc(n2 * sizeof(int));
        //if (L == NULL || R == NULL) {
          //  printf("Memoria non allocata.\n");
        //exit(0);
    //}
        int L[n1];// sullo stack
        int R[n2];// sullo stack
        //sarebbe meglio allocare con malloc affinchè lo stack non venga riempito in modo da provocare stack overflow per
        //array molto lunghi.
        int i;
        int j;
        int k;
        for (i = 0; i<n1; i++)
            L[i] = array[p + i];

        for (j = 0; j<n2; j++)
            R[j] = array [q + j + 1];

        i = 0;
        j = 0;
        for (k = p; k<=r; k++)
            if (i < n1)
                if (j < n2)
                    if (L[i] < R[j])
                        CopyFromL(&i, array, L, k);
                    else
                        CopyFromR(&j, array, R, k);
                else
                    CopyFromL(&i, array, L, k);
            else
                CopyFromR(&j, array, R, k);
        
        //free(L);
        //free(R);
                    
    }

    void MergeSort(int array[], int p, int r){
        int q;
        if (p<r){
            q = (p+r)/2;
            MergeSort(array, p, q);
            MergeSort(array, q+1, r);
            Merge (array, p, q, r);
        }
    }

    void AdaptedInsertionSort(int array[], int p, int r){
        int i, j;
        int key;
        for (j=p; j<r; j++){ 
            key = array[j];
            i = j - 1;
                while(i >= 0 && array[i]>key){
                    array[i+1] = array[i];
                    i = i - 1;
                }
            array[i+1] = key;
        }
    }

     void HybridSort(int array[], int p, int r){
        int q;
        if  (r - p + 1 > 185){ //dopo 185 elementi uso MergeSort
            q = (p+r)/2;
            MergeSort(array, p, q);
            MergeSort(array, q+1, r);
            Merge (array, p, q, r);
        }
        else
            AdaptedInsertionSort(array, p, r);
    }


    void GenerateRandomArray(int array[], int length){
        for (int i = 0; i<length; i++)
            array[i] = rand();
        }

    int isOrdered(int array[], int length){ //Antagonist Function 
        for (int i = 1; i<length; i++){
            if (array[i-1] > array[i])
                return 0; 
            }
            return 1;
    }


    void InsertionSort(int array[], int length){
        int i, j;
        int key;
        for (j=1; j<length; j++){
            key = array[j];
            i = j - 1;
                while(i >= 0 && array[i]>key){
                    array[i+1] = array[i];
                    i = i - 1;
                }
            array[i+1] = key;
        }
    }

    float SingleExperiment(int length, int max_instances, alg option){
        int t_tot = 0;
        long int t_start = 0;
        long int t_end = 0;
        long int t_elapsed = 0;
        int ordered;
        int A[length];
        for (int i = 1; i<=max_instances; i++){
            GenerateRandomArray(A, length);
            switch(option){
                case 0:
                    t_start = clock();
                    InsertionSort(A, length); 
                    t_end = clock();
                    break;
                case 1:
                    t_start = clock();
                    MergeSort(A, 0, length);
                    t_end = clock();
                    break;
                case 2:
                    t_start = clock();
                    HybridSort(A, 0, length); 
                    t_end = clock();
                    break;
                case 3:
                    ordered = isOrdered(A,length);
                    t_start = clock();
                    QuickSort(A, 0, length);
                    t_end = clock();
                    ordered = isOrdered(A, length);
                    break;
                case 4:
                    ordered = isOrdered(A, length);
                    t_start = clock();
                    RandomizedQuickSort(A, 0, length); 
                    t_end = clock();
                    ordered = isOrdered(A, length);
                    break;
                case 5:
                    ordered = isOrdered(A, length);
                    t_start = clock();
                    MedianOfThreeQuickSort(A, 0, length);
                    t_end = clock();
                    ordered = isOrdered(A, length);
                    break;
                case 6:
                    ordered = isOrdered(A, length);
                    t_start = clock();
                    TailQuickSort(A, 0, length);
                    t_end = clock();
                    ordered = isOrdered(A, length);
                    break;
                case 7:
                    ordered = isOrdered(A, length);
                    t_start = clock();
                    OptimalTailQuickSort(A, 0, length);
                    t_end = clock();
                    ordered = isOrdered(A, length);
                    break;
                default:
                    printf("Error\n");
                    break;
            }
            t_elapsed = (t_end - t_start);
            t_tot = t_tot + t_elapsed;
        }
        return (t_tot/max_instances);
    }

    int Experiment(int min_length, int max_length){
        char *filename = "test.txt";
        FILE *fp = fopen(filename, "w");
        if (fp == NULL)
        {
            printf("Error opening the file %s", filename);
            return -1;
        }
        int max_instances = 10;
        int step = 5;
        int length = 0;
        float timeIS = 0;
        float timeMS = 0;
        float timeQS = 0;
        float timeRS = 0;
        float timeHS = 0;
        float timeM3QS = 0;
        float timeTRQS = 0;
        float timeOPTRQS = 0;
        //int ordered;

        printf("\t      timeIS, timeMS,   timeHS, timeQS,   timeRS,  timeM3QS, timeTRQS, timeOPTRQS\n"); //terminal       


        for (length = min_length; length<=max_length; length = length + step){

            srand(13); //reset seed
            timeIS = SingleExperiment(length, max_instances, IS);

            srand(13);
            timeMS = SingleExperiment(length,max_instances, MS);
            
            srand(13);
            timeHS = SingleExperiment(length, max_instances, HS);
            
            srand(13);
            timeQS = SingleExperiment(length, max_instances, QS);

            srand(13);
            timeRS = SingleExperiment(length, max_instances, RS);

            srand(13);
            timeM3QS = SingleExperiment(length, max_instances, M3QS);

            srand(13);
            timeTRQS = SingleExperiment(length, max_instances, TRQS);

            srand(13);
            timeOPTRQS = SingleExperiment(length, max_instances, OPTRQS);


            fprintf(fp, "Length:%d : %f ",length, timeIS); //.txt
            fprintf(fp, "%f ", timeMS);
            fprintf(fp, "%f ", timeHS);
            fprintf(fp, "%f ", timeQS);
            fprintf(fp, "%f ", timeRS);
            fprintf(fp, "%f ", timeM3QS);
            fprintf(fp, "%f ", timeTRQS);
            fprintf(fp, "%f ", timeOPTRQS);
            fprintf(fp, "\n");
            printf("Length: %d : %f %f %f %f %f %f %f %f\n", length, timeIS, timeMS, timeHS, timeQS, timeRS, timeM3QS, timeTRQS, timeOPTRQS); //terminal       
        }
        fclose(fp);
        return 1;
    }