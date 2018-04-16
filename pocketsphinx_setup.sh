# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    pocketsphinx_setup.sh                              :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rzarate <rzarate@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/13 15:29:53 by rzarate           #+#    #+#              #
#    Updated: 2018/04/13 15:34:25 by rzarate          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### INSTALL POCKETSPHINX

brew tap watsonbox/cmu-sphinx
brew install --HEAD watsonbox/cmu-sphinx/cmu-sphinxbase
brew install --HEAD watsonbox/cmu-sphinx/cmu-pocketsphinx_setup

### EXPORT SPHINX TO ENV VARIABLIES

export PATH="$HOME/.brew/bin:$PATH"