#include "so_long.h"

void	free_sprites(t_img *img, void *mlx_connection)
{
    if (img->img_path)
        mlx_destroy_image(mlx_connection, img->img_path);
    if (img->img_wall)
        mlx_destroy_image(mlx_connection, img->img_wall);
    if (img->img_player)
        mlx_destroy_image(mlx_connection, img->img_player);
    if (img->img_item)
        mlx_destroy_image(mlx_connection, img->img_item);
    if (img->img_exit)
        mlx_destroy_image(mlx_connection, img->img_exit);
}

int     ftff_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

int     nl_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i] && str[i] != '\n')
        i++;
    return (i);
}

void	ft_error(int n)
{
	if (n == 1)
        ft_printf("Error\nMap not surrounded by walls\n");
    if (n == 2)
        ft_printf("Number of Exit invalid (must be 1)\n");
    if (n == 3)
        ft_printf("Number of Player invalid (must be 1)\n");
    if (n == 4)
        ft_printf("Number of Items invalid (must be at least 1)\n");
    if (n == 5)
        ft_printf("Error\nCertain Elements are inaccessible\n");
    if (n == 6)
        ft_printf("Error\nMap is not a rectangular\n");
	
    exit(1);
}
