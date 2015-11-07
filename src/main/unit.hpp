/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-norm <dle-norm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 13:35:27 by dle-norm          #+#    #+#             */
/*   Updated: 2015/11/07 13:35:39 by dle-norm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIT_HPP
#define UNIT_HPP

class Unit
 {
 public:
 	Unit();
 	Unit(int x, int y, char c);
 	Unit( Unit const & str);
 	~Unit();
 	
 	Unit & operator=(Unit const & rhs);
 	char** right(char **tab);
 	char** left(char **tab);
 	char** up(char **tab);
 	char** down(char **tab);

 	int getX(void)const;
 	int getY(void)const;
 	char getC(void)const;
 protected:
 	int _x;
 	int _y;
 	char _type;
 };

#endif
