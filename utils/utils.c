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