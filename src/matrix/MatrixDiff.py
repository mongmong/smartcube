#!/usr/bin/env python

'''
Compare two matrices.

Usage: xmatrix.diff -- -g <group> -p <precision> <lambda> [<lambda> ...]

-g|--group=<group>            specify the number of group columns. [default: 1]
-p|--precision=<precision>    specify precision. [default:2]
-a|--absolute                 display absolute contribution.
-r|--relative                 display relative contribution. [default]
<lambda>                      for example, be in following forms:
                                  1. full lambda:
                                        lambda x: x[0] + x[1]
                                  2. abbreviated lambda:
                                        x[0] + x[1]
'''
import getopt
import numpy as N

import smartcube

class MatrixDiff(smartcube.Routine):
    def __init__(self, config, args):
        super(MatrixDiff, self).__init__()

        opts, args = getopt.getopt(args, "g:p:art", ["group=", "precision=", "relative", "absolute", "total"])
        opts = dict(opts)

        self.groupby = 1
        if opts.has_key('-g'):
            self.groupby = int(opts['-g'])
        if opts.has_key('--group'):
            self.groupby = int(opts['--group'])

        self.precision = 2
        if opts.has_key('-p'):
            self.precision = int(opts['-p'])
        if opts.has_key('--precision'):
            self.precision = int(opts['--precision'])

        self.relative = True
        if opts.has_key('--absolute') or opts.has_key('-a'):
            self.relative = False

        self.lambdas = []
        for i in args:
            if i.startswith('lambda'):
                self.lambdas.append(eval(i))
            else:
                self.lambdas.append(eval('lambda x: %s' % i))

        #print opts, args

    def handle(self, input, output):
        old = input.get_inputs()[0]
        new = input.get_inputs()[1]

        keys = set()
        mapold = {}
        mapnew = {}
        sumold = []
        sumnew = []

        # read old matrix
        l = old.pop()
        while l:
            key = '\t'.join(l[:self.groupby])
            values = l[self.groupby:]
            keys.add(key)
            for f in self.lambdas:
                values.append(f(values))
            mapold[key] = N.array(values, dtype = float)

            l = old.pop()

        #output.push(sumoldex)

        # read new matrix
        l = new.pop()
        while l:
            key = '\t'.join(l[:self.groupby])
            values = l[self.groupby:]
            keys.add(key)
            for f in self.lambdas:
                values.append(f(values))
            mapnew[key] = values

            l = new.pop()

        #totaldiff = (sumnewex - sumoldex) / sumoldex

        #if self.total:
        #    output.push(['-'] * self.groupby + list(N.round(totaldiff * 100, self.precision)))

        for key in keys:
            recold = []
            if mapold.has_key(key):
                recold = mapold[key]
            recnew = []
            if mapnew.has_key(key):
                recnew = mapnew[key]

            if not len(recold):
                recold = N.array([0.0] * len(recnew), dtype = float)
                recnew = N.array(recnew, dtype = float)
            elif not len(recnew):
                recold = N.array(recold, dtype = float)
                recnew = N.array([0.0] * len(recold), dtype = float)
            else:
                recold = N.array(recold, dtype = float)
                recnew = N.array(recnew, dtype = float)

            if self.relative:
                diff = (recnew - recold) / recold * 100
            else:
                diff = recnew - recold
            output.push(key.split('\t') + list(N.round(diff, self.precision)))



__routine__ = MatrixDiff
