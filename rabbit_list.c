#include"rabbit_list.h"


//créer une nouvelle liste
list_rabbit_t new_list(void)
{
	return NULL;
}


//renvoie le premier lapin de la liste
rabbit_t head(list_rabbit_t list_rabbit)
{
	if(list_rabbit == NULL)
	{
		printf("op interdite\n");
		exit(1);
	}
	return list_rabbit->rabbit;
}


//renvoie true si la liste est vide
Boolean empty(list_rabbit_t list_rabbit)
{
	if(list_rabbit == NULL)
		return true;
	return false;
}


//ajoute un lapin en debut de liste
list_rabbit_t add_head(list_rabbit_t list_rabbit, rabbit_t rabbit)
{
	link_t *link;
	link = (link_t*)malloc(sizeof(link_t));
	if(link == NULL)
	{
		printf("pb malloc\n");
		exit(1);
	}
	link->rabbit = rabbit;
	link->next = list_rabbit;
	return link;
}


//supprime le premier lapin de la liste
list_rabbit_t delete_head(list_rabbit_t list_rabbit)
{
	link_t *link;
	if(empty(list_rabbit))
	{
		printf("forbidden operation\n");
		exit(1);
	}
	link = list_rabbit;
	list_rabbit = list_rabbit->next;
	free(link);
	return list_rabbit;
}


//affiche le nombre d'elements d'une liste
int nb_element(list_rabbit_t list_rabbit)
{
	int cpt = 0;
	while(list_rabbit != NULL)
	{
		cpt = cpt + 1;
		list_rabbit = list_rabbit->next;
	}
	return cpt;
}


//affiche l'age et le sexe du lapin
void display_rabbit(rabbit_t rabbit)
{
    printf("nb month : %d\tsexe : %d\n", rabbit.nb_month, rabbit.sexe);
}


//affiche l'age et le sexe de chaque lapin de la liste
void display_list(list_rabbit_t list_rabbit)
{
	while(!empty(list_rabbit))
	{
		display_rabbit(list_rabbit->rabbit);
		list_rabbit = list_rabbit->next;
	}
}


//affiche la liste des lapins avec le booleen 'alive'
void display_death(list_rabbit_t list_rabbit)
{
	int i = 1;
    while(!empty(list_rabbit))
	{
		if(list_rabbit->rabbit.alive)
		{
			printf("rabbit %d : alive\n", i);
		}
		else
		{
			printf("rabbit %d : dead\n", i);
		}
		
		list_rabbit = list_rabbit->next;
		i++;
	}
}



