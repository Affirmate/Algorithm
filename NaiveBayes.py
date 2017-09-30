import csv
import random
import math

#File Handling
def loadCsv(filename):
    lines = csv.reader(open(filename, "rb"))
    dataset = list(lines)
    for i in range(len(dataset)):
        dataset[i] = [float(x) for x in dataset[i]]
    return dataset


#Splitting data into 67% training and 33% test ratio
def splitDataset(dataset, splitRatio):
    trainSize = int(len(dataset) * splitRatio)
    trainSet = []
    copy = list(dataset)
    while len(trainSet) < trainSize:
        index = random.randrange(len(copy))
        trainSet.append(copy.pop(index))
    return [trainSet, copy]

'''
The Naive Bayes model consists of a summary of data in the training set, which is then used to make predictions.
The summary involves the mean and standard deviation for each attribute, by class value.
These are required when making predictions to calculate probability of specific attribute values belonging to each class value.
Sub-tasks:
    1. Separate data by class
    2. Calculate mean
    3. Calculate standard deviation
    4. Summarize dataset
    5. Summarize attributes by class
'''

#Separating data by class
'''
The fuction assumes that the last attribute (-1) is the class value.
It returns a map of class values to lists of data instances.
'''
def separateByClass(dataset):
	separated = {}
	for i in range(len(dataset)):
		vector = dataset[i]
		if (vector[-1] not in separated):
			separated[vector[-1]] = []
		separated[vector[-1]].append(vector)
	return separated

#Calculating mean and standard deviation
def mean(numbers):
    return sum(numbers)/float(len(numbers))

def stdev(numbers):
    avg = mean(numbers)
    variance = sum([pow(x-avg, 2) for x in numbers])/float(len(numbers)-1)
    return math.sqrt(variance)

#Summarizing dataset
def summarize(dataset):
	summaries = [(mean(attribute), stdev(attribute)) for attribute in zip(*dataset)]
	del summaries[-1]
	return summaries
'''
The zip fuction groups the values for each attribute across the data instances into their own lists
so that mean and standard deviation can be computed for the attribute
'''

#Summarizing attributes by class
def summarizeByClass(dataset):
	separated = separateByClass(dataset)
	summaries = {}
	for classValue, instances in separated.iteritems():
		summaries[classValue] = summarize(instances)
	return summaries

'''
Making predictions
This involves calculating the probability that a given data instance belongs to each class, then selecting the class with the largest probability as the prediction
Sub-tasks:
    1. Calculate Gaussian probability density function
    2. Calculate class probabilities
    3. Make a prediction
    4. Estimate accuracy
'''

#Calculating probability
def calculateProbability(x, mean, stdev):
    exponent = math.exp(-(math.pow(x-mean, 2)/(2 * math.pow(stdev,2))))
    return (1/(math.sqrt(2 * math.pi) * stdev)) * exponent


#Calculating class probabilities
def calculateClassProbabilities(summaries, inputVector):
    probabilities = {}
    for classValue, classSummaries in summaries.iteritems():
        probabilities[classValue] = 1
        for i in range(len(classSummaries)):
            mean, stdev = classSummaries[i]
            x = inputVector[i]
            probabilities[classValue] *= calculateProbability(x, mean, stdev)   #We combine probabilities by multiplying them
    return probabilities

#Making a prediction
def predict(summaries, inputVector):
    probabilities = calculateClassProbabilities(summaries, inputVector)
    bestLabel, bestProb = None, -1
    for classValue, probability in probabilities.iteritems():
        if bestLabel is None or probability > bestProb:
            bestProb = probability
            bestLabel = classValue
    return bestLabel

#Estimating accuracy of model by making predictions for each data instance in test dataset
def getPredictions(summaries, testSet):
    predictions = []
    for i in range(len(testSet)):
        result = predict(summaries, testSet[i])
        predictions.append(result)
    return predictions

'''
Accuracy
The predictions can be compared to the class values in the test dataset and a classification accuracy can be calculated as a ratio between 0 and 100%
'''
def getAccuracy(testSet, predictions):
    correct = 0
    for x in range(len(testSet)):
        if testSet[x][-1] == predictions[x]:
            correct += 1
    return (correct/float(len(testSet))) * 100.0

#Main
def main():
    filename = 'diabetes.data.csv'
    splitRatio = 0.67
    dataset = loadCsv(filename)
    trainingSet, testSet = splitDataset(dataset, splitRatio)
    print('Split {0} rows into train={1} and test={2} rows').format(len(dataset), len(trainingSet), len(testSet))
    #Prepare model
    summaries = summarizeByClass(trainingSet)
    #Test model
    predictions = getPredictions(summaries, testSet)
    accuracy = getAccuracy(testSet, predictions)
    print('Accuracy: {0}%').format(accuracy)

main()
