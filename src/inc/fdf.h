/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:25:51 by antoda-s          #+#    #+#             */
/*   Updated: 2023/08/30 14:07:46 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* ************************************************************************** */
///	LIBS
/* ************************************************************************** */
# include <signal.h>
# include <sys/types.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "../../libft/libft.h"
# include "../../libft/gnl.h"
# include "../../libft/gnl.h"

/* ************************************************************************** */
///	DEBUG
/* ************************************************************************** */
# ifndef _PRINT
#  define _PRINT 1
#  define _NOPRINT 0
# endif
# ifndef _SHOW_STACKS_
#  define _SHOW_STACKS_ 1
# endif
# ifndef _SHORT_SIZE_
#  define _SHORT_SIZE_ 5
# endif
# ifndef _DEBUG_
#  define _DEBUG_ 0
# endif
# ifndef _DEBUG_MALLOC_
#  define _DEBUG_MALLOC_ 0
# endif
# ifndef _CHUNK_
#  define _CHUNK_ 100
# endif
/* ************************************************************************** */
///	CONSTANTS
/* ************************************************************************** */
# ifndef ERROR
#  define ERROR 1
# endif
# ifndef SUCCESS
#  define SUCCESS 0
# endif
# ifndef TRUE
#  define TRUE 1
# endif
# ifndef FALSE
#  define FALSE 0
# endif
# define SX 'S'
# define PX 'P'
# define RX 'F'
# define RRX 'R'
# define HOLD 0
# define RANGE 2

/* ************************************************************************** */
///	COLORS
/* ************************************************************************** */
# define RED "\033[0;31m"
# define GRN "\033[0;32m"
# define YLW "\033[0;33m"
# define BLU "\033[0;34m"
# define PPL "\033[0;35m"
# define CYN "\033[1;36m"
# define WTH "\033[0m"
# define BOLD "\033[1;1m"
/* ************************************************************************** */
///	STRUCTS
/* ************************************************************************** */

typedef struct s_elem
{
	int				data;
	int				i;
	int				cost_a;
	int				cost_b;
	char			move_a;
	char			move_b;
	struct s_elem	*n;
	struct s_elem	*p;
}					t_elem;

typedef struct s_stack
{
	struct s_elem	*ta;
	int				size_a;
	int				min_a;
	int				max_a;
	struct s_elem	*tb;
	int				size_b;
	int				min_b;
	int				max_b;
	int				chunk;
}					t_stack;

typedef struct s_flags
{
	int				show_stacks;
	int				show_moves;
	int				show_colors;
	int				save_moves;
	int				fd;
	int				any_flag;
	int				len;
	char			**arg;
}					t_flags;

