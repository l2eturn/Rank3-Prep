//#include "mlx.h"
//#include <stdlib.h>

//int main(void)
//{
//    void *mlx;
//    void *win;

//    mlx = mlx_init();                              // เริ่ม MiniLibX
//    if (!mlx)
//        return (1);

//    win = mlx_new_window(mlx, 640, 480, "Test MLX"); // สร้างหน้าต่าง
//    if (!win)
//        return (1);

//    mlx_loop(mlx);  // เริ่ม event loop
//    return (0);
//}

#include "mlx.h"
#include <stdlib.h>

int main(void)
{
    void    *mlx;
    void    *win;
    void    *player;
    int     img_width;
    int     img_height;

    mlx = mlx_init();
    if (!mlx)
        return (1);

    win = mlx_new_window(mlx, 640, 480, "Test MLX");
    if (!win)
        return (1);

    player = mlx_xpm_file_to_image(mlx, "Idle.xpm", &img_width , &img_height);
    if (!player)
        return (1);

    mlx_put_image_to_window(mlx, win, player, 100, 100);

    mlx_loop(mlx);
    return (0);
}
