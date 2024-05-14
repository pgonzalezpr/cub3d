# include "cub3d.h"

void    rotate_player(t_cub *cub, int code)
{
    if (cub || code)
        return ;
}

void    move_player(t_cub *cub, double x_delta, double y_delta)
{
    if (cub || x_delta || y_delta)
        return ;
}

void    get_deltas(t_cub *cub, int code, double *x_delta, double *y_delta)
{
    if (cub || code || x_delta || y_delta)
        return ;
}

void    hook_cub(t_cub *cub)
{
    double x_delta;
    double y_delta;

    x_delta = 0;
    y_delta = 0;
    if (cub->player->moves.rot_right)
        rotate_player(cub, ROT_RIGHT_CODE);
    if (cub->player->moves.rot_left)
        rotate_player(cub, ROT_LEFT_CODE); 
    if (cub->player->moves.forw)
        get_deltas(cub, MOV_FORW_CODE, &x_delta, &y_delta);
    if (cub->player->moves.backw)
        get_deltas(cub, MOV_BACKW_CODE, &x_delta, &y_delta);
    if (cub->player->moves.left)
        get_deltas(cub, MOV_LEFT_CODE, &x_delta, &y_delta);
    if (cub->player->moves.right)
        get_deltas(cub, MOV_RIGHT_CODE, &x_delta, &y_delta);
    if (x_delta || y_delta)
        move_player(cub, x_delta, y_delta);
}