/* ************************************************************************** */
///	FUNCTIONS PROTOTYPES
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*	COMMON FUNCTIONS PROTOTYPES                                               */
/*                                                                            */
/* ************************************************************************** */
///	FILE ; fc_action_px.c
/* ************************************************************************** */
void	action_px_dst(t_elem **top_src, t_elem **top_dst);
void	action_px_source(t_elem **top_src);
void	action_px_stack(t_elem **top_src, t_elem **top_dst);
int		action_px(t_stack *h, char stack, int print);
/* ************************************************************************** */
///	FILE ; fc_action_rx.c
/* ************************************************************************** */
int		action_rr(t_stack *h, int print);
int		action_rrr(t_stack *h, int print);
int		action_rrx(t_stack *h, char stack, int print);
int		action_rx(t_stack *h, char stack, int print);
/* ************************************************************************** */
///	FILE ; fc_action_sx.c
/* ************************************************************************** */
int		action_ss(t_stack *h, int print);
int		action_sx(t_stack *h, char stack, int print);
void	action_sx_stack(t_elem **swap_top);
/* ************************************************************************** */
///	FILE ; fc_args_build.c
/* ************************************************************************** */
int		args_build(t_flags *f);
int		ft_args_array(t_flags *f, int splits, int size, char **array);
int		flags_detector(t_flags *f);
int		flags_parser(t_flags *f);
int		ft_flags_error(t_flags *f, int i);
/* ************************************************************************** */
///	FILE ; fc_args_check.c
/* ************************************************************************** */
int		args_check_isvalid(int len, char **array);
int		args_check_isint(int len, char **array);
int		args_check_norepeat(int len, char **array);
int		args_check_novoid(int len, char **array);
int		args_check(int len, char **array);
/* ************************************************************************** */
///	FILE ; fc_extra_tools.c
/* ************************************************************************** */
void	extra_browse_stack_print(t_elem *t, t_elem *b, char stack, char *color);
void	extra_browse_stack(t_stack *h, t_flags *f, char stack);
void	extra_browse_stacks(t_stack *h, t_flags *f);
void	extra_moves_show(t_flags *f, char *move);
/* ************************************************************************** */
///	FILE ; fc_free.c
/* ************************************************************************** */
void	ft_stack_free_a(t_stack *h);
void	ft_stack_free_b(t_stack *h);
void	ft_stack_free_x(t_stack *h);
void	ft_stack_free_f(t_flags *f);
void	ft_free_structs(t_stack *h, t_flags *f);
/* ************************************************************************** */
///	FILE ; fc_sort_check.c
/* ************************************************************************** */
int		sort_check(t_stack *h);
/* ************************************************************************** */
///	FILE ; fc_stack_init.c
/* ************************************************************************** */
t_stack	*ft_stack_init(int size, char **array);
t_elem	*ft_stack_add_first(t_stack *h, int data);
t_elem	*ft_stack_add_next(t_elem *stack, int data);
void	ft_stack_init_status(t_stack *h);
t_flags	*flags_init(int ac, char **av);
/* ************************************************************************** */
///	FILE ; fc_stack_limits.c
/* ************************************************************************** */
void	ft_stack_limits_updt(t_elem *node, int *max, int *min);
void	ft_stack_limits_chk(t_stack *h, char stack);
/* ************************************************************************** */
///	FILE ; fc_utils.c
/* ************************************************************************** */
int		ft_error(void);
char	*ps_gnl(void);
/* ************************************************************************** */
///	FILE ; fm_cost_action.c
/* ************************************************************************** */
int		cost_raw(t_stack *h, t_elem *node);
int		cost_rr(t_elem *node);
int		cost_rrr(t_stack *h, t_elem *node);
int		cost_to_pa(t_stack *h, t_elem *node);
int		cost_to_pb(t_stack *h, t_elem *node);
/* ************************************************************************** */
///	FILE ; fm_cost_analytics.c
/* ************************************************************************** */
int		cost_source(t_stack *h, char stack_src);
int		cost_dest(t_stack *h, char stack_src);
int		cost_eval(t_stack *h, char stack_src);
t_elem	*cost_best(t_elem *cur, int size, char stack_src);
t_elem	*cost_get(t_stack *h, char stack_src);
/* ************************************************************************** */
///	FILE ; fm_cost_optimizer.c
/* ************************************************************************** */
int		cost_optimizer(t_stack *h, t_elem *node);
int		cost_min(t_elem *cur);
int		ft_max_int(int a, int b);
int		ft_min_int(int a, int b);
/* ************************************************************************** */
///	FILE ; fm_move.c
/* ************************************************************************** */
void	move_both(t_stack *h, t_elem *best);
void	move_single(t_stack *h, t_elem *best);
void	move_to_top(t_stack *h, t_elem *best);
/* ************************************************************************** */
///	FILE ; fm_sort_3.c
/* ************************************************************************** */
void	sort_3_x(t_stack *h, char stack);
void	sort_3_a(t_stack *h);
void	sort_3_b(t_stack *h);
/* ************************************************************************** */
///	FILE ; fm_sort_chunk.c
/* ************************************************************************** */
void	sort_chunk_index_a(t_stack *h, int j, int k);
void	sort_chunk_index_2b2(t_stack *h, const int lowest);
int		sort_chunk_index_2b1(t_stack *h, int j, const int i, int lowest);
void	sort_chunk_index_2b(t_stack *h, t_flags *f);
void	sort_chunk(t_stack *h, t_flags *f);
/* ************************************************************************** */
///	FILE ; fm_sort_cost.c
/* ************************************************************************** */
void	sort_cost(t_stack *h);
void	sort_final(t_stack *h);
void	sort_to_x(t_stack *h, char stack);
void	ft_stack_b_start(t_stack *h);
/* ************************************************************************** */
///	FILE ; fb_push_swap.c
/* ************************************************************************** */
int		main(int ac, char **av);
/* ************************************************************************** */
///	FILE ; fb_checker.c
/* ************************************************************************** */
int		main(int ac, char **av);
int		checker_machine(t_stack *h, t_flags *f);
int		checker_get_move(t_stack *h, t_flags *f);
int		checker_mover(t_stack *h, char *m);
int		checker_result(int result, int fcolor);
#endif